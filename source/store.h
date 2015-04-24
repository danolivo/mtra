#ifndef _STORE_H_
#define _STORE_H_

#define CELLS_MAX_NUM		(100)

#include <vector_t.h>

/* Thermophysics of thermal package. */
extern vector_t l[CELLS_MAX_NUM];
extern vector_t c[CELLS_MAX_NUM];
extern vector_t d[CELLS_MAX_NUM];
/* Model data */
extern vector_t T[CELLS_MAX_NUM];
extern vector_t W[CELLS_MAX_NUM];
extern vector_t S[CELLS_MAX_NUM];
/* Boundaries */
extern double alpha_l;
extern double alpha_r;
extern double Te_l;
extern double Te_r;
extern double eps_l;
extern double eps_r;

/* TDMA Coefficients */
extern double Acv[CELLS_MAX_NUM];
extern double Bcv[CELLS_MAX_NUM];
extern double Ccv[CELLS_MAX_NUM];
extern double Dcv[CELLS_MAX_NUM];

#endif /* _STORE_H_ */

