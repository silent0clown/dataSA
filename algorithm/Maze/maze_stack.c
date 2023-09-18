#include "maze_stack.h"

RET_STATUS dsa_InitSeqStack(SEQ_STACK* seq_node) {
   seq_node->ptBase = (SEQ_ElemType*)malloc(sizeof(SEQ_ElemType) * STACK_INIT_SIZE);

    if(unlikely(seq_node->ptBase == NULL)) {
        DSA_PRINT_MSG("malloc node fail");

        return RET_OVERFLOW;
    }

    seq_node->dwStackSize = STACK_INIT_SIZE;
    seq_node->ptTop       = seq_node->ptBase;

    return RET_SUCCESS;
}

RET_STATUS dsa_FreeSeqStack(SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    free(seq_node->ptBase);
    seq_node->ptBase = NULL;
    seq_node->ptTop  = NULL;
    seq_node->dwStackSize = 0;

    return RET_SUCCESS;
}

RET_STATUS dsa_ClearSeqStack(SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    memset(seq_node->ptBase, 0, seq_node->dwStackSize);
    seq_node->ptTop = seq_node->ptBase;

    return RET_SUCCESS;
}

bool dsa_IsEmptySeqStack(const SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, false);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, false);

    return seq_node->ptBase == seq_node->ptTop ? true : false;
}
 
WORD32 dsa_GetSeqStackLen(const SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, 0);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, 0);

    return seq_node->ptTop - seq_node->ptBase;
}

RET_STATUS dsa_GetSeqStackTopElem(const SEQ_STACK* seq_node, SEQ_ElemType* data) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    *data = *(seq_node->ptTop - 1);

    return RET_SUCCESS;
}

RET_STATUS dsa_PushToSeqStack(SEQ_STACK* seq_node, SEQ_ElemType data) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    /* 推入过多 */
    if(seq_node->ptTop - seq_node->ptBase >= seq_node->dwStackSize) {
        seq_node->ptBase = (SEQ_ElemType *)realloc(seq_node->ptBase, (seq_node->dwStackSize + STACK_INCREMENT_SIZE) * sizeof(SEQ_ElemType));
        if(unlikely(seq_node->ptBase == NULL)) {
            DSA_PRINT_MSG("realloc node fail");
            return RET_ERROR;
        }

        seq_node->dwStackSize += STACK_INCREMENT_SIZE;
        seq_node->ptTop = seq_node->ptBase + seq_node->dwStackSize;
    }

    *seq_node->ptTop = data;
    seq_node->ptTop ++;

    return RET_SUCCESS;
}

RET_STATUS dsa_PopFromSeqStack(SEQ_STACK* seq_node, SEQ_ElemType* data) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    /* 考虑空栈 */
    if(seq_node->ptBase == seq_node->ptTop) {
        DSA_PRINT_MSG("Stack is empty");

        return RET_ERROR;
    }

    seq_node->ptTop--;
    *data = *seq_node->ptTop;
    // *seq_node->ptTop = 0;

    return RET_SUCCESS;
}

// RET_STATUS dsa_PrintSeqStack(const SEQ_STACK* seq_node) {
//     CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
//     CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

//     SEQ_ElemType* tmp_node = seq_node->ptBase;
    
//     if(tmp_node == seq_node->ptTop) {
//         DSA_PRINT_MSG("Stack is empty")
//         return RET_PARA_FAIL;
//     }
//     printf("Stack elem is : ");
//     while(tmp_node != seq_node->ptTop) {
//         printf("%c", *tmp_node);
//         tmp_node++;
//     }
//     printf("\n");

//     return RET_SUCCESS;
// }

void InitMazeMap(MAZE_MAP maze, Maze_Postion* maze_entrance, Maze_Postion* maze_outlet) {
    int i, j, tmp;
    
    srand((unsigned)time(NULL));    // 用系统时间做随机数种子

    for(i = 0; i < MAZE_COLOMN; i++) {
        for(j = 0; j < MAZE_LINE; j++) {

            // 在迷宫最外围生成墙
            if(i == 0 || j == 0 || i == MAZE_COLOMN - 1 || j == MAZE_LINE - 1) {
                maze[i][j] = Wall;
            }
            else {
                tmp = rand() % MAZE_BARRIER;   // 生成随机数[0, X-1]填充迷宫

                if(tmp == 0) {
                    maze[i][j] = BARRIER;   // 1 / BARRIER 概率生成障碍
                }
                else {
                    maze[i][j] = Road;
                }
            }
        }
    }
    
    /* 出入口坐标 */
    maze_entrance->x = 1;
    maze_entrance->y = 0;

    maze_outlet->x   = MAZE_COLOMN - 2;
    maze_outlet->y   = MAZE_LINE - 1;

    maze[1][0] = maze[MAZE_COLOMN - 2][MAZE_LINE - 1] = Road;
    maze[1][1] = maze[MAZE_COLOMN - 2][MAZE_LINE - 2] = Road;

    PaintMaze(maze);
    printf("\nthis is init maze\n");
}


