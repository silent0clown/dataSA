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

    ret = FreeSeqList(&SeqList);
    EXPECT_EQ(ret, RET_SUCCESS);
}

TEST(TestSeqList, test_Init_SeqList_2) {

    EXPECT_EQ(1, 1);
}
