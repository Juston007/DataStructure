#include "stdio.h"
#include "stdlib.h"


//Written by Juston
//2021/03/09 21:08


/**
 * fix bug
 * Date     2021/03/15 16:31
 * fix nextElement priorElement
 * */



/*=====================================宏定义=====================================*/
#define Status       int

#define OK           2

#define TRUE         1
#define FALSE        0

#define ERROR       -3
#define INFEASIBLE  -2
#define OVERFLOW    -1

#define MAX_SIZE     1024

#define ElementType int

#define INCREMENT_SIZE 100
/*=====================================宏定义=====================================*/






/*=====================================结构体=====================================*/
typedef struct SequenceListStruct{
    ElementType *element;    //起始地址
    int length;              //元素数量
    int listSize;            //分配的存储容量大小
    int incrementSize;       //增量大小
} SequenceList;
/*=====================================结构体=====================================*/





/*=====================================函数声明=====================================*/
Status initList(SequenceList &sequenceList);
/**
 * 功能：销毁线性表
 * 参数：sequenceList 顺序表对象
 * 返回值：销毁结果 
*/
Status destroyList(SequenceList &sequenceList);
/**
 * 功能：清空线性表
 * 参数：sequenceList 顺序表对象
 * 返回值：清空结果
*/
Status clearList(SequenceList &sequenceList);
Status isEmpty(SequenceList sequenceList);
int getLength(SequenceList sequenceList);
Status getElement(SequenceList sequenceList,int index,ElementType &element);
int  findElement(SequenceList,ElementType element);
Status priorElement(SequenceList sequenceList,int index,ElementType &element);
Status nextElement(SequenceList sequenceList,int index,ElementType &element);
Status insertElement(SequenceList &sequenceList,int index,ElementType element);
Status deleteElement(SequenceList &sequenceList,int index,ElementType &element);

/*=====================================函数声明=====================================*/





/*=====================================函数定义=====================================*/

/**
 * 功能：初始化顺序表，为其分配存储空间
 * 参数：sequenceList 顺序表对象
 * 返回值：无
*/
Status initList(SequenceList &sequenceList){
    //分配一个大小为MAX_SIZE * 元素所占空间的连续内存空间
    sequenceList.element = (ElementType *) malloc(MAX_SIZE * sizeof(ElementType)); 

    //如果分配空间失败那么直接exit
    if(sequenceList.element == NULL)
        exit(1);

    //当前顺序表长度为0
    sequenceList.length = 0;
    //当前顺序表最大可容纳MAX_SIZE个元素
    sequenceList.listSize = MAX_SIZE;
    //当存储空间不够时的增量
    sequenceList.incrementSize = INCREMENT_SIZE;

    return OK;
}


/**
 * 功能：获取线性表长度
 * 参数：sequenceList 顺序表对象
 * 返回值：线性表长度
*/
int getLength(SequenceList sequenceList){
    return sequenceList.length;
}


/**
 * 功能：线性表是否为空
 * 参数：sequenceList 顺序表对象
 * 返回值：是否为空
*/
Status isEmpty(SequenceList sequenceList){
    return sequenceList.length == 0;
}


/**
 * 功能：获取指定下标的元素
 * 参数：sequenceList 顺序表对象 index 下标 element 通过此引用参数返回元素
 * 返回值：成功返回OK 否则返回ERROR
*/
Status getElement(SequenceList sequenceList,int index,ElementType &element){
    //如果下标不合法那么直接返回ERROR
    if((index > (sequenceList.length - 1)) || (index < 0)){
        return ERROR;
    }else{
        //通过引用参数element返回元素
        element = sequenceList.element[index];
        return OK;
    }
}


/**
 * 功能：根据元素找到其下标
 * 参数：sequenceList 顺序表对象 elemen要查找的元素
 * 返回值：该元素在顺序表中的下标 找不到返回-1
*/
int  findElement(SequenceList sequenceList,ElementType element){
    if(element == NULL)
        return ERROR;

    //从下标为0的元素开始查找
    for (int i = 0;i < sequenceList.length;i++){
        //如果找到直接返回下标
        if(sequenceList.element[i] == element)
            return i;
    }

    //到最后都没找到 说明没有这个元素 直接返回-1
    return -1;
}


