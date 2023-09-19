#include "search.h"

int Search_Seq(SSTable ST, KeyType key) {
    // ST.elem[0].key = key;
    int i = ST.length;
    for(; i > 0; i--) {
        if(INT_EQ(ST.elem[i].key, key)) {
            break;
        }
    }

    return i;
}

// 折半查找,只适用于有序表，且限定于顺序存储结构
int Search_Binary(SSTable ST, KeyType key) {
    
    int low_value  = 1;
    int high_value = ST.length;
    int mid_value  = 0;
    while(low_value <= high_value) {
        mid_value = (low_value + high_value)/2;

        if(ST.elem[mid_value].key < key) {
            low_value = mid_value + 1;
        }

        else if(ST.elem[mid_value].key > key) {
            high_value = mid_value - 1;
        }

        if(ST.elem[mid_value].key == key) {
            return mid_value;
        }
    }

    return 0;
}