#include "gtest/gtest.h"
#include "linerlinklist/LineLinklist.h"
#include "Status.h"

TEST(TestSingleLinkList, test_Init_LinkList) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);
    dwRet = dsa_FreeLinkList(t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    // ASSERT_NE(t_Lnode, NULL);
}

TEST(TestSingleLinkList, test_InsertLinkList) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    dwRet = dsa_InsertLinkList(t_Lnode, 1, 2);
    EXPECT_EQ(dwRet, RET_SUCCESS);
    EXPECT_EQ(t_Lnode->data, 2);

    dwRet = dsa_FreeLinkList(t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);


}