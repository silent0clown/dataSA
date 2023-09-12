#ifndef STATUS_H
#define STATUS_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include "define.h"


#ifndef bool
#define bool int
#define true  1
#define false 0
#endif


typedef unsigned int  RET_STATUS;

WORD32 itemCompareEqual(int a, int b);



#ifdef __cplusplus
}
#endif


#endif