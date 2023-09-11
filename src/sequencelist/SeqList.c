#include "SeqList.h"

// 申请一个顺序表
WORD32 InitSeqList(SeqList* List) {


    List->puiElem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if(List->puiElem ==NULL){
        DSA_PRINT_MSG("Func InitSeqList Proc Fail");
        return RET_OVERFLOW;
    }

    List->uiStoreNum = 0;
    List->uiTotalNum = LIST_INIT_SIZE;
    
    memset(List->puiElem, 0 , sizeof(unsigned int) * LIST_INIT_SIZE);


    return RET_SUCCESS;
}


// 释放一个顺序表
WORD32 FreeSeqList(SeqList* List) {
    CHECK_NULL_RETURN_VALUE(List, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(List->puiElem, RET_PARA_NULL);

    free(List->puiElem);
    List->puiElem = NULL;
    List->uiStoreNum = 0;
    List->uiTotalNum = 0;

    return RET_SUCCESS;
}

// 清空顺序表中元素
WORD32 ClearSeqList(SeqList* List) {
    CHECK_NULL_RETURN_VALUE(List, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(List->puiElem, RET_PARA_NULL);

    memset(List->puiElem, 0, sizeof(unsigned int)*List->uiStoreNum);
    List->uiStoreNum = 0;

    return RET_SUCCESS;
}

bool IsEmptySeqList(SeqList List){
    return List.uiStoreNum == 0 ? true : false;
}

WORD32 GetSeqListNum(SeqList List){
    return List.uiStoreNum;
}

// 获取第i个位置的元素值保存到Elem
WORD32 GetSeqListElem(SeqList List, unsigned int i, ElemType* Elem) {
    if(i < 1 || i > List.uiStoreNum){
        return RET_PARA_FAIL;
    }

    *Elem = List.puiElem[i - 1];
    // Elem = &(List.puiElem[i - 1]);
    // Elem = List.puiElem + sizeof(unsigned int) * (i - 1);
    
    return RET_SUCCESS;
}

// 在顺序表中第i个位置插入元素Elem
WORD32 InsertSeqListElem(SeqList* List, unsigned int i, ElemType Elem) {
    CHECK_NULL_RETURN_VALUE(List, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(List->puiElem, RET_PARA_NULL);

    // 需判断i的有效性
    if(i < 1 || i > List->uiStoreNum + 1){
        return RET_PARA_FAIL;
    }

    // 如果插入的是第101个元素, 需提醒已满
    if(List->uiStoreNum + 1 > List->uiTotalNum){
        printf("SeqList has restore 100 Elem\n");

        return RET_PARA_FAIL;
    }

    // 需将i后的元素往后移动，共需移动 List->uiStoreNum - (i - 1) 个元素
    ElemLength iLoopTime = List->uiStoreNum;

    while(iLoopTime >= i){
        List->puiElem[iLoopTime] = List->puiElem[iLoopTime - 1];
        iLoopTime--;
    }

    /* 以下代码可以提高效率，但是需要调试 */
    // for(iLoopTime; iLoopTime > i; iLoopTime -= 2){
    //     List->puiElem[iLoopTime] =  List->puiElem[iLoopTime -1];
    //     List->puiElem[iLoopTime - 1] =  List->puiElem[iLoopTime - 2]; 
    // }
    // if(iLoopTime - i == 1){
    //     List->puiElem[iLoopTime] = List->puiElem[iLoopTime - 1];
    //     List->puiElem[iLoopTime - 1] = Elem;
    // }
    // else{   /* 此时iLoopTime = 0 */
    //     List->puiElem[iLoopTime] = Elem;
    // }
    List->uiStoreNum += 1;
    List->puiElem[iLoopTime] = Elem;

    return RET_SUCCESS;
}

WORD32 dsa_GetElem(SeqList L, WORD32 i, ElemType* e) {
    CHECK_NULL_RETURN_VALUE(e, RET_ERROR);
    if(i > L.uiStoreNum || i == 0){
        DSA_PRINT_MSG("Get elem location is error");
        return RET_ERROR;
    }
    *e = L.puiElem[i-1];
    return RET_SUCCESS;
}

WORD32 dsa_LocateElem(SeqList L, ElemType e) {
    WORD32 i = 0;
    while(i < L.uiStoreNum) {
        if(L.puiElem[i] == e) {
            return i + 1;
        }
        i++;
    }

    return 0;
}

WORD32 dsa_PriorElem(SeqList L, ElemType cur_e, ElemType* pre_e) {
    CHECK_NULL_RETURN_VALUE(pre_e, RET_ERROR);
    WORD32 i = 0;

    while(i < L.uiStoreNum) {
        if(L.puiElem[i] == cur_e) {
            if(i == 0) {
                return RET_ERROR;
            }
            *pre_e = L.puiElem[i - 1];
            return RET_SUCCESS;
        }

        i++;
    }

    return RET_ERROR;
}

WORD32 dsa_NextElem(SeqList L, ElemType cur_e, ElemType* next_e) {
    CHECK_NULL_RETURN_VALUE(next_e, RET_ERROR);

    for(WORD32 i = 0; i < L.uiStoreNum; i++) {
        if(L.puiElem[i] == cur_e) {
            if(i + 1 == L.uiStoreNum) {
                return RET_ERROR;
            }
            * next_e = L.puiElem[i+1];
            return RET_SUCCESS;
        }
    }

    return RET_ERROR;
}

WORD32 dsa_UnionSeqList(SeqList* L1, SeqList L2) {
    CHECK_NULL_RETURN_VALUE(L1, RET_PARA_NULL);

    for(WORD32 i  = 0; i < L2.uiStoreNum; i++) {
        WORD16 wElemFlag  = 0;
        for(WORD32 j = 0; j < L1->uiStoreNum; j++) {
            if(L2.puiElem[i] == L1->puiElem[j]) {
                wElemFlag = 1;
                break;
            }
        }

        if(L1->uiStoreNum + 1 > L1->uiTotalNum) {
            DSA_PRINT_MSG("Insert elem num more than max");
            return RET_ERROR;
        }

        if(wElemFlag != 1) {
            L1->puiElem[L1->uiStoreNum] = L2.puiElem[i];
            L1->uiStoreNum += 1;
        }
    }
    return RET_SUCCESS;
}

WORD32 dsa_MergeSeqList(SeqList L1, SeqList L2, SeqList* L3) {
    CHECK_NULL_RETURN_VALUE(L3, RET_PARA_NULL);
    WORD32 ret = RET_ERROR;

    ret = dsa_UnionSeqList(L3, L1);
    if(ret != RET_SUCCESS) {
        DSA_PRINT_MSG("Insert elem num more than max");
        return RET_ERROR;
    }

    ret = dsa_UnionSeqList(L3, L2);
    if(ret != RET_SUCCESS) {
        DSA_PRINT_MSG("Insert elem num more than max");
        return RET_ERROR;
    }
    ElemType temp = 0;
    /* 外轮循环轮数 */
    for(WORD32 i  = 0;  i < L3->uiStoreNum - 1; i++) {
        /* 当前一轮需要比较的次数 */
        for(WORD32 j = 0; j < L3->uiStoreNum - 1 - i; j++) {
            if(L3->puiElem[j] > L3->puiElem[j + 1]) {
                temp = L3->puiElem[j];
                L3->puiElem[j] = L3->puiElem[j+1];
                L3->puiElem[j+1] = temp;
            }
        }
    }

    return RET_SUCCESS;
    
}

