#ifndef EXPRESSION_STACK_H
#define EXPRESSION_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

/* head file   */
#include "define.h"
#include "Status.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* definiation */
#define STACK_INIT_SIZE       1000
#define STACK_INCREMENT_SIZE  20
// typedef unsigned int  SEQ_ElemType;


// 迷宫通道块的坐标
typedef struct {
    int x;      // 通道块的横、纵坐标定义
    int y;
} Maze_Postion;


/* 通道块信息，用于迷宫算法 */
typedef union {
    int  number;     // 计算数
    char optr;       // 符号
} SEQ_ElemType;

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

// RET_STATUS dsa_PrintSeqStack(const SEQ_STACK* seq_node);

#define MAZE_COLOMN 15  // 行
#define MAZE_LINE   30  // 列

#define MAZE_BARRIER 4  // 障碍出现概率 1/4
#define SleepTime    3  // 打印地图时间间隔

typedef enum {
    Wall,       // 外墙
    BARRIER,    // 障碍
    Road,       // 通路
    Unpass,     // 死胡同
    East, South, West, North // 探索方向
}MAZE_NODE;


#ifdef __cplusplus
}
#endif

#endif