#ifndef DSA_TREE_H
#define DSA_TREE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "define.h"
#include "Status.h"

// 二叉树的顺序存储表示
#define MAX_SIZE_SIZE    100                 // 二叉树的最大结点数
typedef char TElemType_Sq;						//假设顺序二叉树元素均为字符 
typedef TElemType_Sq SqBiTree[MAX_SIZE_SIZE];   // 0号单元存储根结点
SqBiTree bt;












#ifdef __cplusplus
}
#endif

#endif