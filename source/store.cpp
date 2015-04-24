#include <store.h>

/* Thermophysics of thermal package. */
vector_t l[CELLS_MAX_NUM];
vector_t c[CELLS_MAX_NUM];
vector_t d[CELLS_MAX_NUM];
/* Model data */
vector_t T[CELLS_MAX_NUM];
vector_t W[CELLS_MAX_NUM];
vector_t S[CELLS_MAX_NUM];
/* Boundaries */
double alpha_l;
double alpha_r;
double Te_l;
double Te_r;
double eps_l;
double eps_r;
/* TDMA Coefficients */
double Acv[CELLS_MAX_NUM];
double Bcv[CELLS_MAX_NUM];
double Ccv[CELLS_MAX_NUM];
double Dcv[CELLS_MAX_NUM];

