#include "stdio.h"
#include "Queue_Linked.h"

int main(){

    int returnElement, resCode;

    LinkedQueue queue;
    initQueue(queue);

    printf("is Empty = %d\n",isEmpty(queue));

    enQueue(queue,10);
    resCode = getHead(queue,returnElement);
    printf("getHead [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

    enQueue(queue,20);
    resCode = getHead(queue,returnElement);
    printf("getHead [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

    enQueue(queue,30);
    resCode = getHead(queue,returnElement);
    printf("getHead [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

    resCode = destoryQueue(queue);
    printf("destory Queue code = %d\n",resCode);

    resCode = deQueue(queue,returnElement);
    printf("deQueue [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

    resCode = deQueue(queue,returnElement);
    printf("deQueue [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

    resCode = deQueue(queue,returnElement);
    printf("deQueue [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

    returnElement = -99999;
    resCode = deQueue(queue,returnElement);
    printf("deQueue [%d] resCode [%d] getLength [%d] isEmpty [%d]\n",returnElement, resCode, getLength(queue), isEmpty(queue));

}