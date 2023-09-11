#ifndef STATUS_H
#define STATUS_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>
#include "define.h"


#ifndef bool
#define bool int
#define true 0
#define false -1
#endif

typedef int RET_STATUS;

/* 宏定义 */
#define LIST_INIT_SIZE    100    // 顺序表初始大小
#define LIST_INCREMENT    10     // 顺序表分配增量

typedef S_WORD32 ElemType;
typedef WORD32 ElemLength;


/* 顺序表结构 */
typedef struct 
{
    S_WORD32* puiElem;      // 顺序表基地址
    WORD32  uiStoreNum;     // 当前表长
    WORD32  uiTotalNum;   // 表的总
}SeqList;


WORD32 itemCompareEqual(ElemType a, ElemType b);



#ifdef __cplusplus
}
#endif


#endif