#include "stdio.h"
#include "LinearList_Sequence_Tree.h"

void printAllElement(SequenceList sequenceList){
    for(int i = 0;i < sequenceList.length;i++){
        printf("index[%d] is value[%x]\n",i,sequenceList.element[i]);
    }
}


int main(){
    /*
    //定义结构体变量
    SequenceList sqList;

    //初始化顺序表
    initList(sqList);
    printf("sqList init ok!\n");

    //printf("sqList is empty?  %s\n",isEmpty(sqList) == TRUE ? "yes" : "no");

    //插入元素
    listInsertElement(sqList,0,1);

    //printf("sqList is empty?  %s\n",isEmpty(sqList) == TRUE ? "yes" : "no");

    listInsertElement(sqList,1,2);
    listInsertElement(sqList,2,3);
    listInsertElement(sqList,3,4);
    listInsertElement(sqList,4,5);
    listInsertElement(sqList,5,6);
    listInsertElement(sqList,6,7);
    listInsertElement(sqList,7,8);
    listInsertElement(sqList,8,9);
    listInsertElement(sqList,9,0);

    /*int statusCode = listInsertElement(sqList,11,0);
    printf("insert index 11 value 0 ,result = %d\n",statusCode);
    statusCode = listInsertElement(sqList,-1,0);
    printf("insert index -1 value 0 ,result = %d\n",statusCode);


    //printf("sqList is empty?  %s\n",isEmpty(sqList) == TRUE ? "yes" : "no");

    //输出元素
    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);


    printf("\nMegre Sequence List \n");*/

    SequenceList listA,listB,listC;
    initList(listA);
    initList(listB);
    initList(listC);

    printf("\nlistA listB listC init OK! \n");

    listInsertElement(listA,0,(void*)0x01f01);
    listInsertElement(listA,1,(void*)0x00102);
    listInsertElement(listA,2,(void*)0x10f3);
    listInsertElement(listA,3,(void*)0x0204);

    printf("\nprint listA all element\n");
    printAllElement(listA);

    listInsertElement(listB,0,(void*)0xffa7);
    listInsertElement(listB,1,(void*)0xfeb8);
    listInsertElement(listB,2,(void*)0xefc9);

    printf("\nprint listB all element\n");
    printAllElement(listB);

    void *ptr;
    int resultCode = getListElement(listA,2,ptr);
    printf("at index[%d] element[%x] resultCode[%d]\n",9,ptr,resultCode);




    /*
    int returnElement,resultCode;

    returnElement = -999;
    resultCode = nextElement(sqList,9,returnElement);
    printf("at index[%d] next element[%d] resultCode[%d]\n",9,returnElement,resultCode);

    returnElement = -999;
    resultCode = nextElement(sqList,8,returnElement);
    printf("at index[%d] next element[%d] resultCode[%d]\n",8,returnElement,resultCode);

    returnElement = -999;
    resultCode = nextElement(sqList,-1,returnElement);
    printf("at index[%d] next element[%d] resultCode[%d]\n",-1,returnElement,resultCode);


    returnElement = -999;
    resultCode = priorElement(sqList,9,returnElement);
    printf("at index[%d] prior element[%d] resultCode[%d]\n",9,returnElement,resultCode);

    returnElement = -999;
    resultCode = priorElement(sqList,8,returnElement);
    printf("at index[%d] prior element[%d] resultCode[%d]\n",8,returnElement,resultCode);

    returnElement = -999;
    resultCode = priorElement(sqList,0,returnElement);
    printf("at index[%d] prior element[%d] resultCode[%d]\n",0,returnElement,resultCode);

    returnElement = -999;
    resultCode = priorElement(sqList,10,returnElement);
    printf("at index[%d] prior element[%d] resultCode[%d]\n",10,returnElement,resultCode);

    returnElement = -999;
    resultCode = priorElement(sqList,1,returnElement);
    printf("at index[%d] prior element[%d] resultCode[%d]\n",1,returnElement,resultCode);
    */
    
    
    /*
    ElementType deleteEl;
    deleteElement(sqList,0,deleteEl);
    printf("delete , index %d is %d\n",0,deleteEl);

    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);

    printf("insert index 0 value 1\n");
    listInsertElement(sqList, 0, 1);

    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);
        */

    /*
    ElementType deleteEl;

    deleteElement(sqList,1,deleteEl);
    printf("delete , index %d is %d\n",1,deleteEl);

    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);

    deleteElement(sqList,2,deleteEl);
    printf("delete , index %d is %d\n",2,deleteEl);

    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);

    printf("sqList length = %d\n",sqList.length);
    */
}