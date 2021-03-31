#include "stdio.h"
#include "stdlib.h"

//Written by Juston
//2021/03/31 14:49

/**
 * 更新：我这个跟书上的不太一样 书上用的有头节点（不存储数据）的形式，而我的没有用头节点
*/

/**
 * 和栈相反，队列 (Queue) 是一种先进先出 (FIFO  First In First Out)的线性表
 * 它只允许在表的一端进行插入，而在表的另一端删除元素
 * 在队列中，允许插入的一段叫做队尾 (rear)
 * 允许删除的一端叫做队头 (front)
 *
 * 数据对象 D = {ai | ai 属于 ElementSet, i = 1, 2, ... , n ,n >= 0}
 * 数据关系 R1 = {<ai - 1 , ai> | ai - 1, ai 属于 D, i = 2 , ... , n}
 * 约定其中 a1 端为队列头 an端为队列尾
*/

/*=====================================宏定义=====================================*/
#define Status int

#define OK 2

#define TRUE 1
#define FALSE 0

#define ERROR -3
#define INFEASIBLE -2
#define OVERFLOW -1

#define QUEUE_INIT_SIZE 10
#define QUEUE_INCREMENT 10

#define ElementType int
/*=====================================宏定义=====================================*/

/*=====================================结构体=====================================*/

typedef struct QueueNodeStruct
{
    ElementType data;             //数据
    struct QueueNodeStruct *next; //下一个节点的地址
} QueueNode, *QueuePointer;       //队列节点 队列节点指针

typedef struct LinkedQueueStruct
{
    QueuePointer front; //队头
    QueuePointer rear;  //队尾
} LinkedQueue;          //队列

/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
Status initQueue(LinkedQueue &queue);
Status destoryQueue(LinkedQueue &queue);
Status clearQueue(LinkedQueue &queue);
Status isEmpty(LinkedQueue &queue);
int getLength(LinkedQueue &queue);
Status enQueue(LinkedQueue &queue, ElementType element);
Status deQueue(LinkedQueue &queue, ElementType &element);
Status queueTraverse(LinkedQueue &queue);
/*=====================================函数声明=====================================*/


/*=====================================函数定义=====================================*/

/**
 * 功能：初始化链式队列
 * 参数：queue 链式队列对象
 * 返回值：初始化结果
*/
Status initQueue(LinkedQueue &queue){
    if (&queue == NULL){
        return ERROR;
    }

    //注意 我这里是没有头节点 所以没有节点的额状态下front和rear都是NULL
    queue.front = queue.rear = NULL;

    return OK;
}

/**
 * 功能：销毁链式队列
 * 参数：queue 链式队列对象
 * 返回值：销毁结果
*/
Status destoryQueue(LinkedQueue &queue){
    if(&queue == NULL)
        return ERROR;

    if(isEmpty(queue))
        return OK;

    while(queue.front != NULL){
        free(queue.front);
        queue.front = queue.front->next;
    }

    return OK;
}

/**
 * 功能：清空链式队列
 * 参数：queue 链式队列对象
 * 返回值：清空结果
*/
Status clearQueue(LinkedQueue &queue);

/**
 * 功能：链式队列是否为空
 * 参数：queue 链式队列对象
 * 返回值：是否为空
*/
Status isEmpty(LinkedQueue &queue){

    if (&queue == NULL)
        exit(OVERFLOW);

    //如果front和rear都是NULL 说明此时没有任何数据
    return (queue.front == NULL) && (queue.rear == NULL);
}

/**
 * 功能：获取链式队列长度
 * 参数：queue 链式队列对象
 * 返回值：链式队列长度
*/
int getLength(LinkedQueue &queue){

    if (&queue == NULL){
        return ERROR;
    }

    if (isEmpty(queue))
        return 0;

    //判断node是否为空 不为空就指向下一个节点 
    //计数并返回
    int i = 0;
    QueueNode *node = queue.front;

    while(node != NULL){
        node = node->next;
        i++;
    }

    return i;
}

/**
 * 功能：获取链式队列队头但不弹出
 * 参数：queue 链式队列对象
 * 返回值：队头节点元素值
*/
Status getHead(LinkedQueue &queue, ElementType &returnElement){

    if (&queue == NULL){
        return ERROR;
    }

    //把头结点的数据返回 但不弹出
    returnElement = queue.front->data;

    return OK;
}

/**
 * 功能：向链式队列队尾插入一个元素
 * 参数：queue 链式队列对象
 * 返回值：插入结果
*/
Status enQueue(LinkedQueue &queue, ElementType element){

    if (&queue == NULL){
        return ERROR;
    }

    //申请一个新节点的空间
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));

    if (newNode == NULL)
        exit(OVERFLOW);

    //设置新节点的数据域和指针域
    newNode->data = element;
    newNode->next = NULL;

    //无头节点
    //如果队列为空 那么应该将队列的front和rear指向新节点
    if (isEmpty(queue)){
        queue.front = queue.rear = newNode;
    }
    else{
        //非空 队尾节点的指针域指向新节点 
        //并设置新元素为队尾
        queue.rear->next = newNode;
        queue.rear = newNode;
    }

    return OK;
}

/**
 * 功能：弹出 (删除) 链式队列列头元素
 * 参数：queue 链式队列对象
 * 返回值：弹出结果
*/
Status deQueue(LinkedQueue &queue, ElementType &element){

    if (&queue == NULL){
        return ERROR;
    }

    if (isEmpty(queue))
        return OVERFLOW;

    //将要删除的元素取出
    element = queue.front->data;

    //队头指针 指向 原本队头节点的下一个节点
    queue.front = queue.front->next;

    //如果队头指针为空 说明空了 那么队尾也设置为空
    if(queue.front == NULL){
        queue.rear = NULL;
    }

    return OK;
}

/**
 * 功能：链式队列遍历
 * 参数：queue 链式队列对象
 * 返回值：遍历结果
*/
Status queueTraverse(LinkedQueue &queue);
/*=====================================函数定义=====================================*/