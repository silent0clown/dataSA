#include "SeqList.h"

// 申请一个顺序表
RET_STATUS InitSeqList(SeqList* List){
    printf("Func InitSeqList Proc Begin\n");

    List->puiElem = (ElemType*)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if(List->puiElem ==NULL){
        printf("Func InitSeqList Proc Fail\n");

        return RET_OVERFLOW;
    }

    List->uiStoreNum = 0;
    List->uiTotalNum = LIST_INIT_SIZE;
    
    memset(List->puiElem, 0 , sizeof(unsigned int) * LIST_INIT_SIZE);
    printf("Func InitSeqList Proc Succ\n");

    return RET_SUCCESS;
}


// 释放一个顺序表
RET_STATUS FreeSeqList(SeqList* List){
    CHECK_NULL_RETURN_VALUE(List, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(List->puiElem, RET_PARA_NULL);

    free(List->puiElem);
    List->puiElem = NULL;
    List->uiStoreNum = 0;
    List->uiTotalNum = 0;

    return RET_SUCCESS;
}

// 清空顺序表中元素
RET_STATUS ClearSeqList(SeqList* List){
    CHECK_NULL_RETURN_VALUE(List, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(List->puiElem, RET_PARA_NULL);

    memset(List->puiElem, 0, sizeof(unsigned int)*List->uiStoreNum);
    List->uiStoreNum = 0;

    return RET_SUCCESS;
}

bool IsEmptySeqList(SeqList List){
    return List.uiStoreNum == 0 ? true : false;
}

unsigned int GetSeqListNum(SeqList List){
    return List.uiStoreNum;
}

// 获取第i个位置的元素值保存到Elem
RET_STATUS GetSeqListElem(SeqList List, int i, ElemType* Elem){
    if(i < 1 || i > List.uiStoreNum){
        return RET_PARA_FAIL;
    }

    *Elem = List.puiElem[i - 1];
    // Elem = &(List.puiElem[i - 1]);
    // Elem = List.puiElem + sizeof(unsigned int) * (i - 1);
    
    return RET_SUCCESS;
}

// 在顺序表中第i个位置插入元素Elem
RET_STATUS InsertSeqListElem(SeqList* List, int i, ElemType Elem){
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

    for(iLoopTime; iLoopTime >= i; iLoopTime--){
        List->puiElem[iLoopTime] = List->puiElem[iLoopTime - 1];
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

