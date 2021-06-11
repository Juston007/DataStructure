#include "stdio.h"
#include "stdlib.h"


//Written by Juston
//2021/03/09 21:08


/**
 * 线性表 (Linear List) 是最常用且最简单的一种数据结构。
 * 线性表是n个数据元素的有限序列
 *
 * 除了第一个元素和最后一个元素 每个元素都有前驱和后继
 * 第一个元素只有后继 最后一个元素只有前驱
 *
 * 数据对象 D = { a(i) | 1 2 3 4 5 }
 * 数据关系 R1 = { <a(i - 1),a(i)> | <1,2>   <2,3>   <3,4>   <4,5> }
*/


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
typedef struct ArrayListStruct{
    ElementType *element;    //起始地址
    int length;              //元素数量
    int listSize;            //分配的存储容量大小
    int incrementSize;       //增量大小
} ArrayList;
/*=====================================结构体=====================================*/





/*=====================================函数声明=====================================*/
Status initList(ArrayList &arrayList);
/**
 * 功能：销毁线性表
 * 参数：arrayList 顺序表对象
 * 返回值：销毁结果 
*/
Status destroyList(ArrayList &arrayList);
/**
 * 功能：清空线性表
 * 参数：arrayList 顺序表对象
 * 返回值：清空结果
*/
Status clearList(ArrayList &arrayList);
Status isEmpty(ArrayList arrayList);
int getLength(ArrayList arrayList);
Status getElement(ArrayList arrayList,int index,ElementType &element);
int  findElement(ArrayList,ElementType element);
Status priorElement(ArrayList arrayList,int index,ElementType &element);
Status nextElement(ArrayList arrayList,int index,ElementType &element);
Status insertElement(ArrayList &arrayList,int index,ElementType element);
Status deleteElement(ArrayList &arrayList,int index,ElementType &element);

/*=====================================函数声明=====================================*/





/*=====================================函数定义=====================================*/

/**
 * 功能：初始化顺序表，为其分配存储空间
 * 参数：arrayList 顺序表对象
 * 返回值：无
*/
Status initList(ArrayList &arrayList){
    //分配一个大小为MAX_SIZE * 元素所占空间的连续内存空间
    arrayList.element = (ElementType *) malloc(MAX_SIZE * sizeof(ElementType)); 

    //如果分配空间失败那么直接exit
    if(arrayList.element == NULL)
        exit(1);

    //当前顺序表长度为0
    arrayList.length = 0;
    //当前顺序表最大可容纳MAX_SIZE个元素
    arrayList.listSize = MAX_SIZE;
    //当存储空间不够时的增量
    arrayList.incrementSize = INCREMENT_SIZE;

    return OK;
}


/**
 * 功能：获取线性表长度
 * 参数：arrayList 顺序表对象
 * 返回值：线性表长度
*/
int getLength(ArrayList arrayList){
    return arrayList.length;
}


/**
 * 功能：线性表是否为空
 * 参数：arrayList 顺序表对象
 * 返回值：是否为空
*/
Status isEmpty(ArrayList arrayList){
    return arrayList.length == 0;
}


/**
 * 功能：获取指定下标的元素
 * 参数：arrayList 顺序表对象 index 下标 element 通过此引用参数返回元素
 * 返回值：成功返回OK 否则返回ERROR
*/
Status getElement(ArrayList arrayList,int index,ElementType &element){
    //如果下标不合法那么直接返回ERROR
    if((index > (arrayList.length - 1)) || (index < 0)){
        return ERROR;
    }else{
        //通过引用参数element返回元素
        element = arrayList.element[index];
        return OK;
    }
}


/**
 * 功能：根据元素找到其下标
 * 参数：arrayList 顺序表对象 elemen要查找的元素
 * 返回值：该元素在顺序表中的下标 找不到返回-1
*/
int  findElement(ArrayList arrayList,ElementType element){
    if(element == NULL)
        return ERROR;

    //从下标为0的元素开始查找
    for (int i = 0;i < arrayList.length;i++){
        //如果找到直接返回下标
        if(arrayList.element[i] == element)
            return i;
    }

    //到最后都没找到 说明没有这个元素 直接返回-1
    return -1;
}


/**
 * 功能：指定下标上元素的前驱
 * 参数：arrayList 顺序表对象 index 下标 element 通过此引用参数返回元素
 * 返回值：成功返回OK 否则返回ERROR
*/
Status priorElement(ArrayList arrayList,int index,ElementType &element){
    //检查index是否合法
    if((index > (arrayList.length - 1)) || (index < 0))
        return OVERFLOW;

    //检查index - 1 是否存在
    if((index - 1 > (arrayList.length - 1)) || (index - 1 < 0))
        return OVERFLOW;

    return getElement(arrayList,index - 1,element);
}


