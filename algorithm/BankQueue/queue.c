#include "queue.h"

RET_STATUS dsa_InitQueue(LinkQueue* q_node) {
    QUEUE_NODE* tmp_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
    if(unlikely(tmp_node == NULL)){
        DSA_PRINT_MSG("malloc node fail");
        return RET_OVERFLOW;
    }

    tmp_node->data = 0;
    tmp_node->next = NULL;

    q_node->front = tmp_node;
    q_node->rear = tmp_node;

    return RET_SUCCESS;
}

RET_STATUS dsa_FreeQueue(LinkQueue* q_node) {
    CHECK_NULL_RETURN_VALUE(q_node, RET_PARA_NULL);

    QUEUE_NODE_PTR tmp_node = NULL;
    while(q_node->front != q_node->rear) {
        tmp_node = q_node->front->next;
        free(q_node->front);
        q_node->front = tmp_node;
    }

    free(q_node->front);
    q_node->front = NULL;
    q_node->rear  = NULL;

    return RET_SUCCESS;
}


/* 只保留头结点，其余节点释放掉 */
RET_STATUS dsa_ClearQueue(LinkQueue* q_node) {
    CHECK_NULL_RETURN_VALUE(q_node, RET_PARA_NULL);

    q_node->rear =  q_node->front->next;
    while(q_node->rear) {
        q_node->front->next = q_node->rear->next;
        free(q_node->rear);
        q_node->rear = q_node->front->next;
    }
    q_node->rear  = q_node->front;

    return RET_SUCCESS;
}

bool dsa_IsEmptyQueue(LinkQueue q_node) {
    return q_node.front == q_node.rear ? true : false;
}

u_int32 dsa_GetQueueLength(LinkQueue q_node) {
    QUEUE_NODE_PTR tmp_node = q_node.front;
    u_int32 i = 0;
    while(tmp_node != q_node.rear){
        tmp_node = tmp_node->next;
        i++;
    }
    return i;
}

RET_STATUS dsa_GetQueueHeadData(LinkQueue q_node, QueueDateType* data) {
    CHECK_NULL_RETURN_VALUE(q_node.front, RET_PARA_NULL)
    CHECK_NULL_RETURN_VALUE(q_node.rear, RET_PARA_NULL)

    if(dsa_IsEmptyQueue(q_node)) {
        DSA_PRINT_MSG("This is a empty queue");
        *data = 0;

        return RET_ERROR;
    }

    *data = q_node.front->next->data;

    return RET_SUCCESS;
}

RET_STATUS dsa_InsertQueue(LinkQueue* q_node, QueueDateType data) {
    CHECK_NULL_RETURN_VALUE(q_node, RET_PARA_NULL)
    CHECK_NULL_RETURN_VALUE(q_node->front, RET_PARA_NULL)
    CHECK_NULL_RETURN_VALUE(q_node->rear, RET_PARA_NULL)

    QUEUE_NODE_PTR tmp_node = (QUEUE_NODE_PTR)malloc(sizeof(QUEUE_NODE));
    if(unlikely(tmp_node == NULL)){
        DSA_PRINT_MSG("malloc node fail");
        return RET_OVERFLOW;
    }

    // 插入队列尾部
    tmp_node->data = data;
    tmp_node->next = NULL;
    
    q_node->rear->next = tmp_node;
    q_node->rear = tmp_node;
    return RET_SUCCESS;
}

RET_STATUS dsa_DeleteQueue(LinkQueue* q_node, QueueDateType* data) {
    CHECK_NULL_RETURN_VALUE(q_node, RET_PARA_NULL)
    CHECK_NULL_RETURN_VALUE(q_node->front, RET_PARA_NULL)
    CHECK_NULL_RETURN_VALUE(q_node->rear, RET_PARA_NULL)

    if(dsa_IsEmptyQueue(* q_node)){
        DSA_PRINT_MSG("q node is empty");
        return RET_ERROR;
    }

    QUEUE_NODE_PTR tmp_node = q_node->front->next;
    *data = tmp_node->data;

    q_node->front->next = tmp_node->next;
    free(tmp_node);
    tmp_node = NULL;

    return RET_SUCCESS;
}

RET_STATUS dsa_PrintQueue(LinkQueue q_node) {
    CHECK_NULL_RETURN_VALUE(q_node.front, RET_PARA_NULL);

    if(dsa_IsEmptyQueue(q_node)) {
        DSA_PRINT_MSG("q_node is empty");
        return RET_ERROR;
    }

    QUEUE_NODE_PTR tmp_node = q_node.front->next;

    while(tmp_node) {
        printf(" %d", tmp_node->data);
        tmp_node = tmp_node->next;
    }
    printf("\n");

    return RET_SUCCESS;
}
