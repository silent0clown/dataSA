#include "Status.h"

WORD32 itemCompareEqual(ElemType a, ElemType b){
    if(a == b){
        return RET_SUCCESS;
    }
    
    return RET_ERROR;
}