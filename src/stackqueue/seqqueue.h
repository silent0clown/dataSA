#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

// head file 
#include "define.h"
#include "Status.h"
#include <stdlib.h>

// defination
#define SEQ_QUEUE_MAX_SIZE     100
#define SEQ_QUEUE_NO_FULL_FLAG 0
#define SEQ_QUEUE_FULL_FLAG    1
typedef int SeqQueueDataType;

// data struct
typedef struct {
    SeqQueueDataType* database;

    u_int32 front;          // 头指针
    u_int32 rear;           // 尾指针

}SEQ_QUEUE_LIST;



// function
RET_STATUS dsa_InitSeqQueue(SEQ_QUEUE_LIST* SqList);

RET_STATUS dsa_FreeSeqQueue(SEQ_QUEUE_LIST* SqList);

RET_STATUS dsa_ClearSeqQueue(SEQ_QUEUE_LIST* SqList);

bool dsa_IsEmptySeqQueue(SEQ_QUEUE_LIST SqList);

u_int32 dsa_GetSeqQueueLength(SEQ_QUEUE_LIST SqList);

RET_STATUS dsa_GetSeqQueueHeadData(SEQ_QUEUE_LIST SqList, SeqQueueDataType* data);

RET_STATUS dsa_InsertSeqQueueRearData(SEQ_QUEUE_LIST* SqList, SeqQueueDataType data);

RET_STATUS dsa_DeleteSeqQueueDataHeadData(SEQ_QUEUE_LIST* SqList, SeqQueueDataType* data);

RET_STATUS dsa_PrintSeqQueueData(SEQ_QUEUE_LIST SqList);


#ifdef __cplusplus
}
#endif

#endif