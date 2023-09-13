#include "gtest/gtest.h"
#include "Status.h"
#include "linerlinklist/DoubleLinkList.h"

TEST(TestDoubleLinkList, test_Init_LinkList) {
    DuLNode* DL_node = NULL;
    WORD32 dwRet     = RET_ERROR;

    dwRet = dsa_InitDulLinklist(&DL_node);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    ElemType Insertlist[] = {2023, 9, 23, 11, 5, 58};

    for(WORD32 i = 0; i < sizeof(Insertlist)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertDulLinklist(&DL_node, i+1, Insertlist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    dwRet = dsa_InsertDulLinklist(&DL_node, 8, 888);
    EXPECT_EQ(dwRet, RET_PARA_FAIL);

    ElemType data = 0;
    for(WORD32 i = 0; i < sizeof(Insertlist)/sizeof(ElemType); i++) {
        dwRet = dsa_GetDulListElme(DL_node, i+1, &data);
        EXPECT_EQ(dwRet, RET_SUCCESS);
        printf("dulble list elem[%u] is %d\n", i, data);
        EXPECT_EQ(data, Insertlist[i]);
    }

    dwRet = dsa_FreeDulLinklist(&DL_node);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}

TEST(TestDoubleLinkList, test_GetElemLocation) {
    DuLNode* DL_node = NULL;
    WORD32 dwRet     = RET_ERROR;

    dwRet = dsa_InitDulLinklist(&DL_node);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    ElemType Insertlist[] = {2023, 9, 23, 11, 5, 58};

    for(WORD32 i = 0; i < sizeof(Insertlist)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertDulLinklist(&DL_node, i+1, Insertlist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }

    WORD32 dwLocate = 0;
    for(WORD32 i = 0; i < sizeof(Insertlist)/sizeof(ElemType); i++) {
        dwRet = dsa_GetElemLocation(DL_node, Insertlist[i], &dwLocate);
        EXPECT_EQ(dwRet, RET_SUCCESS);
        printf("dulble list elem %d locate is %u\n", Insertlist[i], dwLocate);
        EXPECT_EQ(dwLocate, i+1);
    }
    ElemType testvalue = 777;
    dwRet = dsa_GetElemLocation(DL_node, testvalue, &dwLocate);
    EXPECT_EQ(dwRet, RET_ERROR);

    ElemType data = 0;
    dwRet = dsa_DeleteDulListElem(&DL_node, 3, &data);
    EXPECT_EQ(dwRet, RET_SUCCESS);
    EXPECT_EQ(data, 23);

    dwRet = dsa_DeleteDulListElem(&DL_node, 6, &data);
    EXPECT_EQ(dwRet, RET_ERROR);
    EXPECT_EQ(data, 0);

    dwRet = dsa_FreeDulLinklist(&DL_node);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}