#include "stdio.h"
#include "Windows.h"
#include "LinearList_Sequence.h"

typedef int (*fun_locateElement)(SequenceList, ElementType);

/**
 * 功能：初始化顺序表，为其分配存储空间
 * 参数：sequenceList 顺序表对象;直接分配一个number个(类型的)空间
 * 返回值：无
*/
Status initListMy(SequenceList &sequenceList, unsigned long long number){
    //分配一个大小为number * 元素所占空间的连续内存空间
    sequenceList.element = (ElementType *) malloc(number * sizeof(ElementType)); 

    //如果分配空间失败那么直接exit
    if(sequenceList.element == NULL){
        printf("malloc error");
        exit(1);
    }

    //当前顺序表长度为number
    sequenceList.length = number;
    //当前顺序表最大可容纳number + MAX_SIZE个元素
    sequenceList.listSize = number + MAX_SIZE;
    //当存储空间不够时的增量
    sequenceList.incrementSize = INCREMENT_SIZE;

    return OK;
}


/**
 * 普通查找
 * 
 * 这个比较常见
*/
int locateElement_1(SequenceList list, ElementType key){
    //顺序查找所有的元素
    //挨个比较，如果匹配的话返回下标
    //如果循环结束都没有找到，那么就是不存在，返回-1
    for(int i = list.length - 1;i >= 0;i--){
        if(key == list.element[i]){
            return i;
        }
    }
    return -1;
}

/**
 * 哨兵查找
 * 
 * 与普通方式查找乍一看没有什么区别，甚至还多了很多代码
 * 但是在面对极大数量的数组时，他的优势就能体现出来
 * 哨兵关键代码只有两句，普通查找有三句关键代码
*/
int locateElement_2(SequenceList list, ElementType key){

    if(key == list.element[0]){
        return 0;
    }

    //将原先下标0的位置取出并保存
    int tempValue = list.element[0];
    list.element[0] = key;

    //从最后一个元素倒着比较
    int index = list.length - 1;
    while(key != list.element[index]){
        index--;
    }

    //将原先下标0的元素复制回去
    list.element[0] = tempValue;

    //返回其真实的下标
    return index == 0 ? -1 : index;
}


/**
 * 也是哨兵查找
 * 但是相对上面的哨兵查找来言
 * 第一个比较直观的特点就是代码量少了很多
 * 第二个比较重要的特点就是其牺牲了第一个存储空间
 * 
 * 还有，不一定非得倒着比较，也可以正着比较
*/
int locateElement_3(SequenceList list, ElementType key){
    list.element[0] = key;

    int index;
    for(index = list.length - 1;list.element[index] != key;--index);

    //返回其真实的下标
    return index;
}


void calculCostTime(const char *methodName, SequenceList list, ElementType key, fun_locateElement operation){
    //获取开始时的时间戳(毫秒)
    double start = GetTickCount();

    /**************开始**************/
    int result = operation(list, key);
    printf("%s index = %d\n", methodName, result);
    /**************结束**************/
    
    //获取结束时的时间戳(毫秒)
    double  end = GetTickCount();

    //打印所花费的时间
    printf("cost time %.0f ms\n\n",end - start);
}

int main(){
    SequenceList list;
    initListMy(list, 1099999999);
    
    for(int i = 0;i < list.length;i++){
        list.element[i] = i * 2 + 2;
    }

    /**
     * 玄学问题。。。
     * locate1 index = 18
     * cost time 1437 ms
     * 
     * locate2 index = 18
     * cost time 1563 ms
     * 
     * locate3 index = 18
     * cost time 1594 ms 
     * **/

    /**************开始**************/
    calculCostTime("locate1", list, 38, &locateElement_1);
    calculCostTime("locate2", list, 38, &locateElement_2);
    calculCostTime("locate3", list, 38, &locateElement_3);
    /**************结束**************/


    return 0;
}