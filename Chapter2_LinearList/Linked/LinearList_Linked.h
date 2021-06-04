 #include "stdio.h"
 #include "stdlib.h"


//Written by Juston
//2021/03/14 18:48

/**
 * update comment
 * 2021/03/29 16:27
*/



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
/*=====================================宏定义=====================================*/

typedef struct LinkedListStruct{
    ElementType data;                   //数据
    struct LinkedListStruct *next;      //下一个元素
} *LinkedList,LinkedNode;



/*=====================================函数声明=====================================*/
Status initList(LinkedList &linkedList);
Status destroyList(LinkedList &linkedList);
/**
 * 功能：清空链表
 * 参数：linkedList 链表对象
 * 返回值：清空结果
*/
Status clearList(LinkedList &linkedList);
Status isEmpty(LinkedList linkedList);
int getLength(LinkedList linkedList);
Status getElement(LinkedList linkedList,int index,ElementType &returnElement);
int  findElement(LinkedList,ElementType element);
Status PriorElement(LinkedList linkedList,int index,ElementType &returnElement);
Status NextElement(LinkedList linkedList,int index,ElementType &returnElement);
Status insertElement(LinkedList &linkedList,int index,ElementType element);
Status deleteElement(LinkedList &linkedList,int index,ElementType &element);
/*=====================================函数声明=====================================*/


//带头节点的链表

/*=====================================函数定义=====================================*/

/**
 * 功能：初始化链表，为其分配存储空间
 * 参数：linkedList 链表对象
 * 返回值：无
*/
Status initList(LinkedList &linkedList){

    //分配一个节点的内存空间
    linkedList = (LinkedNode *)malloc(sizeof(LinkedNode));

    //内存分配失败直接退出
    if(linkedList == NULL){
        exit(1);
    }

    //数据域为空
    linkedList->data = NULL;
    //指针域为空
    linkedList->next = NULL;

    return OK;
}

/**
 * 功能：销毁链表
 * 参数：linkedList 链表对象
 * 返回值：销毁结果 
*/
Status destroyList(LinkedList &linkedList){
    if(linkedList != NULL){
        //直接释放链表的第一个节点即可
        free(linkedList);
        return OK;
    }else{
        return ERROR;
    }
}


/**
 * 功能：获取链表长度
 * 参数：linkedList 链表对象
 * 返回值：链表长度
*/
int getLength(LinkedList linkedList){
    int listLength = 0;

    //a1是第一个元素
    LinkedList nextElement = linkedList->next;

    //最后一个元素指针域为空
    //时间复杂度 O(n)
    while(nextElement != NULL){
        //长度加一并指向下一个元素
        listLength++;
        nextElement = nextElement->next;
    }

    return listLength;
}


/**
 * 功能：链表是否为空
 * 参数：linkedList 链表对象
 * 返回值：是否为空
*/
Status isEmpty(LinkedList linkedList){
    return linkedList->next == NULL;
}


/**
 * 功能：获取指定下标的元素
 * 参数：linkedList 链表对象 index 下标 returnElement 通过此参数返回值
 * 返回值：找到返回OK 否则ERROR
*/
Status getElement(LinkedList linkedList,int index,ElementType &returnElement){

    //首先指向头节点
    LinkedNode *element = linkedList;

    //循环几次就指向第几个元素
    //从0到index(用户要找的下标)
    //时间复杂度 O(n)
    for(int i = 0;i <= index;i++){
        //还没找到index的元素
        //但是当前元素为空 直接返回ERROR
        if(element == NULL)
            return ERROR;

        //指向下一个元素
        element = element->next;
    }

    //返回下标为index的元素值
    returnElement = element->data;
    return OK;
}