void PaintMaze(MAZE_MAP maze) {
    int i, j;
    
    // Wait(SleepTime);                // 暂停一下
    
    for(i = 0; i < MAZE_COLOMN; i++) {
        for(j = 0; j < MAZE_LINE; j++) {

            if(maze[i][j] == Wall) {                   // 外墙
                printf("*");
            } else if(maze[i][j] == BARRIER) {        // 迷宫内部的障碍
                printf("●");
            } else if(maze[i][j] == East) {            // 正在朝东探索
                printf("▷");
            } else if(maze[i][j] == South) {           // 正在朝南探索
                printf("▽");
            } else if(maze[i][j] == West) {            // 正在朝西探索
                printf("◁");
            } else if(maze[i][j] == North) {           // 正在朝北探索
                printf("△");
            } else if(maze[i][j] == Unpass) {         // 死胡同，即四个方向都探索过，但无法通过的位置
                printf("x");
            } else {                                   // 还未探索过的路径结点
                printf(" ");
            }
            
            // if(j != 0 && j % (MAZE_LINE - 1) == 0) {           // 每隔N个结点换行
            //     printf("\n");
            // }
        }
        printf("\n");
    }
    
    printf("\n");
}


int MazeDesertion(MAZE_MAP maze, Maze_Postion entrance, Maze_Postion outlet) {
    SEQ_STACK seq_stack;       // 存储探索过的通道
    SEQ_ElemType seq_data;     // 存储当前通道快信息
    Maze_Postion cur_postion;       // 当前位置
    int cur_step = 1;

    dsa_InitSeqStack(&seq_stack);

    cur_postion  = entrance;

    do {
        if(RoadIsCanPass(maze, cur_postion)) {
            FootPrint(maze, cur_postion);
            seq_data = Construct(cur_step, cur_postion, East);
            
            dsa_PushToSeqStack(&seq_stack, seq_data);

            if(cur_postion.x == outlet.x && cur_postion.y == outlet.y) {
                printf("寻路成功...\n");
                return 1;
            }

            // 获取下一个应当探索的位置
            cur_postion = NextPos(cur_postion, East);
            cur_step++;
        }
        else{
            // 如果栈不为空
            if(!dsa_IsEmptySeqStack(&seq_stack)) {
                // 回退到上一个位置
                dsa_PopFromSeqStack(&seq_stack, &seq_data);

                // 如果四个方向都探索过，则需要继续回退
                while(seq_data.di == North && !dsa_IsEmptySeqStack(&seq_stack)) {
                    MarkPrint(maze, seq_data.seat, Unpass);

                    dsa_PopFromSeqStack(&seq_stack, &seq_data);
                }
                // 探索其他方向
                if(seq_data.di < North) {
                    ++seq_data.di;

                    MarkPrint(maze, seq_data.seat, seq_data.di);

                    dsa_PushToSeqStack(&seq_stack, seq_data);

                    cur_postion = NextPos(cur_postion, seq_data.di);
                }

            }
        }
    }while(!dsa_IsEmptySeqStack(&seq_stack));

    printf("\n寻路失败...\n");

    return 0;

}

Maze_Postion NextPos(Maze_Postion seat, int di) {
    Maze_Postion tmp = seat;
    
    switch(di) {
        case East:
            tmp.y++;            //向东
            break;
        case South:
            tmp.x++;            //向南
            break;
        case West:
            tmp.y--;            //向西
            break;
        case North:
            tmp.x--;            //向北
            break;
    }
    
    return tmp;
}


SEQ_ElemType Construct(int ord, Maze_Postion seat, int di) {
    SEQ_ElemType e;
    
    e.ord = ord;
    e.seat = seat;
    e.di = di;
    
    return e;
}


bool RoadIsCanPass(MAZE_MAP maze, Maze_Postion cur_postion) {
    int x = cur_postion.x;
    int y = cur_postion.y;

    if(x < 0 || y < 0 || x > MAZE_COLOMN -1 || y > MAZE_LINE - 1 ) {
        printf("in the bindary\n");
        return false;
    }

    if(maze[x][y] != Road) {
        return false;
    }
    return true;
}

void FootPrint(MAZE_MAP maze, Maze_Postion cur_postion) {
    MarkPrint(maze, cur_postion, East);
}

void MarkPrint(MAZE_MAP maze, Maze_Postion cur_postion, int mark) {
    int x = cur_postion.x;
    int y = cur_postion.y;

    maze[x][y] = mark;


    PaintMaze(maze);
}




