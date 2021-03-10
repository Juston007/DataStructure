#include "stdio.h"
#include "LinearList_Sequence.h"

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
    
    ElementType deleteEl;
    deleteElement(sqList,0,deleteEl);
    printf("delete , index %d is %d\n",0,deleteEl);

    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);

    printf("insert index 0 value 1\n");
    insertElement(sqList, 0, 1);

    for (int i = 0;i < sqList.length;i++)
        printf("read ,sqList[%d] = %d\n",i,sqList.element[i]);

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