/**
 * 功能：根据元素找到其下标
 * 参数：linkedList 链表对象 elemen要查找的元素
 * 返回值：该元素在链表中的下标 找不到返回-1
*/
int  findElement(LinkedList linkedList,ElementType element){

    int listLength = getLength(linkedList);

    //先指向a1节点
    LinkedNode *currentElement = linkedList->next;


    //0 ~ [index - 1]
    for(int i = 0;i < listLength;i++){
        //还没找到元素 但是当前元素是NULL 那么直接返回ERROR
        if(currentElement == NULL)
            return ERROR;
        
        //找到用户要寻找的元素 返回其下标
        if(currentElement->data == element)
            return i;
        
        //没有找到 接着指向下一个元素
        currentElement = currentElement->next;
    }

    return ERROR;
}


/**
 * 功能：指定下标上元素的前驱
 * 参数：linkedList 链表对象 index 下标 returnElement 通过此参数返回前驱的值
 * 返回值：找到返回OK 否则ERROR
*/
Status PriorElement(LinkedList linkedList,int index,ElementType &returnElement){

    //下标[index]不合法
    if(!(index > 0 && (index < getLength(linkedList)))){
        return INFEASIBLE;
    }

    //下标[index - 1]不合法
    if(!(index - 1 > 0 && (index - 1 < getLength(linkedList)))){
        return INFEASIBLE;
    }

    return getElement(linkedList,index - 1,returnElement);
}


/**
 * 功能：指定下标上元素的后继
 * 参数：linkedList 链表对象 index 下标 returnElement 通过此参数返回后继的值
 * 返回值：找到返回OK 否则ERROR
*/
Status NextElement(LinkedList linkedList,int index,ElementType &returnElement){

    //下标[index]不合法
    if(!(index > 0 && (index < getLength(linkedList)))){
        return INFEASIBLE;
    }

    //下标[index + 1]不合法
    if(!(index + 1 > 0 && (index + 1 < getLength(linkedList)))){
        return INFEASIBLE;
    }

    return getElement(linkedList,index + 1,returnElement);
}


/**
 * 功能：向指定位置插入一个元素
 * 参数：linkedList 链表对象 index 下标 element 待插入元素
 * 返回值：插入结果
*/
Status insertElement(LinkedList &linkedList,int index,ElementType newElement){

    //下标[index]不合法
    if(index < 0 || index > getLength(linkedList)){
        return INFEASIBLE;
    }

    //先指向头节点
    LinkedNode *element = linkedList;

    //指向第[i - 1]个元素
    for(int i = 0;i <= (index - 1);i++){
        //当前元素为空 直接返回ERROR
        if(element == NULL)
            return ERROR;

        //指向下一个元素
        element = element->next;
    }

    //申请新节点的内存
    LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedList));

    //如果新节点分配空间失败 那么直接exit
    if(newNode == NULL)
        exit(1);

    newNode->data = newElement;

    //新节点的下一个元素是下标为[index - 1]元素的下一个[index]节点
    newNode->next = element->next;

    //新节点是下标为[index - 1]元素的后继
    element->next = newNode;

    return OK;
}


/**
 * 功能：删除指定位置的元素
 * 参数：linkedList 链表对象 index 下标 element 待删除元素
 * 返回值：删除结果
*/
Status deleteElement(LinkedList &linkedList,int index,ElementType &element){

    //下标[index]不合法
    if(index < 0 || (index > getLength(linkedList))){
        return INFEASIBLE;
    }

    //先指向头节点
    LinkedNode *currentElement = linkedList;

    //指向第[i - 1]个元素
    for(int i = 0;i <= (index - 1);i++){
        //当前元素为空 直接返回ERROR
        if(element == NULL)
            return ERROR;

        //指向下一个元素
        currentElement = currentElement->next;
    }

    //没有第i个元素
    if(currentElement->next == NULL){
        return OVERFLOW;
    }

    //把要删除的元素返回给调用者
    element = currentElement->next->data;

    //直接越过要删除的元素指向其指针域
    currentElement->next = currentElement->next->next;

    return OK;
}
/*=====================================函数定义=====================================*/