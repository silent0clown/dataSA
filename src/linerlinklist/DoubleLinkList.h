/* 双向循环链表 */
#ifndef DOUBLE_LINKLIST_H
#define DOUBLE_LINKLIST_H

#ifdef __cplusplus
extern "C" {
#endif

/* head file   */
#include "define.h"
#include <stdlib.h>
#include <string.h>


/* defination  */
typedef S_WORD32 ElemType;

/* data struct */
/* struct后不跟DulNode会有边意思告警 */
typedef struct DuLNode{
    ElemType data;
    struct DuLNode* piror_node;
    struct DuLNode* next_node;
}DuLNode, *DulLinkList;

/* function    */

/* 表创建 */
RET_STATUS dsa_InitDulLinklist(DuLNode** DL_node);

/* 表删除 */
RET_STATUS dsa_FreeDulLinklist(DuLNode** DL_node);

/* 表插入元素 */
RET_STATUS dsa_InsertDulLinklist(DuLNode** DL_node, WORD32 dwLocation, ElemType data);

/* 表删除元素 */
RET_STATUS dsa_DeleteDulListElem(DuLNode** DL_node, WORD32 dwLocation, ElemType* data);

/* 表查询元素 */
RET_STATUS dsa_GetDulListElme(DuLNode* DL_node, WORD32 dwLocation, ElemType* data);

/* 查询元素位置 */
RET_STATUS dsa_GetElemLocation(const DuLNode* const DL_node, const ElemType data, WORD32* dwLocate);


#ifdef __cplusplus
}
#endif

#endif