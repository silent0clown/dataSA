#ifndef DSA_SEARCH_H
#define DSA_SEARCH_H

#ifdef __cplusplus
extern "C" {
#endif

// typedef float KeyType;
typedef int   KeyType;
// typedef char  KeyType;
typedef char  ElemType;
typedef struct {
    KeyType key;
    float   weight;
}Search_ElemType;


// 顺序表的查找
typedef struct 
{
    /* data */
    Search_ElemType* elem;
    int length;
}SSTable;

// 在顺序表ST中顺序查找其关键字等于Key的数据元素，若找到，则函数值为
// 该元素在表中的位置，否则为0
int Search_Seq(SSTable ST, KeyType key);


#ifdef __cplusplus
}
#endif

#endif