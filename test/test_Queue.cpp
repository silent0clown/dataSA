#include "gtest/gtest.h"
#include "Status.h"
#include "stackqueue/queue.h"
#include "stackqueue/seqqueue.h"


#define DATA_LENGTH 6

TEST(TestLinkQueue, test_Init_LinkQueue) {
    RET_STATUS dwRet = RET_ERROR;
    LinkQueue q_node;
    dwRet = dsa_InitQueue(&q_node);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    QueueDateType datalist[] = {2023, 9, 18, 16, 48, 30};
    for(int i = 0; i < DATA_LENGTH; i++) {
        dwRet = dsa_InsertQueue(&q_node, datalist[i]);
        EXPECT_EQ(dwRet, RET_SUCCESS);
    }
    dsa_PrintQueue(q_node);
    dwRet =  dsa_GetQueueLength(q_node);
    EXPECT_EQ(dwRet, DATA_LENGTH);

    QueueDateType data = 0;
    dsa_GetQueueHeadData(q_node, &data);
    EXPECT_EQ(data, 2023);

    dsa_DeleteQueue(&q_node, &data);
    dwRet =  dsa_GetQueueLength(q_node);
    EXPECT_EQ(data, 2023);
    EXPECT_EQ(dwRet, DATA_LENGTH - 1);


    dwRet = dsa_FreeQueue(&q_node);
    EXPECT_EQ(dwRet, RET_SUCCESS);
}

TEST(TestLinkQueue, test_Seq_Queue) {
    SEQ_QUEUE_LIST SqList;
    u_int32 dwRet = RET_ERROR;

    dwRet = dsa_InitSeqQueue(&SqList);
    EXPECT_EQ(dwRet, RET_SUCCESS);

    EXPECT_EQ(dsa_IsEmptySeqQueue(SqList), true);

    SeqQueueDataType datalist[] = {2023, 9, 18, 19, 57, 30};
    SeqQueueDataType data = 0;
    for(u_int64 i = 0; i < DATA_LENGTH; i++) {
        dsa_InsertSeqQueueRearData(&SqList, datalist[i]);
        dsa_GetSeqQueueHeadData(SqList, &data);
        dwRet = dsa_GetSeqQueueLength(SqList);
        // EXPECT_EQ(data, datalist[i]);
        EXPECT_EQ(dwRet, i+1);
    }

    for(u_int32 i = 0; i < DATA_LENGTH; i++) {
        dsa_DeleteSeqQueueDataHeadData(&SqList, &data);
        dwRet = dsa_GetSeqQueueLength(SqList);
        EXPECT_EQ(data, datalist[i]);
        EXPECT_EQ(dwRet, DATA_LENGTH - i - 1);
    }

}