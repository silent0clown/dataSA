#include "maze_stack.h"                        //**▲03 栈和队列**//

int main() {
    MAZE_MAP maze;
    Maze_Postion start, end;
    char n, Re = 'Y';
    
    while(Re == 'Y' || Re == 'y') {
        InitMazeMap(maze, &start, &end);    // 初始化迷宫，包括出入口

        MazeDesertion(maze, start, end);      // 迷宫寻路

        printf("重置？（Y/N）：");
        scanf("%c%c", &Re, &n);
        
        printf("\n");
    }
    
    return 0;
}