/**
 * 功能：指定下标上元素的前驱
 * 参数：sequenceList 顺序表对象 index 下标 element 通过此引用参数返回元素
 * 返回值：成功返回OK 否则返回ERROR
*/
Status priorElement(SequenceList sequenceList,int index,ElementType &element){
    //检查index是否合法
    if((index > (sequenceList.length - 1)) || (index < 0))
        return OVERFLOW;

    //检查index - 1 是否存在
    if((index - 1 > (sequenceList.length - 1)) || (index - 1 < 0))
        return OVERFLOW;

    return getElement(sequenceList,index - 1,element);
}


/**
 * 功能：指定下标上元素的后继
 * 参数：sequenceList 顺序表对象 index 下标 element 通过此引用参数返回元素
 * 返回值：成功返回OK 否则返回ERROR
*/
Status nextElement(SequenceList sequenceList,int index,ElementType &element){
    //检查index是否合法
    if((index > (sequenceList.length - 1)) || (index < 0))
        return OVERFLOW;

    //检查index - 1 是否存在
    if((index + 1 > (sequenceList.length - 1)) || (index + 1 < 0))
        return OVERFLOW;

    return getElement(sequenceList,index + 1,element);
}


/**
 * 功能：向指定位置插入一个元素
 * 参数：sequenceList 顺序表对象 index 下标 element 待插入元素
 * 返回值：插入结果
*/
Status insertElement(SequenceList &sequenceList,int index,ElementType newElement){
    // 如果要插入的位置小于0 
    // 或者不是最后一个元素之后第一个元素 （例如不能再最后一个元素后两个位置插入元素）
    // 那么就是非法的
    if(index < 0 || (index > sequenceList.length)){
        return INFEASIBLE;
    }

    //存储空间已经用完 申请新的内存空间
    if(sequenceList.length >= sequenceList.listSize){
        //新列表大小 = 旧列表大小 + 增量
        int newListSize = sequenceList.listSize + sequenceList.incrementSize;
        //重新申请内存空间
        sequenceList.element = (ElementType *) realloc(sequenceList.element,newListSize * sizeof(ElementType));

        //如果分配失败那么exit
        if(sequenceList.element == NULL)
            exit(1);

        sequenceList.listSize += sequenceList.incrementSize;
    }

    //要插入的位置之后 每个元素后移一位
    //必须采用从后开始的方式 从前开始的话元素会被覆盖
    for (int i = sequenceList.length - 1;i >= index;i--){
        //sequenceList.element[i - 1] = sequenceList.element[i];
        sequenceList.element[i + 1] = sequenceList.element[i];
    }
    /*for (int i = index;i < sequenceList.length;i++){
        sequenceList.element[i + 1] = sequenceList.element[i];
    }*/

    //插入新元素
    sequenceList.element[index] = newElement;

    //表长加1
    sequenceList.length++;

    return OK;
}


/**
 * 功能：删除指定位置的元素
 * 参数：sequenceList 顺序表对象 index 下标 element 待删除元素
 * 返回值：删除结果
*/
Status deleteElement(SequenceList &sequenceList,int index,ElementType &element){
    //索引不合法
    if(index < 0 || (index > (sequenceList.length - 1))){
        return INFEASIBLE;
    }

    element = sequenceList.element[index];

    //索引index之后的元素全都前移一位
    //必须采用从前开始的方式 从后开始的话元素会被覆盖
    for (int i = index;i < sequenceList.length - 1;i++){
        //printf("length = %d , element[%d](%d) = element[%d](%d)\n",sequenceList.length - 1,index,sequenceList.element[index],index + 1,sequenceList.element[index + 1]);
        sequenceList.element[i] = sequenceList.element[i + 1];
    }

    //表长减1
    sequenceList.length--;

    return OK;
}

/*=====================================函数定义=====================================*/