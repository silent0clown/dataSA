#include "gtest/gtest.h"
#include "Status.h"
#include "stackqueue/stack.h"

TEST(TEST_STACK, test_InitSeqStack) {
    SEQ_STACK seq_stack;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitSeqStack(&seq_stack);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    dwRet = dsa_FreeSeqStack(&seq_stack);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}

TEST(TEST_STACK, test_PushToSeqStack) {
    SEQ_STACK seq_stack;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitSeqStack(&seq_stack);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    SEQ_ElemType InsertList[] = {2023, 9, 13, 17, 01, 40};
    SEQ_ElemType data = 0;
    for(WORD32 i = 0; i < sizeof(InsertList)/sizeof(SEQ_ElemType); i++) {
        dwRet = dsa_PushToSeqStack(&seq_stack, InsertList[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
        dwRet = dsa_GetSeqStackTopElem(&seq_stack, &data);
        EXPECT_EQ(data, InsertList[i]);
    }

    dsa_PrintSeqStack(&seq_stack);
    dwRet = dsa_GetSeqStackLen(&seq_stack);
    EXPECT_EQ(dwRet, sizeof(InsertList)/sizeof(SEQ_ElemType));

    dsa_PopFromSeqStack(&seq_stack, &data);
    EXPECT_EQ(data, 40);
    dwRet = dsa_GetSeqStackLen(&seq_stack);
    EXPECT_EQ(dwRet, 5);
    

    dwRet = dsa_FreeSeqStack(&seq_stack);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}