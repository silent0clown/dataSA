#include "StaticLinklist.h"

WORD32 dsa_Malloc(SLinkList space) {
    WORD32 i = space[0].cur;

    if(i != 0) {
        space[0].cur = space[i].cur;
    }

    return i;
}
/* cur          : 指向数组下标 
 * space[0].cur ：指向备用链表首结点下标
 * space[MAX_SIZE - 1].cur : 指向首个被占用结点下标
*/
void dsa_Free(SLinkList space, WORD32 k) {
    space[k].cur = space[0].cur;
    space[0].cur = k;
}

/* 
 * S    ：指示静态链表头结点索引
 * space：指示备用空间
 */
WORD32 dsa_InitStaticList(SLinkList space, WORD32* SL_node) {
    WORD32 index;

    /* 初始化备用空间 */
    for(WORD32 i = 0; i < STATIC_LIST_MAX_SIZE - 1; i++) {
        space[i].cur = i + 1;
    }
    space[STATIC_LIST_MAX_SIZE - 1].cur = 0; 

    /* 申请头结点空间 */
    index  = dsa_Malloc(space);

    if(index == 0) {
        return RET_ERROR;
    }

    space[index].cur = 0;
    *SL_node = index;

    return RET_SUCCESS;
}


// WORD32 dsa_FreeStaticList(SLinkList space, WORD32* SL_node) {
//     CHECK_NULL_RETURN_VALUE(SL_node, RET_PARA_NULL);

//     if(*SL_node == 0) {
//         return RET_ERROR;
//     }

//     int cur;
//     while (*SL_node != 0) {
//         /* code */
//         cur = space[*SL_node].cur;

//     }
    
// }