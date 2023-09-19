#ifndef LINE_LINK_LIST_H
#define LINE_LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

/* head file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "define.h"
#include "Status.h"

/* define */
#define SORT_INCREASING_FLAG  0
#define SORT_DIMINISHING_FLAG 1

// typedef S_WORD32 ElemType;
// 事件类型枚举常量，0代表到达事件，1至4表示四个窗口的离开事件
typedef enum {
    Arrive, Leave_1, Leave_2, Leave_3, Leave_4
} EventType;

/* 事件链表元素类型定义 */
typedef struct
{
    int OccurTime;      // 事件发生时刻
    EventType NType;    // 事件类型
} Event, ElemType;      // 事件链表元素

/* struct */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;    /* 指向单链表结点的指针 */


/* function */
bool dsa_IsEmptyLinkList(LNode* t_Lnode);

WORD32 dsa_InitLinkList(LNode** Lnode);
WORD32 dsa_FreeLinkList(LNode** Lnode);
WORD32 dsa_InsertLinkList(LNode* t_Lnode, WORD32 dwlocate, ElemType data);
WORD32 dsa_ClearLinkList(LNode* t_Lnode);
WORD32 dsa_GetLinkListLength(const LNode* t_Lnode);

RET_STATUS dsa_GetLinkListElme(LNode* t_Lnode, WORD32 dwlocation, ElemType* data);

RET_STATUS dsa_InsertList_Head(LNode** t_Lnode, S_WORD32 sdwInsertElem);

RET_STATUS dsa_InsertList_End(LNode** t_Lnode, S_WORD32 sdwInsertElem);

RET_STATUS dsa_SortLinkList(LNode* t_Lnode, BYTE bflag);

RET_STATUS dsa_MergeLinkList(LNode* t_Lnode1, LNode* t_Lnode2, LNode* t_Lnode3);

#ifdef __cplusplus
}
#endif
#endif