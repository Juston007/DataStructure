#include "stdio.h"
#include "LinearList_Linked.h"

int main(){

    //***************Init************************
    LinkedList linkedList;
    initList(linkedList);
    printf("Init linked List OK!\n");

    //***************Init************************
    printf("isEmpty = %d\n",isEmpty(linkedList));

    insertElement(linkedList,0,9);
    printf("insert element [%d] at index [%d]     currentLength = %d    isEmpty = %d\n",9,0,getLength(linkedList),isEmpty(linkedList));

    insertElement(linkedList,1,8);
    printf("insert element [%d] at index [%d]     currentLength = %d    isEmpty = %d\n",8,1,getLength(linkedList),isEmpty(linkedList));

    insertElement(linkedList,2,7);
    printf("insert element [%d] at index [%d]     currentLength = %d    isEmpty = %d\n",7,2,getLength(linkedList),isEmpty(linkedList));

    insertElement(linkedList,3,6);
    printf("insert element [%d] at index [%d]     currentLength = %d    isEmpty = %d\n",6,3,getLength(linkedList),isEmpty(linkedList));

    insertElement(linkedList,4,5);
    printf("insert element [%d] at index [%d]     currentLength = %d    isEmpty = %d\n",5,4,getLength(linkedList),isEmpty(linkedList));


    ElementType returnElement;

    deleteElement(linkedList,2,returnElement);
    printf("delete index[%d] value[%d] length = %d\n",2,returnElement,getLength(linkedList));

    getElement(linkedList,2,returnElement);
    printf("at index[%d] is value[%d]\n",2,returnElement);

    printf("value[%d] in index[%d]\n",7,findElement(linkedList,7));

    returnElement = 0;
    PriorElement(linkedList,4,returnElement);
    printf("index[%d] prior element is value[%d]\n",4,returnElement);

    returnElement = 0;
    int code = NextElement(linkedList,4,returnElement);
    printf("code = %d\n",code);
    printf("index[%d] next element is value[%d] code = %d\n",4,returnElement,code);
    
}