#include "stdio.h"
#include "Stack_Sequence.h"

int main()
{

    int elements[5] = {1, 2, 3, 4, 5};
    int num = 99;
    char ch = 'a';

    int *top = &elements[3];
    int *base = elements;

    printf("top = %d base = %d num = %d ch = %d\n", (int)(top), (int)base,(int)(&num),(int)(&ch));

    //指针与指针做减法运算 相当于 (operation1 - operation1) / sizeof(ElementType)
    printf("top - base = %d\n",(top - base));
    printf("top - num = %d\n",(top - &num));

    //不同类型的指针做运算无法通过编译 也就是只有相同数据类型的指针才能做运算
    //printf("top - ch = %d\n",(top - &ch));

    //指针类型与int类型做加减运算 相当于 (地址) + (i) * sizeof(ElementType)
    printf("top + 1 = %d\n",(top + 1));

    /*
    SequenceStack stack;
    initStack(stack);

    printf("stack init ok!\n\n");

    int returnElement = -999999;

    printf("isEmpty = %d      length = %d\n",isEmpty(stack),getLength(stack));

    Status resStatus = push(stack,1);
    printf("push element 1 status = %d  length = %d\n",resStatus,getLength(stack));
    getTop(stack,returnElement);
    printf("top element = %d\n\n",returnElement);

    resStatus = push(stack,2);
    printf("push element 2 status = %d    length = %d\n",resStatus,getLength(stack));
    getTop(stack,returnElement);
    printf("top element = %d\n\n",returnElement);

    resStatus = pop(stack,returnElement);
    printf("pop element %d status = %d    length = %d\n",returnElement,resStatus,getLength(stack));
    getTop(stack,returnElement);
    printf("top element = %d\n\n",returnElement);

    resStatus = push(stack,3);
    printf("push element 3 status = %d    length = %d\n",resStatus,getLength(stack));
    getTop(stack,returnElement);
    printf("top element = %d\n",returnElement);
    printf("isEmpty = %d\n\n",isEmpty(stack));

    resStatus = push(stack,4);
    printf("push element 4 status = %d    length = %d\n",resStatus,getLength(stack));
    getTop(stack,returnElement);
    printf("top element = %d\n\n",returnElement);

    clearStack(stack);

    destoryStack(stack);*/
}