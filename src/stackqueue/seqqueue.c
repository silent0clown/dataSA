#include "seqqueue.h"

RET_STATUS dsa_InitSeqQueue(SEQ_QUEUE_LIST* SqList) {
    SqList->database = (SeqQueueDataType*)malloc(sizeof(SeqQueueDataType) * SEQ_QUEUE_MAX_SIZE);
    if(unlikely(SqList == NULL)) {
        DSA_PRINT_MSG("malloc fail");

        return RET_ERROR;
    }

    SqList->front = 0;
    SqList->rear  = 0;


    return RET_SUCCESS;
}

RET_STATUS dsa_FreeSeqQueue(SEQ_QUEUE_LIST* SqList) {
    CHECK_NULL_RETURN_VALUE(SqList, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(SqList->database, RET_PARA_NULL);

    free(SqList->database);
    SqList->database = NULL;
    SqList->front = 0;
    SqList->rear = 0;

    return RET_SUCCESS;
}

RET_STATUS dsa_ClearSeqQueue(SEQ_QUEUE_LIST* SqList) {
    CHECK_NULL_RETURN_VALUE(SqList, RET_PARA_NULL);

    SqList->front = SqList->rear = 0;
    
    return RET_SUCCESS;
}

bool dsa_IsEmptySeqQueue(SEQ_QUEUE_LIST SqList) {
    return (SqList.rear - SqList.front + SEQ_QUEUE_MAX_SIZE) % SEQ_QUEUE_MAX_SIZE == 0 ? true : false;
}

u_int32 dsa_GetSeqQueueLength(SEQ_QUEUE_LIST SqList) {

    return (SqList.rear - SqList.front + SEQ_QUEUE_MAX_SIZE) % SEQ_QUEUE_MAX_SIZE;
}


RET_STATUS dsa_GetSeqQueueHeadData(SEQ_QUEUE_LIST SqList, SeqQueueDataType* data) {
    CHECK_NULL_RETURN_VALUE(data, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(SqList.database, RET_PARA_NULL);

    if(dsa_IsEmptySeqQueue(SqList)){
        DSA_PRINT_MSG("this is a empty queue");
        return RET_ERROR;
    }

    *data = SqList.database[SqList.front];

    return RET_SUCCESS;
}

RET_STATUS dsa_InsertSeqQueueRearData(SEQ_QUEUE_LIST* SqList, SeqQueueDataType data) {
    CHECK_NULL_RETURN_VALUE(SqList, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(SqList->database, RET_PARA_NULL);

    // 依靠 % 取余实现循环
    if((SqList->rear + 1) % SEQ_QUEUE_MAX_SIZE == SqList->front) {
        DSA_PRINT_MSG("Queue is full");

        return RET_ERROR;
    }

    SqList->database[SqList->rear] = data;
    SqList->rear = (SqList->rear + 1) % SEQ_QUEUE_MAX_SIZE;

    return RET_SUCCESS;
}

RET_STATUS dsa_DeleteSeqQueueDataHeadData(SEQ_QUEUE_LIST* SqList, SeqQueueDataType* data) {
    CHECK_NULL_RETURN_VALUE(SqList, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(SqList->database, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(data, RET_PARA_NULL);

    if(SqList->rear == SqList->front) {
        DSA_PRINT_MSG("this is a empty queue");

        return RET_ERROR;
    }

    *data = SqList->database[SqList->front];
    // 头指针前进
    SqList->front = (SqList->front + 1) % SEQ_QUEUE_MAX_SIZE;

    return RET_SUCCESS;
}

RET_STATUS dsa_PrintSeqQueueData(SEQ_QUEUE_LIST SqList) {
    CHECK_NULL_RETURN_VALUE(SqList.database, RET_PARA_NULL);

    for(u_int32 i = SqList.front; i < SqList.rear; i++) {
        printf(" %d ", SqList.database[i]);
    }
    printf("\n");

    return RET_SUCCESS;
}