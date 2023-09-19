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
// typedef int QueueDateType;
/* 链队元素类型定义，这里记录客户信息 */
typedef struct {
    int ArrivedTime;    // 客户到达时间
    int Duration;       // 办理业务所需的时间
    int Count;          // 此变量记录来到每个队列的客户是第几个【教材中无此变量，增加此变量的目的是观察排队状况。】
} QElemType;            //队列的数据元素类型

// 队列元素结构
typedef struct QNode {
    QElemType data;
    struct QNode* next;
} QNode, * QueuePtr;

// 队列结构
typedef struct {
    QueuePtr front;     // 队头指针
    QueuePtr rear;      // 队尾指针
} LinkQueue;            // 队列的链式存储表示



// data struct 
/* 单链表结构 */
// typedef struct QUEUE_NODE {
//     QueueDateType data;
//     struct QUEUE_NODE* next;
// }QUEUE_NODE, *QUEUE_NODE_PTR; 

// typedef struct{
//     QUEUE_NODE_PTR front;   // 队头指针
//     QUEUE_NODE_PTR rear;    // 队尾指针
// }LinkQueue;

// function
RET_STATUS dsa_InitQueue(LinkQueue* q_node);

RET_STATUS dsa_FreeQueue(LinkQueue* q_node);

RET_STATUS dsa_ClearQueue(LinkQueue* q_node);

bool dsa_IsEmptyQueue(LinkQueue q_node);

u_int32 dsa_GetQueueLength(LinkQueue q_node);

RET_STATUS dsa_GetQueueHeadData(LinkQueue q_node, QElemType* data);

RET_STATUS dsa_InsertQueue(LinkQueue* q_node, QElemType data);

RET_STATUS dsa_DeleteQueue(LinkQueue* q_node, QElemType* data);

RET_STATUS dsa_PrintQueue(LinkQueue q_node);

#ifdef __cplusplus
}
#endif

#endif