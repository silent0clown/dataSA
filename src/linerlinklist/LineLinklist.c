#include "LineLinklist.h"

WORD32 dsa_InitLinkList(LNode* Lnode) {
    // CHECK_NULL_RETURN_VALUE(Lnode , RET_PARA_NULL);
    LNode* tmpLnode = NULL;
    tmpLnode =  (LNode*)malloc(sizeof(LNode));
    if(unlikely(tmpLnode == NULL)) {
        DSA_PRINT_MSG("Malloc Lnode Fail");
        return RET_OVERFLOW;
    }
    tmpLnode->next = NULL;
    Lnode = tmpLnode;

    return RET_SUCCESS;
}

WORD32 dsa_FreeLinkList(LNode* Lnode) {
    CHECK_NULL_RETURN_VALUE(Lnode, RET_PARA_FAIL);

    LNode* tmp_node = NULL;
    while(Lnode != NULL) {
        tmp_node = Lnode->next;
        free(Lnode);
        Lnode = tmp_node;
    }    

    Lnode = NULL;
    return RET_SUCCESS;
}

/* 向列表中第dwlocate个位置插入元素data */
WORD32 dsa_InsertLinkList(LNode* t_Lnode,  WORD32 dwlocate, ElemType data) {
    CHECK_NULL_RETURN_VALUE(t_Lnode, RET_PARA_NULL);

    WORD32 i = 0;
    /* 寻找第i-1个结点 */
    while(t_Lnode != NULL && i < dwlocate - 1) {
        t_Lnode = t_Lnode->next;
        i++;
    }

    if(t_Lnode == NULL) {
        DSA_PRINT_MSG("t_Lnode is null");
        return RET_PARA_FAIL;
    }

    // 生成新节点
    LNode* new_node = (LNode*)malloc(sizeof(LNode));
    if(new_node == NULL){
        DSA_PRINT_MSG("malloc new node fail");
        return RET_ERROR;
    }
    new_node->data = data;
    new_node->next = t_Lnode->next;
    t_Lnode->next  = new_node;

    return RET_SUCCESS;
}