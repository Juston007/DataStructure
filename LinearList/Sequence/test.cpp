#include "stdio.h"
#include "LinearList_Sequence.h"

void printAllElement(SequenceList sequenceList){
    for(int i = 0;i < sequenceList.length;i++){
        printf("index[%d] is value[%d]\n",i,sequenceList.element[i]);
    }
}

//合并两个顺序表
void MergeSequenceList(SequenceList listA,SequenceList listB,SequenceList &listC){
    /*
    ElementType *aElements = listA.element;
    ElementType *bElements = listB.element;

    while((aElements < &(listA.element[listA.length - 1])) && (bElements < &(listB.element[listB.length - 1]))){
        if(aElements > bElements){
            insertElement(listC,listC.length,*aElements);
            aElements++;
        }else{
            insertElement(listC,listC.length,*bElements);
            bElements++;
        }
    }

    if(aElements < &(listA.element[listA.length - 1])){
        for(int i = 0;aElements <= &(listA.element[listA.length - 1]);i++){
            insertElement(listC,listC.length,*aElements);
            aElements++;
        }
    }

    if(bElements < &(listB.element[listB.length - 1])){
        for(int i = 0;bElements <= &(listB.element[listB.length - 1]);i++){
            insertElement(listC,listC.length,*bElements);
            bElements++;
        }
    }*/

    int listALength = listA.length;
    int listBLength = listB.length;

    int i,j,k;
    i = j = k = 0;

    while((i < listALength) && (j < listBLength)){
        int aElement,bElement;
        getElement(listA,i,aElement);
        getElement(listB,j,bElement);

        if(aElement > bElement){
            insertElement(listC,k++,aElement);
            i++;
        }else{
            insertElement(listC,k++,bElement);
            j++;
        }
    }

    while(i < listALength){
        int aElement;
        getElement(listA,i,aElement);
        insertElement(listC,k++,aElement);
        i++;
    }


    while(j < listBLength){
        int bElement;
        getElement(listB,j,bElement);
        insertElement(listC,k++,bElement);
        j++;
    }


}

int main(){
    //定义结构体变量
    SequenceList sqList;

    //初始化顺序表
    initList(sqList);
    printf("sqList init ok!\n");

    //printf("sqList is empty?  %s\n",isEmpty(sqList) == TRUE ? "yes" : "no");

    //插入元素
    insertElement(sqList,0,1);

    //printf("sqList is empty?  %s\n",isEmpty(sqList) == TRUE ? "yes" : "no");

    insertElement(sqList,1,2);
    insertElement(sqList,2,3);
    insertElement(sqList,3,4);
    insertElement(sqList,4,5);
    insertElement(sqList,5,6);
    insertElement(sqList,6,7);
    insertElement(sqList,7,8);
    insertElement(sqList,8,9);
    insertElement(sqList,9,0);

    /*int statusCode = insertElement(sqList,11,0);
    printf("insert index 11 value 0 ,result = %d\n",statusCode);
    statusCode = insertElement(sqList,-1,0);
    printf("insert index -1 value 0 ,result = %d\n",statusCode);*/


    //printf("sqList is empty?  %s\n",isEmpty(sqList) == TRUE ? "yes" : "no");

    //输出元素
    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);


    printf("\n Megre Sequence List \n");

    SequenceList listA,listB,listC;
    initList(listA);
    initList(listB);
    initList(listC);

    printf("\n listA listB listC init OK! \n");

    insertElement(listA,0,3);
    insertElement(listA,1,5);
    insertElement(listA,2,8);
    insertElement(listA,3,11);

    printf("\nprint listA all element\n");
    printAllElement(listA);

    insertElement(listB,0,2);
    insertElement(listB,1,6);
    insertElement(listB,2,8);
    insertElement(listB,3,9);
    insertElement(listB,4,11);
    insertElement(listB,5,15);
    insertElement(listB,6,20);

    printf("\nprint listB all element\n");
    printAllElement(listB);

    MergeSequenceList(listA,listB,listC);
    printf("\n merge print listC all element\n");
    printAllElement(listC);




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
    insertElement(sqList, 0, 1);

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