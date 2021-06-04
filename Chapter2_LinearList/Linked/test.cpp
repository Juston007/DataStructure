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

    printf("\n");
}

/**
 * 链表的合并
*/
void MergeLinkedList(LinkedList listA,LinkedList listB,LinkedList &listC){
    //链表和顺序表的插入 链表直接将元素与元素的指针连接起来即可
    //但是也可以一个个插入元素 但是此方法太过费事 时间复杂度高

    //pa、pb和pc指向元素 会一个个往后走 就像迭代器一样？

    //pa、pb分别指向listA和listB的第一个元素
    //当然可能为NULL 不过没关系 要是为NULL就直接跳过了
    LinkedNode *pa = listA->next;
    LinkedNode *pb = listB->next;

    //pc指向listA的Header
    //为啥不是listA->next ？ 因为这个时候新链表还没元素哈哈
    LinkedNode *pc = listA;
    //这里是为了能够函数调用者能够接收到被修改的链表
    listC = pc;

    //当其中一个链表指向最后一个元素的时候结束
    while((pa != NULL) && (pb != NULL)){
        if(pa->data > pb->data){
            //pc的指针域指向pb
            pc->next = pb;
            //pb指向下一个元素
            pb = pb->next;
        }
        else{
            //与上面相同
            pc->next = pa;
            pa = pa->next;
        }
        //pc也指向其下一个元素
        pc = pc->next;
    }
    //此时一个链表已经全部添加完毕了 所以只添加剩下的链表的元素就行了
    //但是不需要像顺序表一样一个个添加 可以利用链表的特性直接让指针域指到剩下的第一个元素就行了
    //ps 特性是说的通过前一个元素可以找到下一个元素
    pc->next = (pa != NULL) ? pa : pb;

    free(listB);
}

/**
 * 先建立末尾的元素
*/
void firstSetupEnd(LinkedList &list,int length){
    LinkedList nodePoint = list;
    for(int i = 0;i < length;i++){
        LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));

        if(newNode == NULL)
            exit(OVERFLOW);
        
        int value;
        scanf("%d",&value);
        newNode->data = value;

        //新元素指针域指向第一个元素
        newNode->next = list->next;
        //第一个元素调整到新元素后面    现在新元素成了第一个元素 之前的元素成了第二个元素
        list->next = newNode;
    }
}

/**
 * 先建立开始的元素
 * 这样 O(n) 比用insertElement O(n ^ 2)时间复杂度底
*/
void firstSetupStart(LinkedList &list,int length){
    LinkedList nodePoint = list;
    for(int i = 0;i < length;i++){
        LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));

        if(newNode == NULL)
            exit(OVERFLOW);
        
        int value;
        scanf("%d",&value);
        newNode->data = value;

        //这里必须给新元素的指针赋值为NULL
        //不然会存在一个脏数据导致程序无法正常运行
        newNode->next = NULL;
        //指针直接指向新元素
        nodePoint->next = newNode;

        //指针后移
        nodePoint = nodePoint->next;
    }
}


int main(){



    /*
    LinkedList list;
    initList(list);

    //firstSetupEnd(list,5);
    firstSetupStart(list,5);
    printAllElement(list);
    */

    /*
    LinkedList listA,listB,listC;

    initList(listA);
    initList(listB);

    insertElement(listA,0,3);
    insertElement(listA,1,5);
    insertElement(listA,2,8);
    insertElement(listA,3,11);
    printAllElement(listA);

    insertElement(listB,0,2);
    insertElement(listB,1,6);
    insertElement(listB,2,8);
    insertElement(listB,3,9);
    insertElement(listB,4,11);
    insertElement(listB,5,15);
    insertElement(listB,6,20);
    printAllElement(listB);

    MergeLinkedList(listA,listB,listC);
    printAllElement(listC);
    */

    /*
    //***************Init************************
    LinkedList linkedList;
    initList(linkedList);
    printf("Init linked List OK!\n");

    
    //***************Init************************
    //printf("isEmpty = %d\n",isEmpty(linkedList));

    insertElement(linkedList,0,9);
    insertElement(linkedList,1,8);
    insertElement(linkedList,2,7);
    insertElement(linkedList,3,6);
    insertElement(linkedList,4,5);

    //printf("isEmpty = %d length = %d\n",isEmpty(linkedList),getLength(linkedList));

    printAllElement(linkedList);*/


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

   /*
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
   */


}