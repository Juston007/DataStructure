#include "stdio.h"
#include "LinearList_Linked.h"

void printAllElement(LinkedList linkedList){
    int returnElement;
    for(int i = 0;i < getLength(linkedList);i++){
        returnElement = -9999999;
        int code = getElement(linkedList,i,returnElement);
        if(code == ERROR){
            printf("ERROR");
            return;
        }
        printf("linkdedList[%d] = %d\n",i,returnElement);
    }
}

int main(){

    //***************Init************************
    LinkedList linkedList;
    initList(linkedList);
    printf("Init linked List OK!\n");

    //***************Init************************
    printf("isEmpty = %d\n",isEmpty(linkedList));

    insertElement(linkedList,0,9);
    insertElement(linkedList,1,8);
    insertElement(linkedList,2,7);
    insertElement(linkedList,3,6);
    insertElement(linkedList,4,5);

    printf("isEmpty = %d length = %d\n",isEmpty(linkedList),getLength(linkedList));

    printAllElement(linkedList);


    /*insertElement OK!
    int resultCode = insertElement(linkedList,6,4);
    printf("insert element[%d] at index[%d]     resultCode = %d\n",4,6,resultCode);
    printAllElement(linkedList);

    resultCode = insertElement(linkedList,0,0);
    printf("insert element[%d] at index[%d]     resultCode = %d\n",0,0,resultCode);
    printAllElement(linkedList);

    resultCode = insertElement(linkedList,-1,-1);
    printf("insert element[%d] at index[%d]     resultCode = %d\n",-1,-1,resultCode);
    printAllElement(linkedList);
    */


    /*
    //findElement OK!
    int returnIndex = findElement(linkedList,9);
    printf("[%d] at index[%d]\n",9,returnIndex);

    returnIndex = -999;
    returnIndex = findElement(linkedList,-1);
    printf("[%d] at index[%d]\n",-1,returnIndex);   

    returnIndex = -999;
    returnIndex = findElement(linkedList,7);
    printf("[%d] at index[%d]\n",7,returnIndex);   
    */

   
   /*
   //NextElement OK!
    int returnElement;
    int resultCode = NextElement(linkedList,0,returnElement);
    printf("index[%d] next element[%d]  resultCode = %d\n",0,returnElement,resultCode);

    resultCode = -999;
    returnElement = -999;
    resultCode = NextElement(linkedList,1,returnElement);
    printf("index[%d] next element[%d]  resultCode = %d\n",1,returnElement,resultCode);

    resultCode = -999;
    returnElement = -999;
    resultCode = NextElement(linkedList,7,returnElement);
    printf("index[%d] next element[%d]  resultCode = %d\n",7,returnElement,resultCode);
    */


   /*PriorElement OK!
    int returnElement;
    int resultCode = PriorElement(linkedList,0,returnElement);
    printf("index[%d] prior element[%d]  resultCode = %d\n",0,returnElement,resultCode);

    resultCode = -999;
    returnElement = -999;
    resultCode = PriorElement(linkedList,3,returnElement);
    printf("index[%d] prior element[%d]  resultCode = %d\n",3,returnElement,resultCode);

    resultCode = -999;
    returnElement = -999;
    resultCode = PriorElement(linkedList,5,returnElement);
    printf("index[%d] prior element[%d]  resultCode = %d\n",5,returnElement,resultCode);
    */

   int resultCode,returnElement;
   resultCode = deleteElement(linkedList,0,returnElement);
   printf("delete element[%d] at index[%d]     resultCode = %d\n",returnElement,0,resultCode);
   printAllElement(linkedList);

   resultCode = deleteElement(linkedList,3,returnElement);
   printf("delete element[%d] at index[%d]     resultCode = %d\n",returnElement,3,resultCode);
   printAllElement(linkedList);

   resultCode = deleteElement(linkedList,-1,returnElement);
   printf("delete element[%d] at index[%d]     resultCode = %d\n",returnElement,-1,resultCode);
   printAllElement(linkedList);

   resultCode = deleteElement(linkedList,3,returnElement);
   printf("delete element[%d] at index[%d]     resultCode = %d\n",returnElement,3,resultCode);
   printAllElement(linkedList);


}