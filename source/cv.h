/**
 * Функции для расчета теплопереноса методом конечных объемов по книге Патанкара.
 * Все необходимые для расчета данные определены в модуле @see store. 
 */
#ifndef _CV_H_
#define _CV_H_


#include <common.h>
#include <store.h>

extern void CV_Pre(double thau);
extern void CV_Calc(vector_t *Tr);

#endif /* _CV_H_ */

