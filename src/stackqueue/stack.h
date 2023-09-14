#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

/* head file   */
#include "define.h"
#include "Status.h"
#include <stdlib.h>
#include <string.h>

/* definiation */
#define STACK_INIT_SIZE       1000
#define STACK_INCREMENT_SIZE  20
typedef char SEQ_ElemType;

/* data struct */
typedef struct SEQ_STACK {
    SEQ_ElemType* ptBase;
    SEQ_ElemType* ptTop;
    WORD32        dwStackSize;
}SEQ_STACK;   /* 顺序栈 */


/* function   */
RET_STATUS dsa_InitSeqStack(SEQ_STACK* seq_node);
RET_STATUS dsa_FreeSeqStack(SEQ_STACK* seq_node);
RET_STATUS dsa_ClearSeqStack(SEQ_STACK* seq_node);

bool dsa_IsEmptySeqStack(const SEQ_STACK* seq_node);

WORD32 dsa_GetSeqStackLen(const SEQ_STACK* seq_node);

RET_STATUS dsa_GetSeqStackTopElem(const SEQ_STACK* seq_node, SEQ_ElemType* data);

RET_STATUS dsa_PushToSeqStack(SEQ_STACK* seq_node, SEQ_ElemType data);

RET_STATUS dsa_PopFromSeqStack(SEQ_STACK* seq_node, SEQ_ElemType* data);

RET_STATUS dsa_PrintSeqStack(const SEQ_STACK* seq_node);

#ifdef __cplusplus
}
#endif

#endif