// #ifndef MAZE_H
// #define MAZE_H

// #ifdef __cplusplus
// extern "C" {
// #endif

// #include "maze_stack.h"
#include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define MAZE_COLOMN 15  // 行
// #define MAZE_LINE   30  // 列
// #define MAZE_BARRIER 4  // 障碍出现概率 1/4
// #define SleepTime    3  // 打印地图时间间隔

// typedef enum {
//     Wall,       // 外墙
//     BARRIER,    // 障碍
//     Road,       // 通路
//     Unpass,     // 死胡同
//     East, South, West, North // 探索方向
// }MAZE_NODE;


// typedef int MAZE_MAP[MAZE_COLOMN][MAZE_LINE];  // 迷宫地图

// void InitMazeMap(MAZE_MAP maze, Maze_Postion* maze_entrance, Maze_Postion* maze_outlet);

// void PaintMaze(MAZE_MAP maze);

// SEQ_ElemType Construct(int ord, Maze_Postion seat, int di);

// int MazeDesertion(MAZE_MAP maze, Maze_Postion entrance, Maze_Postion outlet);

// Maze_Postion NextPos(Maze_Postion seat, int di);



// bool RoadIsCanPass(MAZE_MAP maze, Maze_Postion cur_postion);

// void FootPrint(MAZE_MAP maze, Maze_Postion cur_postion);

// void MarkPrint(MAZE_MAP maze, Maze_Postion cur_postion, int mark);

// #ifdef __cplusplus
// }
// #endif


// #endif