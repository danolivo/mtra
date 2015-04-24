#include <assert.h>
#include <cmath>
#include <cv.h>
#include <tdma.h>

int last;
double Rstar = 1.e3;
int a1 = 0;

/* Алгоритм вычисления координаты точки */
static double y(int i, const vector_t* w) {
	if (i == 0)
		return 0;
	double sum = 0;
	for (int j=0; j<i; j++) {
		sum = sum + W[j];
	}
	if (i < w->size()-1)
		sum += W[i]/2.;
	else
		sum += W[i];
	return sum;
}

/* Алгоритм вычисления коэффициента Ламе */
static double H(double y) {
	if (a1 == 0)
		return 1.;
		
	return pow((Rstar+y)/Rstar, a1);
}

/* Алгоритм вычисления интеграла коэффициента Ламе */
static double CV_IntH(double y0, double y1) {
	assert(Rstar != 0);
	return (Rstar/(a1+1.))*(pow((Rstar+y1)/Rstar, a1+1.)-pow((Rstar+y0)/Rstar, a1+1.));
}

void CV_Pre(double thau)
{
	int last = T->size()-1;

	for (int i = 1; i<last; i++) {
		double ww;
		if (i == last-1)
			ww = W[i]/2.;
		else
			ww = W[i];
		double le = (ww*l[i]+W[i+1]*l[i+1])/(ww+W[i+1]);
		Bcv[i] = H(y(i,w)+W[i]/2.)*(le/(y(i+1,w)-y(i,w)));
		if (i == 1)
			ww = W[i]/2.;
		else
			ww = W[i];
		double lw = (ww*l[i]+W[i-1]*l[i-1])/(ww+W[i-1]);
		Ccv[i] = H(y(i,w)-W[i]/2.)*(lw/(y(i,w)-y(i-1,w)));
		Acv[i] = Bcv[i] + Ccv[i] + ((d[i]*c[i])/thau)*CV_IntH(y(i,w)-W[i]/2., y(i,w)+W[i]/2.);
		Dcv[i] = CV_IntH(y(i,w)-W[i]/2., y(i,w)+W[i]/2.)*(T[i]*(d[i]*c[i]/thau)-(*S)[i]);
	}
	double le = (W[0]*l[0]+W[1]*l[1]/2.)/(W[0]+W[1]/2.);
	Acv[0] = H(W[0])*le/(W[0]+W[1]/2.)+((d[0]*c[0])/thau)*CV_IntH(0., W[0]);
	Bcv[0] =H(W[0])*le/(W[0]+W[1]/2.);
	Ccv[0] = 0.;
	Dcv[0] = H(W[0])*(lbc->Qw()-eps_l*5.67*pow(T[0]/100., 4.)) + ((*S)[0]+ + ((d[0]*c[0])/thau)*T[0])*CV_IntH(0., W[0]);

	double lw = (W[last]*l[last]+W[last-1]*l[last-1]/2.)/(W[last]+W[last-1]/2.);
	Acv[last] = H(y(last, w)-W[last])*lw/(W[last]+W[last-1]/2.)+((d[last]*c[last])/thau)*CV_IntH(y(last,w)-W[last], y(last,w));
	Bcv[last] = 0.;
	Ccv[last] = H(y(last, w)-W[last])*lw/(W[last]+W[last-1]/2.);	
	Dcv[last] = (rbc->Qw()-rbc->Eps()*5.67*pow(T[last]/100., 4.))*H(y(last, w)) + (*S)[last]*CV_IntH(y(last,w)-W[last], y(last,w)) + ((d[last]*c[last])/thau)*T[last]*CV_IntH(y(last,w)-W[last], y(last,w));
}
void CV_Calc(vector_t *Tr)
{
	tdma(Tr);
}
