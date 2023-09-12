#include "gtest/gtest.h"
#include "Status.h"
#include "linerlinklist/LineLinklist.h"

TEST(TestSingleLinkList, test_Init_LinkList) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    dwRet = dsa_FreeLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}

TEST(TestSingleLinkList, test_InsertLinkList) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    bool bret = dsa_IsEmptyLinkList(t_Lnode);
    EXPECT_EQ(bret, true);

    ElemType sdwInsertLiist[] = {2023, 9, 12, 10, 13, 14};
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertLinkList(t_Lnode, i+1, sdwInsertLiist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    
    dwRet = dsa_GetLinkListLength(t_Lnode);
    EXPECT_EQ(dwRet, sizeof(sdwInsertLiist)/sizeof(ElemType));

    LNode* tmp = t_Lnode->next;
    ElemType data = 0;
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) { 
        EXPECT_EQ(tmp->data, sdwInsertLiist[i]);
        dwRet = dsa_GetLinkListElme(t_Lnode, i+1, &data);
        printf("elem[%u] is %d\n", i, data);
        EXPECT_EQ(data, sdwInsertLiist[i]);

        tmp = tmp->next;
    }

    bret = dsa_IsEmptyLinkList(t_Lnode);
    EXPECT_EQ(bret, false);

    dwRet = dsa_ClearLinkList(t_Lnode);
    bret = dsa_IsEmptyLinkList(t_Lnode);
    EXPECT_EQ(bret, true);

    dwRet = dsa_FreeLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}


TEST(TestSingleLinkList, test_InsertLinkList_Head) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    bool bret = dsa_IsEmptyLinkList(t_Lnode);
    EXPECT_EQ(bret, true);

    ElemType sdwInsertLiist[] = {2023, 9, 12, 10, 13, 14};
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertList_Head(&t_Lnode, sdwInsertLiist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    
    dwRet = dsa_GetLinkListLength(t_Lnode);
    EXPECT_EQ(dwRet, sizeof(sdwInsertLiist)/sizeof(ElemType));

    ElemType data = 0;
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) { 
       
        dwRet = dsa_GetLinkListElme(t_Lnode, i+1, &data);
        printf("elem[%u] is %d\n", i, data);
        EXPECT_EQ(data, sdwInsertLiist[sizeof(sdwInsertLiist)/sizeof(ElemType) - i - 1]);
    }

    dwRet = dsa_FreeLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}

TEST(TestSingleLinkList, test_InsertLinkList_End) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    bool bret = dsa_IsEmptyLinkList(t_Lnode);
    EXPECT_EQ(bret, true);

    ElemType sdwInsertLiist[] = {2023, 9, 12, 10, 13, 14};
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertList_End(&t_Lnode, sdwInsertLiist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    
    dwRet = dsa_GetLinkListLength(t_Lnode);
    EXPECT_EQ(dwRet, sizeof(sdwInsertLiist)/sizeof(ElemType));

    ElemType data = 0;
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) { 
       
        dwRet = dsa_GetLinkListElme(t_Lnode, i+1, &data);
        printf("elem[%u] is %d\n", i, data);
        EXPECT_EQ(data, sdwInsertLiist[i]);
    }

    dwRet = dsa_FreeLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}


TEST(TestSingleLinkList, test_SortLinkList) {
    LNode* t_Lnode = NULL;
    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    bool bret = dsa_IsEmptyLinkList(t_Lnode);
    EXPECT_EQ(bret, true);

    ElemType sdwInsertLiist[] = {2023, 9, 12, 10, 13, 14};
    ElemType sdwSortLiist[] = {9, 10, 12, 13, 14, 2023};
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertList_End(&t_Lnode, sdwInsertLiist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    
    dwRet = dsa_GetLinkListLength(t_Lnode);
    EXPECT_EQ(dwRet, sizeof(sdwInsertLiist)/sizeof(ElemType));

    dwRet = dsa_SortLinkList(t_Lnode, SORT_INCREASING_FLAG);

    ElemType data = 0;
    for(WORD32 i = 0; i < sizeof(sdwInsertLiist)/sizeof(ElemType); i++) {        
        dwRet = dsa_GetLinkListElme(t_Lnode, i+1, &data);
        printf("elem[%u] is %d\n", i, data);
        EXPECT_EQ(data, sdwSortLiist[i]);
    }


    dwRet = dsa_FreeLinkList(&t_Lnode);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}

TEST(TestSingleLinkList, test_MergeLinkList) {
    LNode* t_Lnode = NULL;
    LNode* t_Lnode2 = NULL;
    LNode* t_Lnode3 = NULL;

    WORD32 dwRet = RET_ERROR;
    dwRet = dsa_InitLinkList(&t_Lnode);
    dwRet = dsa_InitLinkList(&t_Lnode2);
    dwRet = dsa_InitLinkList(&t_Lnode3);


    ElemType sdwInsertList[] = {2023, 9, 12, 10, 13, 14};
    ElemType sdwInsertList2[] = {2023, 9, 12, 15, 43, 47};
    for(WORD32 i = 0; i < sizeof(sdwInsertList)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertList_End(&t_Lnode, sdwInsertList[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }

    for(WORD32 i = 0; i < sizeof(sdwInsertList2)/sizeof(ElemType); i++) {
        dwRet = dsa_InsertList_End(&t_Lnode2, sdwInsertList2[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    
    dwRet = dsa_SortLinkList(t_Lnode, SORT_INCREASING_FLAG);
    dwRet = dsa_SortLinkList(t_Lnode2, SORT_INCREASING_FLAG);

    dwRet = dsa_MergeLinkList(t_Lnode, t_Lnode2, t_Lnode3);

    LNode* p = t_Lnode3;
    while(p) {
        printf("Merge elem is %d\n", p->data);
        p = p->next;
    }

    dwRet = dsa_FreeLinkList(&t_Lnode3);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}