/**
 * 功能：指定下标上元素的后继
 * 参数：arrayList 顺序表对象 index 下标 element 通过此引用参数返回元素
 * 返回值：成功返回OK 否则返回ERROR
*/
Status nextElement(ArrayList arrayList,int index,ElementType &element){
    //检查index是否合法
    if((index > (arrayList.length - 1)) || (index < 0))
        return OVERFLOW;

    //检查index - 1 是否存在
    if((index + 1 > (arrayList.length - 1)) || (index + 1 < 0))
        return OVERFLOW;

    return getElement(arrayList,index + 1,element);
}


/**
 * 功能：向指定位置插入一个元素
 * 参数：arrayList 顺序表对象 index 下标 element 待插入元素
 * 返回值：插入结果
*/
Status insertElement(ArrayList &arrayList,int index,ElementType newElement){
    // 如果要插入的位置小于0 
    // 或者不是最后一个元素之后第一个元素 （例如不能再最后一个元素后两个位置插入元素）
    // 那么就是非法的
    if(index < 0 || (index > arrayList.length)){
        return INFEASIBLE;
    }

    //存储空间已经用完 申请新的内存空间
    if(arrayList.length >= arrayList.listSize){
        //新列表大小 = 旧列表大小 + 增量
        int newListSize = arrayList.listSize + arrayList.incrementSize;
        //重新申请内存空间
        arrayList.element = (ElementType *) realloc(arrayList.element,newListSize * sizeof(ElementType));

        //如果分配失败那么exit
        if(arrayList.element == NULL)
            exit(1);

        arrayList.listSize += arrayList.incrementSize;
    }


    /**
     * 在n个元素的顺序表中，共有n + 1个可以插入的位置
     * 
     * 在位置i插入一个元素时，需要将第n至第i个元素后移一位
     * 共需要移动[n - i + 1]个元素
     * 
     * 从[n + 1]上插入元素共需要移动0[n - (n + 1) + 1]次
     * 从[n]上插入元素共需要移动1[n - (n) + 1]次
     * 从[i]上插入元素共需要移动n - i + 1[n - (i) + 1]次
     * 从[1]上插入元素共需要移动n[n - (1) + 1]次
     * 
     * 平均移动次数 = 总的移动次数 / 可以插入位置的多少种情况
     * 总的移动次数 = [(n + 1)(0 + n)] / 2
     * 
     * 平均移动次数 = [(n + 1)(0 + n)] / 2 / (n + 1)
     * 平均移动次数 = [(n + 1)(0 + n) / 2]  *  [1 / (n + 1)] = n / 2
    */


    //要插入的位置之后 每个元素后移一位
    //必须采用从后开始的方式 从前开始的话元素会被覆盖
    for (int i = arrayList.length - 1;i >= index;i--){
        //arrayList.element[i - 1] = arrayList.element[i];
        arrayList.element[i + 1] = arrayList.element[i];
    }
    /*for (int i = index;i < arrayList.length;i++){
        arrayList.element[i + 1] = arrayList.element[i];
    }*/

    //插入新元素
    arrayList.element[index] = newElement;

    //表长加1
    arrayList.length++;

    return OK;
}


/**
 * 功能：删除指定位置的元素
 * 参数：arrayList 顺序表对象 index 下标 element 待删除元素
 * 返回值：删除结果
*/
Status deleteElement(ArrayList &arrayList,int index,ElementType &element){
    //索引不合法
    if(index < 0 || (index > (arrayList.length - 1))){
        return INFEASIBLE;
    }

    element = arrayList.element[index];

    /**
     * 在n个元素的顺序表中，共有n个可以删除的位置
     * 
     * 在位置i删除一个元素时，需要将第n至第i + 1个元素前移一位
     * 共需要移动[n - i]个元素
     * 
     * 从[n]上删除元素共需要移动0[n - n]次
     * 从[n - 1]上删除元素共需要移动1[n - (n - 1)]次
     * 从[i]上删除元素共需要移动n - i[n - i]次
     * 从[1]上删除元素共需要移动n[n - 1]次
     * 
     * 平均移动次数 = 总的移动次数 / 可以删除位置的多少种情况
     * 总的移动次数 = n[0 + (n - 1)] / 2
     * 
     * 平均移动次数 = n[0 + (n - 1)] / 2 / n
     * 平均移动次数 = [n[0 + (n - 1)] / 2] * [1 / n] = (n - 1) / 2
    */

    //索引index之后的元素全都前移一位
    //必须采用从前开始的方式 从后开始的话元素会被覆盖
    for (int i = index;i < arrayList.length - 1;i++){
        //printf("length = %d , element[%d](%d) = element[%d](%d)\n",arrayList.length - 1,index,arrayList.element[index],index + 1,arrayList.element[index + 1]);
        arrayList.element[i] = arrayList.element[i + 1];
    }

    //表长减1
    arrayList.length--;

    return OK;
}

/*=====================================函数定义=====================================*/