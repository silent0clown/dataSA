// #include "Maze.h"
#include<stdio.h>
#define  int  2
void print()
{
    printf("12323");

    return;
}

// void InitMazeMap(MAZE_MAP maze, Maze_Postion* maze_entrance, Maze_Postion* maze_outlet) {
//     int i, j, tmp;
    
//     srand((unsigned)time(NULL));    // 用系统时间做随机数种子

//     for(i = 0; i < MAZE_COLOMN; i++) {
//         for(j = 0; j < MAZE_LINE; j++) {

//             // 在迷宫最外围生成墙
//             if(i == 0 || j == 0 || i == MAZE_COLOMN - 1 || j == MAZE_LINE - 1) {
//                 maze[i][j] = Wall;
//             }
//             else {
//                 tmp = rand() % MAZE_BARRIER;   // 生成随机数[0, X-1]填充迷宫

//                 if(tmp == 0) {
//                     maze[i][j] == BARRIER;   // 1 / BARRIER 概率生成障碍
//                 }
//                 else {
//                     maze[i][j] == Road;
//                 }
//             }
//         }
//     }
    
//     /* 出入口坐标 */
//     maze_entrance->x = 1;
//     maze_entrance->y = 0;

//     maze_outlet->x   = MAZE_COLOMN - 2;
//     maze_outlet->y   = MAZE_LINE - 1;

//     PaintMaze(maze);
// }


// void PaintMaze(MAZE_MAP maze) {
//     int i, j;
    
//     // Wait(SleepTime);                // 暂停一下
    
//     for(i = 0; i < MAZE_COLOMN; i++) {
//         for(j = 0; j < MAZE_LINE; j++) {
//             if(maze[i][j] == Wall) {                   // 外墙
//                 printf("*");
//             } else if(maze[i][j] == BARRIER) {        // 迷宫内部的障碍
//                 printf("●");
//             } else if(maze[i][j] == East) {            // 正在朝东探索
//                 printf("▷");
//             } else if(maze[i][j] == South) {           // 正在朝南探索
//                 printf("▽");
//             } else if(maze[i][j] == West) {            // 正在朝西探索
//                 printf("◁");
//             } else if(maze[i][j] == North) {           // 正在朝北探索
//                 printf("△");
//             } else if(maze[i][j] == Unpass) {         // 死胡同，即四个方向都探索过，但无法通过的位置
//                 printf("x");
//             } else {                                   // 还未探索过的路径结点
//                 printf(" ");
//             }
            
//             // if(j != 0 && j % (MAZE_LINE - 1) == 0) {           // 每隔N个结点换行
//             //     printf("\n");
//             // }
//         }
//         printf("\n");
//     }
    
//     printf("\n");
// }


// int MazeDesertion(MAZE_MAP maze, Maze_Postion entrance, Maze_Postion outlet) {
//     SEQ_STACK seq_stack;       // 存储探索过的通道
//     SEQ_ElemType seq_data;     // 存储当前通道快信息
//     Maze_Postion cur_postion;       // 当前位置

//     dsa_InitSeqStack(&seq_stack);

//     cur_postion  = entrance;
//     int cur_step = 1;

//     do {
//         if(RoadIsCanPass(maze, cur_postion)) {
//             FootPrint(maze, cur_postion);
//             seq_data = Construct(cur_step, cur_postion, East);
            
//             dsa_PushToSeqStack(&seq_stack, seq_data);

//             if(cur_postion.x == outlet.x && cur_postion.y == outlet.y) {
//                 printf("寻路成功...\n");
//                 return 1;
//             }

//             // 获取下一个应当探索的位置
//             cur_postion = NextPos(cur_postion, East);
//             cur_step++;
//         }
//         else{
//             // 如果栈不为空
//             if(!dsa_IsEmptySeqStack(&seq_stack)) {
//                 // 回退到上一个位置
//                 dsa_PopFromSeqStack(&seq_stack, &seq_data);

//                 // 探索其他方向
//                 if(seq_data.di < North) {
//                     ++seq_data.di;

//                     MarkPrint(maze, seq_data.seat, seq_data.di);

//                     dsa_PushToSeqStack(&seq_stack, seq_data);

//                     cur_postion = NextPos(cur_postion, seq_data.di);
//                 }

//                 // 如果四个方向都探索过，则需要继续回退
//                 if(seq_data.di == North && !dsa_IsEmptySeqStack(&seq_stack)) {
//                     MarkPrint(maze, seq_data.seat, Unpass);

//                     dsa_PopFromSeqStack(&seq_stack, &seq_data);
//                 }
//             }
//         }
//     }while(!dsa_IsEmptySeqStack(&seq_stack));

//     printf("\n寻路失败...\n");

//     return 0;

// }

// Maze_Postion NextPos(Maze_Postion seat, int di) {
//     Maze_Postion tmp = seat;
    
//     switch(di) {
//         case East:
//             tmp.y++;            //向东
//             break;
//         case South:
//             tmp.x++;            //向南
//             break;
//         case West:
//             tmp.y--;            //向西
//             break;
//         case North:
//             tmp.x--;            //向北
//             break;
//     }
    
//     return tmp;
// }


// SEQ_ElemType Construct(int ord, Maze_Postion seat, int di) {
//     SEQ_ElemType e;
    
//     e.ord = ord;
//     e.seat = seat;
//     e.di = di;
    
//     return e;
// }


// bool RoadIsCanPass(MAZE_MAP maze, Maze_Postion cur_postion) {
//     int x = cur_postion.x;
//     int y = cur_postion.y;

//     if(x < 0 || y < 0 || x >= MAZE_COLOMN || y >= MAZE_LINE ) {
//         printf("in the bindary\n");
//         return false;
//     }

//     if(maze[x][y] != Road) {
//         return false;
//     }
//     return true;
// }

// void FootPrint(MAZE_MAP maze, Maze_Postion cur_postion) {
//     MarkPrint(maze, cur_postion, East);
// }

// void MarkPrint(MAZE_MAP maze, Maze_Postion cur_postion, int mark) {
//     int x = cur_postion.x;
//     int y = cur_postion.y;

//     maze[x][y] = mark;


//     PaintMaze(maze);
// }