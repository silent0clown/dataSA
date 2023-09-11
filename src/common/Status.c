#include "Status.h"

WORD32 itemCompareEqual(int a, int b){
    if(a == b){
        return RET_SUCCESS;
    }
    
    return RET_ERROR;
}