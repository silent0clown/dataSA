#ifndef DEFINE_H
#define DEFINE_H

#ifdef __cplusplus
extern "C" {
#endif

#define CHECK_NULL_RETURN_VALUE(PTR, VAL){if(NULL == PTR){return VAL;}}

#define    RET_ERROR      (-1)
#define    RET_SUCCESS    (0)
#define    RET_OVERFLOW   (9)
#define    RET_PARA_NULL  (10)
#define    RET_PARA_FAIL  (11)

#ifdef __cplusplus
}
#endif


#endif