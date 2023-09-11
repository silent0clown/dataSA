/* 线性顺序表 */

#ifndef SEQLIST_H
#define SEQLIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "Status.h"


WORD32 InitSeqList(SeqList* List);

WORD32 FreeSeqList(SeqList* List);

WORD32 ClearSeqList(SeqList* List);
// 增
WORD32 InsertSeqListElem(SeqList* List, unsigned int i, ElemType Elem);

// 删

WORD32 GetSeqListNum(SeqList List);
// 查
WORD32 GetSeqListElem(SeqList List, unsigned int i, ElemType* Elem);

// 改
/*
 * 取值
 *
 * 获取顺序表中第i个元素，将其存储到e中。
 * 如果可以找到，返回OK，否则，返回ERROR。
 *
 *【备注】
 * 教材中i的含义是元素位置，从1开始计数，但这不符合编码的通用约定。
 * 通常，i的含义应该指索引，即从0开始计数。
 */
WORD32 dsa_GetElem(SeqList L, WORD32 i, ElemType* e);
/*
 * ████████ 算法2.6 ████████
 *
 * 查找
 *
 * 返回顺序表中首个与e满足Compare关系的元素位序。
 * 如果不存在这样的元素，则返回0。
 *
 *【备注】
 * 元素e是Compare函数第二个形参
 */
WORD32 dsa_LocateElem(SeqList L, ElemType e);

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
WORD32 dsa_PriorElem(SeqList L, ElemType cur_e, ElemType* pre_e);

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR。
 */
WORD32 dsa_NextElem(SeqList L, ElemType cur_e, ElemType* next_e);

WORD32 dsa_UnionSeqList(SeqList* L1, SeqList L2);

WORD32 dsa_MergeSeqList(SeqList L1, SeqList L2, SeqList* L3);

#ifdef __cplusplus
}
#endif


#endif