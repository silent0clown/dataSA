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
#define STATIC_LIST_MAX_SIZE 100
typedef S_WORD32 ElemType;

/* struct */
typedef struct 
{
    /* data */
    ElemType data;
    WORD32   cur;
}SLinkList[STATIC_LIST_MAX_SIZE];

WORD32 dsa_InitStaticList(SLinkList space, WORD32* SL_node);
// WORD32 dsa_FreeStaticList(SLinkList space, WORD32* SL_node);

#ifdef __cplusplus
}
#endif
#endif