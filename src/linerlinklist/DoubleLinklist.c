/* 双向循环链表 */
#include "DoubleLinkList.h"

RET_STATUS dsa_InitDulLinklist(DuLNode** DL_node) {
    DuLNode* tmp_node = (DuLNode*)malloc(sizeof(DuLNode));
    if(unlikely(tmp_node == NULL)) {
        DSA_PRINT_MSG("malloc node fail");
        return RET_ERROR;
    }
    tmp_node->data       = 0;
    tmp_node->piror_node = tmp_node;   
    tmp_node->next_node  = tmp_node;
    *DL_node = tmp_node;
    
    return RET_SUCCESS;
}

RET_STATUS dsa_FreeDulLinklist(DuLNode** DL_node) {
    CHECK_NULL_RETURN_VALUE(DL_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(*DL_node, RET_PARA_NULL);

    DuLNode* free_node = *DL_node;
    DuLNode* tmp_node;
    while(free_node != *DL_node) {
        tmp_node = free_node->next_node;
        free(free_node);
        free_node = tmp_node;
    }

    *DL_node = NULL;

    return RET_SUCCESS;
}


/* 在第dwlocation位置插入元素data */
RET_STATUS dsa_InsertDulLinklist(DuLNode** DL_node, WORD32 dwLocation, ElemType data) {
    CHECK_NULL_RETURN_VALUE(DL_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(*DL_node, RET_PARA_NULL);

    if(dwLocation == 0) {
        DSA_PRINT_MSG("Insert location can not 0");
        return RET_PARA_FAIL;
    }
    DuLNode* tmp_node = *DL_node;

    for(WORD32 i = 1; i < dwLocation; i++) {
        tmp_node = tmp_node->next_node;
        /* 重新指向头结点 */
        if(tmp_node == *DL_node) {
            DSA_PRINT_MSG("Insert location larger than list length");
            return RET_PARA_FAIL;
        }
    }

    DuLNode* In_node  = (DuLNode*)malloc(sizeof(DuLNode));
    if(unlikely(In_node == NULL)) {
        DSA_PRINT_MSG("malloc node fail");
        return RET_ERROR;
    }

    In_node->data = data;
    In_node->piror_node = tmp_node;
    In_node->next_node  = tmp_node->next_node;
    tmp_node->next_node = In_node;

    return RET_SUCCESS;
}

RET_STATUS dsa_GetDulListElme(DuLNode* DL_node, WORD32 dwLocation, ElemType* data) {
    CHECK_NULL_RETURN_VALUE(DL_node, RET_PARA_NULL);

    if(dwLocation == 0) {
        DSA_PRINT_MSG("Insert location can not 0");
        return RET_PARA_FAIL;
    }
    DuLNode* tmp_node = DL_node;

    for(WORD32 i = 0; i < dwLocation; i++) {
        tmp_node = tmp_node->next_node;
        if(tmp_node == NULL) {
            DSA_PRINT_MSG("Insert location larger than list length");
            return RET_PARA_FAIL;
        }
    }
    *data = tmp_node->data;

    return RET_SUCCESS;
}

RET_STATUS dsa_GetElemLocation(const DuLNode* const DL_node, const ElemType data, WORD32* dwLocate) {
    CHECK_NULL_RETURN_VALUE(DL_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(dwLocate, RET_PARA_NULL);

    const DuLNode* tmp_node = DL_node->next_node;

    WORD32 dwCount = 1;
    while(tmp_node->data != data) {
        if(tmp_node == DL_node) {
            DSA_PRINT_MSG("Can't found elem %d", data);
            *dwLocate = 0;

            return RET_ERROR;
        }
        tmp_node = tmp_node->next_node;  /* 可以改变地址，不能改变值 */
        dwCount++;
    }
    *dwLocate = dwCount;

    return RET_SUCCESS;
}

RET_STATUS dsa_DeleteDulListElem(DuLNode** DL_node, WORD32 dwLocation, ElemType* data) {
    CHECK_NULL_RETURN_VALUE(DL_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(*DL_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(data, RET_PARA_NULL);

    if(dwLocation == 0) {
        DSA_PRINT_MSG("locate can not zero");
        *data = 0;

        return RET_ERROR;
    }

    DuLNode* tmp_node = *DL_node;
    for(WORD32 i = 0; i < dwLocation; i++) {
        tmp_node = tmp_node->next_node;
        if(tmp_node == *DL_node) {
            DSA_PRINT_MSG("locaton lager than list length");
            *data = 0;
            return RET_ERROR;
        }
    }

    *data = tmp_node->data;
    DuLNode* del_node = tmp_node->next_node;
    tmp_node->next_node = del_node->next_node;
    free(del_node);
    del_node = NULL;

    return RET_SUCCESS;
}
