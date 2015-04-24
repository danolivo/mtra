#include <assert.h>
#include <tdma.h>

double P[CELLS_MAX_NUM], Q[CELLS_MAX_NUM];

void tdma(vector_t *Tr)
{
	P[0] = Bcv[0]/Acv[0];
	Q[0] = Dcv[0]/Acv[0];

	for (int i=1; i<=T->size()-1; i++) {
		P[i] = Bcv[i]/(Acv[i]-Ccv[i]*P[i-1]);
		Q[i] = (Dcv[i]+Ccv[i]*Q[i-1])/(Acv[i]-Ccv[i]*P[i-1]);
	}
	(*Tr)[T->size()-1] = Q[T->size()-1];
	for (int i=T->size()-2; i>=0; i--)
		(*Tr)[i] = P[i]*(*T)[i+1]+Q[i];
}
