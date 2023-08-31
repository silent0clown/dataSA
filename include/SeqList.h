/* 线性顺序表 */

#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "Status.h"

/* 宏定义 */
#define LIST_INIT_SIZE    100    // 顺序表初始大小
#define LIST_INCREMENT    10     // 顺序表分配增量

typedef int ElemType;
typedef unsigned int ElemLength;


/* 顺序表结构 */
typedef struct 
{
    ElemType* puiElem;      // 顺序表基地址
    ElemLength  uiStoreNum;     // 当前表长
    ElemLength  uiTotalNum;   // 表的总
}SeqList;

RET_STATUS InitSeqList(SeqList* List);

RET_STATUS FreeSeqList(SeqList* List);

RET_STATUS ClearSeqList(SeqList* List);

RET_STATUS InsertSeqListElem(SeqList* List, int i, ElemType Elem);

unsigned int GetSeqListNum(SeqList List);

RET_STATUS GetSeqListElem(SeqList List, int i, ElemType* Elem);

#endif