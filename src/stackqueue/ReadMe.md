# 栈
## 一、定义
**栈**是限定仅在表尾进行插入或删除操作的线性表，表尾端称为**栈顶(top)**，表头端称为**栈底(bottom)**。不含元素的空表称为**空栈**。

栈是典型的**后进先出(LIFO)**(last in first out)结构。

---

## 二、实现
数据结构：
```c
typedef struct SqStack {
    SElemType* base;  /* 栈底 */
    SElemType* top;   /* 栈顶 */ 
    int  stacksize;   /* 最大容量 */
}
```
![Alt text](image.png)

## 三、应用
1. 数制转换
2. 括号匹配的校验
3. 行编辑程序
4. 迷宫求解
5. 表达式求值
6. 实现递归
   1. Hanoi塔
   2. 斐波那契数列
   3. 阶乘函数
   4. Ackerman函数