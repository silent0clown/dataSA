#include "LineLinklist.h"

WORD32 dsa_InitLinkList(LNode** Lnode) {
    // CHECK_NULL_RETURN_VALUE(Lnode , RET_PARA_NULL);
    LNode* tmpLnode = NULL;
    tmpLnode =  (LNode*)malloc(sizeof(LNode));

    if(unlikely(tmpLnode == NULL)) {
        DSA_PRINT_MSG("Malloc Lnode Fail");
        return RET_OVERFLOW;
    }
    tmpLnode->data = 0;
    tmpLnode->next = NULL;
    *Lnode = tmpLnode;

    return RET_SUCCESS;
}

WORD32 dsa_FreeLinkList(LNode** Lnode) {
    CHECK_NULL_RETURN_VALUE(*Lnode, RET_PARA_FAIL);

    LNode* tmp_node = *Lnode;

    while(tmp_node != NULL) {
        tmp_node = (*Lnode)->next;
        free(*Lnode);
        (*Lnode) = tmp_node;
    }    

    *Lnode = NULL;
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
    if(unlikely(new_node == NULL)){
        DSA_PRINT_MSG("malloc new node fail");
        return RET_ERROR;
    }
    new_node->data = data;
    new_node->next = t_Lnode->next;
    t_Lnode->next  = new_node;

    return RET_SUCCESS;
}

bool dsa_IsEmptyLinkList(LNode* t_Lnode) {
    return (t_Lnode != NULL && t_Lnode->next == NULL) ? true : false;
}

/* 释放掉非头结点外的空间 */
WORD32 dsa_ClearLinkList(LNode* t_Lnode) {
    CHECK_NULL_RETURN_VALUE(t_Lnode, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(t_Lnode->next, RET_SUCCESS);

    LNode* tmp_node = t_Lnode->next;

    while(tmp_node->next != NULL) {
        t_Lnode->next = tmp_node->next;
        free(tmp_node);
        tmp_node = t_Lnode->next;
    }

    free(tmp_node);
    tmp_node = NULL;
    t_Lnode->next = NULL;

    return RET_SUCCESS;
}

WORD32 dsa_GetLinkListLength(const LNode* t_Lnode) {
    CHECK_NULL_RETURN_VALUE(t_Lnode, 0);

    WORD32 dwlength = 0;
    LNode* p = t_Lnode->next;
    while(p != NULL) {
        p = p->next;
        dwlength += 1; 
    }

    return dwlength;
}

RET_STATUS dsa_GetLinkListElme(LNode* t_Lnode, WORD32 dwlocation, ElemType* data) {
    CHECK_NULL_RETURN_VALUE(t_Lnode, RET_PARA_NULL);
    
    if(dwlocation == 0 || dwlocation > dsa_GetLinkListLength(t_Lnode)) {
        DSA_PRINT_MSG("dwlocation is error");
       
        return RET_PARA_FAIL;
    }

    LNode* tmp = t_Lnode;
    
    for(WORD32 i = 0; i < dwlocation; i++) {
        tmp = tmp->next;
    }

    *data = tmp->data;

    return RET_SUCCESS;
}

RET_STATUS dsa_InsertList_Head(LNode** t_Lnode, S_WORD32 sdwInsertElem) {
    CHECK_NULL_RETURN_VALUE(*t_Lnode, RET_PARA_NULL);

    LNode* tmp_node = (LNode*)malloc(sizeof(LNode));

    if(unlikely(tmp_node == NULL)) {
        DSA_PRINT_MSG("malloc tmp_node fail");
        return RET_ERROR;
    }

    tmp_node->data = sdwInsertElem;
    tmp_node->next = (*t_Lnode)->next;
    (*t_Lnode)->next = tmp_node;

    return RET_SUCCESS;
}

RET_STATUS dsa_InsertList_End(LNode** t_Lnode, S_WORD32 sdwInsertElem) {
    CHECK_NULL_RETURN_VALUE(*t_Lnode, RET_PARA_NULL);

    LNode* tmp_node = (LNode*)malloc(sizeof(LNode));

    if(unlikely(tmp_node == NULL)) {
        DSA_PRINT_MSG("malloc tmp_node fail");
        return RET_ERROR;
    }

    LNode* p = *t_Lnode;

    while(p->next != NULL) {
        p = p->next;
    }

    tmp_node->data = sdwInsertElem;
    tmp_node->next = NULL;
    p->next = tmp_node;

    return RET_SUCCESS;
}

RET_STATUS dsa_SortLinkList(LNode* t_Lnode, BYTE bflag) {
    CHECK_NULL_RETURN_VALUE(t_Lnode, RET_PARA_NULL);


    WORD32 dwLength = dsa_GetLinkListLength(t_Lnode);

    if(dwLength < 2) {
        DSA_PRINT_MSG("List total length is less than 2");
        return RET_SUCCESS;
    }

    LNode* tmp_node = t_Lnode->next;

    for(WORD32 i = 0; i < dwLength - 1; tmp_node = tmp_node->next, i++) {
        LNode* loop_node = t_Lnode->next;

        for(WORD32 j = 0; j < dwLength - i - 1; loop_node = loop_node->next, j++) {
            if(bflag == SORT_INCREASING_FLAG) {
                if(loop_node->data > loop_node->next->data) {
                    ElemType tmp_data = loop_node->data;
                    loop_node->data   = loop_node->next->data;
                    loop_node->next->data = tmp_data;
                }
            }
            else if(bflag == SORT_DIMINISHING_FLAG) {
                if(loop_node->data < loop_node->next->data) {
                    ElemType tmp_data = loop_node->data;
                    loop_node->data   = loop_node->next->data;
                    loop_node->next->data = tmp_data;
                }
            }
        }
    }

    return RET_SUCCESS;
 }

RET_STATUS dsa_MergeLinkList(LNode* t_Lnode1, LNode* t_Lnode2, LNode* t_Lnode3) {
    CHECK_NULL_RETURN_VALUE(t_Lnode1, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(t_Lnode2, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(t_Lnode3, RET_PARA_NULL);

    LNode* p1 = t_Lnode1->next;
    LNode* p2 = t_Lnode2->next;

    LNode* p3 = t_Lnode3;
    while (p1 && p2)
    {
        if(p1->data < p2->data) {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }

    p3->next = p1 ? p1 : p2;

    free(t_Lnode1);
    free(t_Lnode2);
    t_Lnode1 = NULL;
    t_Lnode2 = NULL;

    return RET_SUCCESS;
}
