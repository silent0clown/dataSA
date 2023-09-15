#include <stdio.h>
#include "sequencelist/SeqList.h"
#include "stackqueue/stack.h"


# define INSERT_LIST_ELEMNUM (5)

void test_InitSeqList()
{
    SeqList SeqList;
    int ret = RET_ERROR;

    printf("[MAIN TEST] Func InitSeqList test begin...\n");

    /* 这边一开始传入指针，导致coredump */
    /* 若要传入指针，需要二级指针且改写函数 */
    ret = InitSeqList(&SeqList);
    if(ret == RET_SUCCESS && SeqList.puiElem != NULL){
        printf("[MAIN TEST] ptr elem is %n\n", SeqList.puiElem);
        printf("[MAIN TEST] ptr total size is %d\n", SeqList.uiTotalNum);
        printf("[MAIN TEST] ptr have elem is %d\n", SeqList.uiStoreNum);
    }
    else{
        printf("[MAIN TEST] malloc ptr fail!\n");
    }

    ret = FreeSeqList(&SeqList);
    if(ret == RET_SUCCESS && SeqList.puiElem == NULL){
        printf("[MAIN TEST] free ptr Succ!\n");
    }
    else{
        printf("[MAIN TEST] free ptr Fail!\n");
    }

}

int main() {
    printf("test");
}

// void SeqStack_NumConvert(int32 i32InputNum, int32 i32Convert) {

//     int32 i32Output = 0;
//     SEQ_STACK seq_stack;
//     u_int32 ui32Ret = dsa_InitSeqStack(&seq_stack);
//     if(ui32Ret != RET_SUCCESS) {
//         DSA_PRINT_MSG("malloc stack fail");
//         return;
//     }

//     while(i32InputNum != 0) {
//         dsa_PushToSeqStack(&seq_stack, i32InputNum % i32Convert);
//         i32InputNum = i32InputNum / i32Convert;
//     }

//     printf("After convert, number is : \n");

//     while(dsa_IsEmptySeqStack(&seq_stack) == false) {
//         dsa_PopFromSeqStack(&seq_stack, &i32Output);
//         printf("%d",i32Output);
//     }
//     printf("\n");

//     return;    
// }

// int main()
// {
//     int input = 0;
//     int convert = 0;
//     printf("Input a number:\n");
//     scanf("%d",&input);
//     printf("Input convert:\n");
//     scanf("%d", &convert);
//     printf("Try to convert %d to as %d\n",input, convert);
//     SeqStack_NumConvert(input, convert);
//     return 0;
// }


// void SeqStack_BracketCheck(const char* buffer, int bufferlen) {
//     const char* p = buffer;
//     SEQ_STACK seq_stack;
//     dsa_InitSeqStack(&seq_stack);
//     char c;
//     for(int i = 0; i< bufferlen; i++) {
//         char getc = *p++;
//         /* '表示字符，"表示字符串 */
//         if(getc == '[' || getc == '(' || getc == '{') {
//             dsa_PushToSeqStack(&seq_stack, getc);
//             continue;
//         }

//         if(getc == ']') {
//             dsa_PopFromSeqStack(&seq_stack, &c);
//             if(c != '[') {
//                 printf("[] Error\n");
//                 break;
//             }
//             continue;
//         }

//         if(getc == ')') {
//             dsa_PopFromSeqStack(&seq_stack, &c);
//             if(c != '(') {
//                 printf("() Error\n");
//                 break;
//             }
//             continue;
//         }

//         if(getc == '}') {
//             dsa_PopFromSeqStack(&seq_stack, &c);
//             if(c != '{') {
//                 printf("{} Error\n");
//                 break;
//             }
//             continue;
//         }
//     }

//     if(!dsa_IsEmptySeqStack(&seq_stack)) {
//         printf("ERROR\n");
//     }

//     printf("Check success\n");
//     return;
// }

// int main(){

//     // char p[50] = {0};
//     // printf("Input a string:\n");
//     // scanf("%s", &p[0]);
//     char p[] = "[boot] name is (value){[abc]}";
//     int len  = strlen(p);
//     printf("Check string :%s, strlen() = %ld\n ", p, strlen(p));
//     SeqStack_BracketCheck(p, len);

//     return 0;
// }

// void SeqStack_LineEdit(const char *buffer) {
//     SEQ_STACK seq_stack;
//     dsa_InitSeqStack(&seq_stack);

//     SEQ_ElemType data;
//     for(const char* p = buffer; *p != '\0'; p++) {
//         if(*p == '#') {
//             if(dsa_IsEmptySeqStack(&seq_stack)) {
//                 printf("can not backspace");
//                 continue;
//             }

//             dsa_PopFromSeqStack(&seq_stack, &data);
//             continue;
//         }
//         if(*p == '@') {
//             while(!dsa_IsEmptySeqStack(&seq_stack)) {
//                 dsa_PopFromSeqStack(&seq_stack, &data);
//                 // printf("%c",data);
//                 if(data == '\n') {
//                     dsa_PushToSeqStack(&seq_stack, data);
//                     break;
//                 }
//             }
//             continue;
//         }

//         dsa_PushToSeqStack(&seq_stack, *p);
//     }

//     dsa_PrintSeqStack(&seq_stack);
    
//     return ;
// }

// int main() {
//     char *p = "whil##ilr#e(s# *s)\noutcha@putchar( *s = ++)";
//     SeqStack_LineEdit(p);
// }




