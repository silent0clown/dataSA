#include "stack.h"

RET_STATUS dsa_InitSeqStack(SEQ_STACK* seq_node) {
   seq_node->ptBase = (SEQ_ElemType*)malloc(sizeof(SEQ_ElemType) * STACK_INIT_SIZE);

    if(unlikely(seq_node->ptBase == NULL)) {
        DSA_PRINT_MSG("malloc node fail");

        return RET_OVERFLOW;
    }

    seq_node->dwStackSize = STACK_INIT_SIZE;
    seq_node->ptTop       = seq_node->ptBase;

    return RET_SUCCESS;
}

RET_STATUS dsa_FreeSeqStack(SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    free(seq_node->ptBase);
    seq_node->ptBase = NULL;
    seq_node->ptTop  = NULL;
    seq_node->dwStackSize = 0;

    return RET_SUCCESS;
}

RET_STATUS dsa_ClearSeqStack(SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    memset(seq_node->ptBase, 0, seq_node->dwStackSize);
    seq_node->ptTop = seq_node->ptBase;

    return RET_SUCCESS;
}

bool dsa_IsEmptySeqStack(const SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, false);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, false);

    return seq_node->ptBase == seq_node->ptTop ? true : false;
}
 
WORD32 dsa_GetSeqStackLen(const SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, 0);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, 0);

    return seq_node->ptTop - seq_node->ptBase;
}

RET_STATUS dsa_GetSeqStackTopElem(const SEQ_STACK* seq_node, SEQ_ElemType* data) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    *data = *(seq_node->ptTop - 1);

    return RET_SUCCESS;
}

RET_STATUS dsa_PushToSeqStack(SEQ_STACK* seq_node, SEQ_ElemType data) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    /* 推入过多 */
    if(seq_node->ptTop - seq_node->ptBase >= seq_node->dwStackSize) {
        seq_node->ptBase = (SEQ_ElemType *)realloc(seq_node->ptBase, (seq_node->dwStackSize + STACK_INCREMENT_SIZE) * sizeof(SEQ_ElemType));
        if(unlikely(seq_node->ptBase == NULL)) {
            DSA_PRINT_MSG("realloc node fail");
            return RET_ERROR;
        }

        seq_node->dwStackSize += STACK_INCREMENT_SIZE;
        seq_node->ptTop = seq_node->ptBase + seq_node->dwStackSize;
    }

    *seq_node->ptTop = data;
    seq_node->ptTop ++;

    return RET_SUCCESS;
}

RET_STATUS dsa_PopFromSeqStack(SEQ_STACK* seq_node, SEQ_ElemType* data) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    /* 考虑空栈 */
    if(seq_node->ptBase == seq_node->ptTop) {
        DSA_PRINT_MSG("Stack is empty");

        return RET_ERROR;
    }

    seq_node->ptTop--;
    *data = *seq_node->ptTop;
    *seq_node->ptTop = 0;

    return RET_SUCCESS;
}

RET_STATUS dsa_PrintSeqStack(const SEQ_STACK* seq_node) {
    CHECK_NULL_RETURN_VALUE(seq_node, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(seq_node->ptBase, RET_PARA_NULL);

    SEQ_ElemType* tmp_node = seq_node->ptBase;
    
    if(tmp_node == seq_node->ptTop) {
        DSA_PRINT_MSG("Stack is empty")
        return RET_PARA_FAIL;
    }
    printf("Stack elem is : ");
    while(tmp_node != seq_node->ptTop) {
        printf("%c", *tmp_node);
        tmp_node++;
    }
    printf("\n");

    return RET_SUCCESS;
}




