#ifndef _CARRAY_H_
#define _CARRAY_H_

#include <common.h>

template <class templ> class CArray {
	templ* data;
	int VALUES_MAX_NUM;
	int last;
public:
	CArray();
	~CArray();
	
	int size() const;
	void resize(int num);
	void push_back(templ val);
	
	templ &operator[](int num);
	const templ operator[](int num) const;
	CArray& operator=(const CArray& arr);
	const templ operator=(int num) const;
	double operator+(double a, templ b);
	
	void print() const;
};

template<class templ>CArray<templ>::CArray()
{
	this->VALUES_MAX_NUM = CELLS_MAX_NUM;
	data = new templ [VALUES_MAX_NUM];
	last = NULL_VALUE;
}

template<class templ>CArray<templ>::~CArray()
{
	delete [] data;
}
template<class templ> templ & CArray<templ>::operator[](int num)
{
	if (num > last) {
		printf("Array Index %d is out of order %d! MAX_NUM = %d\n", num, last, VALUES_MAX_NUM);
		return 0;
	} else
		return *this;
}

template<class templ> const templ CArray<templ>::operator[](int num) const
{
	if (num > last) {
		printf("Array Index %d is out of order %d! MAX_NUM = %d\n", num, last, VALUES_MAX_NUM);
		return -1;
	} else
		return data[num];
}
template<class templ> CArray<templ>& CArray<templ>::operator=(const CArray& arr)
{
	if (last == NULL_VALUE)
		data = new templ [VALUES_MAX_NUM];
	resize(arr.size());
	assert(VALUES_MAX_NUM > last);
	for (int i=0; i<=last; i++)
		data[i] = arr[i];
	return *this;
}
template<class templ> const templ CArray<templ>::operator=(int num) const
{
	if (num > last) {
		printf("Array Index %d is out of order %d! MAX_NUM = %d\n", num, last, VALUES_MAX_NUM);
		return -1;
	} else
		return data[num];
}
template<class templ> double CArray<templ>::operator+(double a, templ b)
{
	if (num > last) {
		printf("Array Index %d is out of order %d! MAX_NUM = %d\n", num, last, VALUES_MAX_NUM);
		return -1;
	} else
		return a+b;
}
template<class templ> int CArray<templ>::size() const
{
	return last+1;
}
template<class templ> void CArray<templ>::resize(int num)
{
	last = num-1;
	assert(last < VALUES_MAX_NUM);
	return;
}
template<class templ> void CArray<templ>::push_back(templ val)
{
	if (last < 0)
		last = 0;
	else
		last++;
	assert(last < VALUES_MAX_NUM);
	data[last] = val;
}

template<class templ> void CArray<templ>::print() const {
	printf("data= ");
	for (int i=0; i<=last; i++)
		printf("%lf ", data[i]);
	printf("\n");
}

typedef CArray<double> vector_t;

#endif /* _CARRAY_H_ */

