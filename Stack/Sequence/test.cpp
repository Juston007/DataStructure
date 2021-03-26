#include "stdio.h"
#include "Stack_Sequence.h"

int main(){
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

    destoryStack(stack);

}