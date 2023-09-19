#ifndef DSA_STRING_H
#define DSA_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Status.h"
#include "define.h"
#include <stdlib.h>
#include <string.h>

// 字符串的定长顺序存储表示
#define MAX_STRING_LEN    255
typedef unsigned char     SString[MAX_STRING_LEN + 1];    // 0号单元存放字符串的长度

RET_STATUS Line_Concat(SString* T, SString S1, SString S2);  // T由S1连结S2得到， T = S1 + S2


RET_STATUS Line_SubString(SString* Sub, SString S, int pos, int len);  // 将串S中从第pos个字符开始长度为len的字符复制到Sub中




// 堆分配内存表示,通产采用堆分配方式

typedef struct{
    char *ch;         // 若非空，则按串长度分配存储区，否则为NULL
    int length;       // 串长度
}HString;

// 构造一个值为string的字符串S
RET_STATUS H_StrAssign(HString* S, const char* string);

RET_STATUS H_StrInsert(HString* S, int pos, HString T); // 在串S的第Pos个字符前插入T


// KMP算法，应用在需要多次回溯的字符串匹配











#ifdef __cplusplus
}
#endif
#endif