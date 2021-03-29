#include "stdio.h"
#include "stdlib.h"


//Written by Juston
//2021/03/26 20:14


/*=====================================宏定义=====================================*/
#define Status       int

#define OK           2

#define TRUE         1
#define FALSE        0

#define ERROR       -3
#define INFEASIBLE  -2
#define OVERFLOW    -1

#define STACK_INIT_SIZE     10      //栈初始大小
#define STACK_INCREMENT     10      //栈大小增量


#define ElementType int
/*=====================================宏定义=====================================*/


/*=====================================结构体=====================================*/
typedef struct SequenceStatckStruck{
    ElementType *base;      //栈底指针  指向栈底的元素
    ElementType *top;       //栈顶指针  指向栈顶的元素
    int stackSize;          //栈大小
}SequenceStack;
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
Status initStack(SequenceStack &stack);
Status destoryStack(SequenceStack &stack);
Status clearStack(SequenceStack &stack);
Status isEmpty(SequenceStack stack);
int getLength(SequenceStack stack);
Status getTop(SequenceStack stack,ElementType &returnElement);
Status push(SequenceStack &stack,ElementType element);
Status pop(SequenceStack &stack,ElementType &returnElement);
Status traverseStack(SequenceStack &stack,Status (*visit)());
/*=====================================函数声明=====================================*/


/*=====================================函数定义=====================================*/

/**
 * 功能：初始化顺序栈
 * 参数：stack 被初始化的栈
 * 返回值：初始化结果
*/
Status initStack(SequenceStack &stack){

    //如果stack为NULL那么后面都无法操作了
    if(&stack == NULL)
        return ERROR;

    //构造一片连续的内存空间用于存储栈的元素
    //大小为 STACK_INIT_SIZE * sizeof(ElementType)
    ElementType *elements = (ElementType *)malloc(STACK_INIT_SIZE * sizeof(ElementType));

    if(elements == NULL)
        exit(OVERFLOW);

    //栈顶 栈底都指向新申请的内存空间
    stack.base = stack.top = elements;
    
    //设置栈的初始长度
    stack.stackSize = STACK_INIT_SIZE;

    return TRUE;
}

/**
 * 功能：销毁顺序栈
 * 参数：stack 被销毁的栈
 * 返回值：销毁
*/
Status destoryStack(SequenceStack &stack){

    if(&stack == NULL)
        return ERROR;

    if(stack.base != NULL)
        free(stack.base);
    
    free(&stack);

    return TRUE;
}

/**
 * 功能：清空顺序栈
 * 参数：stack 被清空的栈
 * 返回值：清空结果
*/
Status clearStack(SequenceStack &stack){
    if(&stack == NULL)
        return ERROR;

    int length = getLength(stack);
    for(int i = 0;i < length;i++){
        ElementType returnValue;
        Status resCode = pop(stack,returnValue);
        printf("i = %d  resCode = %d returnValue = %d\n",i,resCode,returnValue);
    }

    return TRUE;
}

/**
 * 功能：栈是否为空
 * 参数：stack 栈
 * 返回值：TRUE 栈为空 FALSE 栈不为空
*/
Status isEmpty(SequenceStack stack){
    if(&stack == NULL)
        return ERROR;

    return stack.base == stack.top;
}

/**
 * 功能：获取长度
 * 参数：stack 栈
 * 返回值：栈的长度
*/
int getLength(SequenceStack stack){
    if(&stack == NULL)
        return ERROR;

    return (stack.top - stack.base);
}

/**
 * 功能：获取栈顶元素但不弹出
 * 参数：stack 栈 returnElement 通过此参数返回栈顶元素
 * 返回值：获取结果
*/
Status getTop(SequenceStack stack,ElementType &returnElement){
    if(&stack == NULL)
        return ERROR;

    if(isEmpty(stack)){
        return FALSE;
    }
    else{
        returnElement = *(stack.top - 1);
        return TRUE;
    }
}

/**
 * 功能：向栈顶压入一个元素
 * 参数：stack 栈 element 要压入的元素
 * 返回值：压入结果
*/
Status push(SequenceStack &stack,ElementType element){
    if(&stack == NULL)
        return ERROR;

    //如果栈已经满了 那么需要申请新的内存空间
    if(stack.stackSize <= (stack.top - stack.base)){
        //重新申请一个新的内存空间
        //新内存空间的大小为 (原来的大小 + 增量) * 一个元素的大小
        int newSize = (stack.stackSize + STACK_INCREMENT) * sizeof(ElementType);
        stack.base = (ElementType *)realloc(stack.base,newSize);
        
        if(stack.base == NULL)
            exit(OVERFLOW);
        
        //新的栈顶
        stack.top = stack.base + stack.stackSize;
        stack.stackSize += STACK_INCREMENT;
    }

    *(stack.top++) = element;

    return TRUE;
}

/**
 * 功能：弹出一个元素
 * 参数：stack 栈 returnElement 通过此参数返回弹出的栈顶元素
 * 返回值：弹出结果
*/
Status pop(SequenceStack &stack,ElementType &returnElement){
    if(&stack == NULL)
        return ERROR;

        
    if(isEmpty(stack))
        return FALSE;

    returnElement = *(--stack.top);
    return TRUE;
}

/**
 * 功能：遍历栈
 * 参数：stack 被初始化的栈对象 visit 指针函数
 * 返回值：遍历结果
*/
Status traverseStack(SequenceStack &stack,Status (*visit)());
/*=====================================函数定义=====================================*/