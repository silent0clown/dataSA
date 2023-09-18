#ifndef MAZE_STACK_H
#define MAZE_STACK_H

#ifdef __cplusplus
extern "C" {
#endif

/* head file   */
#include "define.h"
#include "Status.h"
#include "maze.h"
#include <stdlib.h>
#include <string.h>
#include<time.h>
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
typedef struct {
    int ord;        // 通道块的“序号”
    Maze_Postion seat;   // 通道块的“坐标位置”
    int di;         // 下一个应当访问的“方向”
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


typedef int MAZE_MAP[MAZE_COLOMN][MAZE_LINE];  // 迷宫地图

void InitMazeMap(MAZE_MAP maze, Maze_Postion* maze_entrance, Maze_Postion* maze_outlet);

void PaintMaze(MAZE_MAP maze);

SEQ_ElemType Construct(int ord, Maze_Postion seat, int di);

int MazeDesertion(MAZE_MAP maze, Maze_Postion entrance, Maze_Postion outlet);

Maze_Postion NextPos(Maze_Postion seat, int di);



bool RoadIsCanPass(MAZE_MAP maze, Maze_Postion cur_postion);

void FootPrint(MAZE_MAP maze, Maze_Postion cur_postion);

void MarkPrint(MAZE_MAP maze, Maze_Postion cur_postion, int mark);


#ifdef __cplusplus
}
#endif

#endif