#include "array.h"


/* 初始化维数为dim的素组，可变参数指示各维度大小 */
RET_STATUS dsa_InitArray(Array* array, int dim, ...) {
    int total_elem;
    va_list ap;         // ap存放可变参数表信息，指示各维度大小
    int i;

    CHECK_NULL_RETURN_VALUE(array, RET_PARA_NULL);

    if(dim < 1 || dim > MAX_ARRAY_DIM) {
        return RET_ERROR;
    }

    // 初始化数组维度
    array->dim = dim;

    // 初始化数组维度信息表
    array->bounds = (int*)malloc(dim * sizeof(int));
    if(unlikely(array->bounds == NULL)){
        return RET_OVERFLOW;
    }

    total_elem = 1;

    // 使ap指向第一个可变参数, dim相当于起始标识
    va_start(ap, dim);

    for(i = 0; i < dim; i++) {
        // 记录当前维度的宽度
        array->bounds[i] = va_arg(ap, int);
        if(array->bounds[i] < 0) {
            return RET_ERROR;
        }
        total_elem *= array->bounds[i];
    }

    // 置空ap
    va_end(ap);
    // 初始化数组空间，以存放元素
    array->base = (ElemType*)malloc(total_elem * sizeof(ElemType));
    if(array->base == NULL) {
        return RET_ERROR;
    }

    // 初始化数组映像函数常量信息表
    array->constants = (int*)malloc(dim * sizeof(int));
    if(unlikely(array->constants == NULL)) {
        return RET_ERROR;
    }

    // 遍历最后一个维度，每次总是需要跨越一个元素
    array->constants[dim - 1] = 1;
    for(i = dim -2; i >= 0; i--) {
        array->constants[i] = array->bounds[i + 1] * array->constants[i + 1];
    }

    /*
     * 举例：
     * 对于三维数组[2,3,4]来说，bounds的值为<2,3,4>，constants的值为<12,4,1>
     * 分析bounds，第一维中包含2个元素，第二维中包含3个元素，第三维中包含4个元素
     * 分析constants，遍历第一维，每次需要跨过12个元素，遍历第二维，每次需要跨越4个元素，遍历第三维，每次需要跨越1个元素
     */

    return RET_SUCCESS;
}