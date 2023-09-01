#include <stdio.h>
#include "SeqList.h"


# define INSERT_LIST_ELEMNUM (5)

void test_InitSeqList()
{
    SeqList SeqList;
    int ret = RET_ERROR;

    printf("[MAIN TEST] Func InitSeqList test begin...\n");

    /* 这边一开始传入指针，导致coredump */
    /* 若要传入指针，需要二级指针且改写函数 */
    ret = InitSeqList(&SeqList);
    if(ret == RET_SUCCESS && SeqList.puiElem != NULL){
        printf("[MAIN TEST] ptr elem is %n\n", SeqList.puiElem);
        printf("[MAIN TEST] ptr total size is %d\n", SeqList.uiTotalNum);
        printf("[MAIN TEST] ptr have elem is %d\n", SeqList.uiStoreNum);
    }
    else{
        printf("[MAIN TEST] malloc ptr fail!\n");
    }

    ret = FreeSeqList(&SeqList);
    if(ret == RET_SUCCESS && SeqList.puiElem == NULL){
        printf("[MAIN TEST] free ptr Succ!\n");
    }
    else{
        printf("[MAIN TEST] free ptr Fail!\n");
    }

}




int main()
{
    SeqList SeqList;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};
    RET_STATUS ret = RET_ERROR;

    printf("[MAIN TEST] Func InitSeqList test begin...\n");
    /* 这边一开始传入指针，导致coredump */
    /* 若要传入指针，需要二级指针且改写函数 */
    ret = InitSeqList(&SeqList);
    if(ret == RET_SUCCESS && SeqList.puiElem != NULL){
        printf("[MAIN TEST] ptr elem is %n\n", SeqList.puiElem);
        printf("[MAIN TEST] ptr total size is %d\n", SeqList.uiTotalNum);
        printf("[MAIN TEST] ptr have elem is %d\n", SeqList.uiStoreNum);
    }
    else{
        printf("[MAIN TEST] malloc ptr fail!\n");
    }

    // 插入字符
    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        if(ret != RET_SUCCESS){
            printf("Insert fail\n");
            break;
        }
    }

    if(ret == RET_SUCCESS){
        printf("[TEST INSERT] List has %u Elem\n", GetSeqListNum(SeqList));
    }
    else{
        printf("[TEST INSERT] Insert SeqList fail\n");
    }

    // 查找字符
    printf("[TEST LOOKUP] Lookup value is :");
    // ElemType lookup[INSERT_LIST_ELEMNUM] = {};
    ElemType value = 0;
    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = GetSeqListElem(SeqList, i + 1, &value);
        if(ret != RET_SUCCESS){
            printf("[TEST LOOKUP] Lookup fail\n");
            break;
        }
        printf(" %d", value);
    }
    printf(" \n");
    // if(ret == RET_SUCCESS){
    //     printf("[TEST LOOKUP] Lookup value is :");
    //     for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
    //         printf(" %d",lookup[i]);
    //     }
    //     printf("\n");
        
    // }


    // 释放内存
    ret = FreeSeqList(&SeqList);
    if(ret == RET_SUCCESS && SeqList.puiElem == NULL){
        printf("[MAIN TEST] free ptr Succ!\n");
    }
    else{
        printf("[MAIN TEST] free ptr Fail!\n");
    }


    return 0;
}