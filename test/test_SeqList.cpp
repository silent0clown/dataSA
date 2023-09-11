#include "gtest/gtest.h"
#include "sequencelist/SeqList.h"
#include "Status.h"

# define INSERT_LIST_ELEMNUM (5)

TEST(TestSeqList, test_Init_SeqList) {
    SeqList SeqList;
    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};

    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
      }

    ElemType e = 0;
    for(int i = 0; i < INSERT_LIST_ELEMNUM + 1; i++){
        ret = dsa_GetElem(SeqList, i, &e);
        if(i == 0){
            EXPECT_EQ(ret, RET_ERROR);
        }
        else{
            EXPECT_EQ(ret, RET_SUCCESS);
        }
        EXPECT_EQ(e, InsertList[i - 1]);
    }

    ret = FreeSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);
}

TEST(TestSeqList, test_Init_SeqList_2) {

    EXPECT_EQ(1, 1);
}

TEST(TestSeqList, test_LocateElem) {
    SeqList SeqList;
    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};

    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
      }

    ElemType e = 0;
    WORD32 dwLocate = 0;
    for(int i = 0; i < INSERT_LIST_ELEMNUM + 1; i++){
        ret = dsa_GetElem(SeqList, i, &e);
        dwLocate = dsa_LocateElem(SeqList, InsertList[i - 1]);
        if(i == 0){
            EXPECT_EQ(ret, RET_ERROR);
            EXPECT_EQ(dwLocate, 0);
        }
        else{
            EXPECT_EQ(ret, RET_SUCCESS);
        }
        EXPECT_EQ(dwLocate, i);
        EXPECT_EQ(e, InsertList[i - 1]);
    }

    ret = FreeSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);
}

TEST(TestSeqList, test_ClearSeqList) {
    SeqList SeqList;
    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};

    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
    }

    ElemType e = 0;
    for(int i = 0; i < INSERT_LIST_ELEMNUM + 1; i++){
        ret = dsa_GetElem(SeqList, i, &e);
        if(i == 0){
            EXPECT_EQ(ret, RET_ERROR);
        }
        else{
            EXPECT_EQ(ret, RET_SUCCESS);
        }
        EXPECT_EQ(e, InsertList[i - 1]);
    }
    ret = ClearSeqList(&SeqList);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        EXPECT_EQ(SeqList.puiElem[i], 0);
    }

    EXPECT_EQ(SeqList.uiStoreNum, 0);
}


TEST(TestSeqList, test_PriorElem) {
    SeqList SeqList;
    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};

    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
      }

    ElemType e = 0;
    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++) {
       ret = dsa_PriorElem(SeqList, InsertList[i], &e);

       if(i == 0) {
            EXPECT_EQ(ret, RET_ERROR);
       }
       else {
            EXPECT_EQ(ret, RET_SUCCESS);
            EXPECT_EQ(e, InsertList[i - 1]);
       }
    }

    ret = FreeSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);
}

TEST(TestSeqList, test_NextElem) {
    SeqList SeqList;
    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};

    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
    }

    ElemType e = 0;
    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++) {
       ret = dsa_NextElem(SeqList, InsertList[i], &e);

       if(i + 1 == INSERT_LIST_ELEMNUM) {
            EXPECT_EQ(ret, RET_ERROR);
       }
       else {
            EXPECT_EQ(ret, RET_SUCCESS);
            EXPECT_EQ(e, InsertList[i + 1]);
       }
    }

    ret = FreeSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);
}

TEST(TestSeqList, test_UnionSeqList) {
    SeqList SeqList, OriList;

    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};
    ElemType OriginList[INSERT_LIST_ELEMNUM] = {2, 3, 8, 1, 12};
    
    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
    }

    ret = InitSeqList(&OriList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&OriList, i+1, OriginList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
    }
    ret = dsa_UnionSeqList(&OriList, SeqList);
    for(WORD32 i = 0; i < OriList.uiStoreNum; i++) {
        printf("Elem[%u] = %d\n", i, OriList.puiElem[i]);
    }
    EXPECT_EQ(OriList.uiStoreNum , 8);
}

TEST(TestSeqList, test_MergeSeqList) {
    SeqList SeqList, OriList, MergeList;

    RET_STATUS ret = RET_ERROR;
    ElemType InsertList[INSERT_LIST_ELEMNUM] = {8, 9, 7, 5, 1};
    ElemType OriginList[INSERT_LIST_ELEMNUM] = {2, 3, 8, 1, 12};
    
    ret = InitSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&SeqList, i+1, InsertList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
    }

    ret = InitSeqList(&OriList);
    EXPECT_EQ(ret, RET_SUCCESS);

    for(int i = 0; i < INSERT_LIST_ELEMNUM; i++){
        ret = InsertSeqListElem(&OriList, i+1, OriginList[i]);
        EXPECT_EQ(ret, RET_SUCCESS);
    }

    ret = InitSeqList(&MergeList);
    EXPECT_EQ(ret, RET_SUCCESS);

    ret = dsa_MergeSeqList(OriList, SeqList, &MergeList);
    EXPECT_EQ(MergeList.uiStoreNum , 8);
    for(WORD32 i = 0; i < MergeList.uiStoreNum - 1; i++) {
        printf("Elem[%u] = %d\n", i, MergeList.puiElem[i]);
        EXPECT_LE(MergeList.puiElem[i], MergeList.puiElem[i+1]);
    }
    printf("Elem[%u] = %d\n", MergeList.uiStoreNum -1, MergeList.puiElem[MergeList.uiStoreNum -1]);
}