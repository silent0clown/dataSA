#ifndef DEFINE_H
#define DEFINE_H

#ifdef __cplusplus
extern "C" {
#endif


#pragma GCC system_header   // 允许可变参数宏
#define CHECK_NULL_RETURN_VALUE(PTR, VAL){if(NULL == (PTR)){return VAL;}}
#define  MAX(x,y) (((x)>(y)) ? (x):(y))  
#define  MIN(x,y) (((x)<(y)) ? (x):(y)) 

//
#define INT_EQ(a, b) ((a) == (b))
#define INT_LT(a, b) ((a) < (b))
#define INT_LQ(a, b) ((a) <= (b))

#define CHAR_EQ(a, b) (!strcmp((a), (b)))
#define CHAR_LT(a, b) (strcmp((a), (b)) < 0)
#define CHAR_LQ(a, b) (strcmp((a), (b)) <= 0)

#define    RET_ERROR      (1)
#define    RET_SUCCESS    (0)
#define    RET_OVERFLOW   (9)
#define    RET_PARA_NULL  (10)
#define    RET_PARA_FAIL  (11)
typedef unsigned int  RET_STATUS;

typedef  unsigned char      u_int8;       /* Unsigned 8  bit value */  
typedef  unsigned short     u_int16;      /* Unsigned 16 bit value */  
typedef  unsigned int       u_int32;      /* Unsigned 32 bit value */  
typedef  unsigned long long u_int64;      /* Unsigned 32 bit value */  
typedef  signed char        int8;        /* Signed 8  bit value */  
typedef  signed short       int16;       /* Signed 16 bit value */  
typedef  signed int         int32;       /* Signed 32 bit value */  
typedef  signed long long   int64;       /* Signed 32 bit value */  
  
/* 另外一种写法，同样很方便清晰 */  
  
typedef  unsigned char       BYTE;           /* Unsigned 8  bit value type. */  
typedef  unsigned short      WORD16;         /* Unsinged 16 bit value type. */  
typedef  unsigned int        WORD32;         /* Unsigned 32 bit value type. */  
typedef  unsigned long long  WORD64;         /* Unsigned 64 bit value type. */  

typedef  char                S_BYTE;         /* Signed 8  bit value type. */  
typedef  short               S_WORD16;       /* Singed 16 bit value type. */  
typedef  int                 S_WORD32;       /* Signed 32 bit value type. */ 
typedef  long long           S_WORD64;       /* Signed 64 bit value type. */ 


#define DEBUGMSG_OPEN    1  
  
#define MYLOGO "[DEBUG INFO] "  
  
#define FLAG_FILENAME    0  
#define FLAG_FUNCTION    1  
#define FLAG_LINE        1

 #define likely(x) __builtin_expect(!!(x), 1)
 #define unlikely(x) __builtin_expect(!!(x), 0)

#define DSA_PRINT_MSG(fmt, args...){            \
if(DEBUGMSG_OPEN){                              \
        printf(MYLOGO);                         \
        if(FLAG_FILENAME)                       \
            printf("%s ", __FILE__);            \
        if(FLAG_FILENAME)                       \
            printf("%s ", __FUNCTION__);        \
        if(FLAG_FILENAME)                       \
            printf("%d: ", __LINE__);           \
        printf(fmt, ##args);                    \
        printf("\n");                           \
    }                                           \
}  


#ifdef __cplusplus
}
#endif


#endif