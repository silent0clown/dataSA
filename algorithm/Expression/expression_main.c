#include "expression_stack.h"

int calualate(const char* expression) {
    
    SEQ_STACK optr;   // 运算符栈
    SEQ_STACK opnd;   // 运算数栈
    dsa_InitSeqStack(&optr);
    dsa_InitSeqStack(&opnd);
    int result = 0;
    while(*expression != '\0'){
        SEQ_ElemType firt_optr;
        firt_optr.optr = '#';
        dsa_PushToSeqStack(&optr, firt_optr);
        char c = *expression;
        printf("%c", c);
        // if (c = ' ') {
        //     expression++;
        //     continue;
        // }

        // if('0' <= c && c <= '9') {
        //     SEQ_ElemType data = {0};
        //     data.number = c;
        //     dsa_PushToSeqStack(&opnd, data);
        // }

        // if(c == '+'||c == '-'||c == '*'||c == '/') {
        //     SEQ_ElemType data = {0};
        //     data.optr = c;
        //     char piror_optr; 
        //     dsa_PopFromSeqStack(&optr, &piror_optr);

        // }
        

        expression++;
    }

    return result;
}



int main() {
    char* expression = "2 + 3 * 6 - 4 / 2";
    calualate(expression);
}