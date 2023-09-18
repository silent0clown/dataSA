#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

// head file
#include "define.h"
#include "Status.h"
// #include <string.h>
#include <stdlib.h>

// defination
typedef int QueueDateType;


// data struct 
/* 单链表结构 */
typedef struct QUEUE_NODE {
    QueueDateType data;
    struct QUEUE_NODE* next;
}QUEUE_NODE, *QUEUE_NODE_PTR; 

typedef struct{
    QUEUE_NODE_PTR front;   // 队头指针
    QUEUE_NODE_PTR rear;    // 队尾指针
}LinkQueue;

// function
RET_STATUS dsa_InitQueue(LinkQueue* q_node);

RET_STATUS dsa_FreeQueue(LinkQueue* q_node);

RET_STATUS dsa_ClearQueue(LinkQueue* q_node);

bool dsa_IsEmptyQueue(LinkQueue q_node);

u_int32 dsa_GetQueueLength(LinkQueue q_node);

RET_STATUS dsa_GetQueueHeadData(LinkQueue q_node, QueueDateType* data);

RET_STATUS dsa_InsertQueue(LinkQueue* q_node, QueueDateType data);

RET_STATUS dsa_DeleteQueue(LinkQueue* q_node, QueueDateType* data);

RET_STATUS dsa_PrintQueue(LinkQueue q_node);

#ifdef __cplusplus
}
#endif

#endif