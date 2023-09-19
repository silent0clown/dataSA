#ifndef DSA_ARRAY_H
#define DSA_ARRAY_H

#ifdef __cplus
extern "C" {
#endif

#include "define.h"
#include "Status.h"
#include <stdarg.h>
#include <stdlib.h>
#define MAX_ARRAY_DIM 8
typedef int ElemType;


typedef struct{
    ElemType * base;
    int dim;
    int* bounds;
    int* constants;
}Array;


RET_STATUS dsa_InitArray(Array* array, int dim, ...);




#ifdef __cplus
}
#endif

#endif