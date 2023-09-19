#include "string.h"

RET_STATUS Line_Concat(SString* T, SString S1, SString S2) {

    if(S1[0] == MAX_STRING_LEN){
        for(int i = 1; i <= S1[0]; i++) {
            *T[i] = S1[i];
        }
        *T[0] = MAX_STRING_LEN;

    }
    else if (S1[0] + S2[0] <= MAX_STRING_LEN) {
        int total_len = S1[0] + S2[0];
        int i = 1;
        for(; i <= S1[0]; i++) {
            *T[i] = S1[i];
        }
        for(; i <= total_len; i++){
            *T[i] = S2[i - S1[0]];
        }
        *T[0] = S1[0] + S2[0];
        return RET_SUCCESS;
    }
    else {
        *T[0] = MAX_STRING_LEN;
        int i = 1;
        for(; i <= S1[0]; i++) {
            *T[i] = S1[i]; 
        }
        for(; i <= MAX_STRING_LEN; i++){
            *T[i] = S2[i - S1[0]];
        }
    }
    return RET_ERROR;
}

RET_STATUS Line_SubString(SString* Sub, SString S, int pos, int len) {
    if(pos > S[0] || pos + len > S[0] + 1 || pos < 1 || len < 0) {
        return RET_OVERFLOW;
    }

    for(int i = 1; i <= len; i++) {
        *Sub[i] = S[pos + i];
    }
    *Sub[0] = len;

    return RET_SUCCESS;
}




RET_STATUS H_StrAssign(HString* S, const char* string) {
    CHECK_NULL_RETURN_VALUE(string, RET_PARA_NULL);
    CHECK_NULL_RETURN_VALUE(S, RET_PARA_NULL);

    int i = strlen(string);

    if(i == 0) {
        S->ch = NULL;
        S->length = 0;
    
        return RET_SUCCESS;
    }

    S->ch = (char *)malloc(i * sizeof(char));
    if(unlikely(S->ch == NULL)) {
        return RET_OVERFLOW;
    }

    memcpy(S->ch, string, i);

    S->length = i;
    return RET_SUCCESS;
}



// 在串S的第Pos个字符前插入T
RET_STATUS H_StrInsert(HString* S, int pos, HString T) {
    if(pos < 1 || pos > S->length + 1) {
        return RET_PARA_FAIL;
    }
    // T非空,则需重新分配存储空间
    if(T.length){
        // + 1 存储'\0'
        S = (HString*)realloc(S->ch, (S->length + T.length + 1) * sizeof(char));
        if(unlikely(S == NULL)){
            return RET_OVERFLOW;
        }

        for(int i = S->length; i >= pos; i--) {
            S->ch[i + T.length] = S->ch[i];
        }

        for(int i = 0; i < T.length; i++){
            S->ch[pos + i] = T.ch[i];
        }

        S->length += T.length;
        S->ch[S->length] = '\0';
    }

    return RET_SUCCESS;

}

