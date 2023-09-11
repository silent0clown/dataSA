#ifndef LINE_LINK_LIST_H
#define LINE_LINK_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

/* head file */
#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "Status.h"

/* define */
typedef S_WORD32 ElemType;

/* struct */
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;    /* 指向单链表结点的指针 */


/* function */
WORD32 dsa_InitLinkList(LNode* Lnode);
WORD32 dsa_FreeLinkList(LNode* Lnode);
WORD32 dsa_InsertLinkList(LNode* t_Lnode, WORD32 dwlocate, ElemType data);

#ifdef __cplusplus
}
#endif
#endif