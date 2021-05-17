#include "stdio.h"
#include "BinaryTree.h"
#include "LinearList_Sequence.h"

//获取值最小的二叉树在列表中的下标
int getMinTreeIndexInList(SequenceList list){

    if(isEmpty(list))
        return -1;

    BinaryTree minTree, tempTree;
    void *temp;
    int minIndex = 0;
    
    getElement(list, 0, temp);
    minTree = (BinaryTree)temp; 
    
    int length = getLength(list);
    for(int i = 1;i < length;i++){
        getElement(list, i, temp);
        tempTree = (BinaryTree)temp; 

        if(tempTree->data < minTree->data){
            minTree = tempTree;
            minIndex = i;
        }
    }

    return minIndex;
}

int main(){
    SequenceList list;
    initList(list);

    //接收n个字符 并生成n个结点
    int inputChar;
    //如果输入的字符不为NULL说明输入没有结束
    for(int i = 0;scanf("%d",&inputChar) && inputChar != '*';i++){
        //生成一个结点并设置其数据域为输入的字符
        //指针域设置为空
        BinaryTree node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        node->data = inputChar;
        node->leftChild = node->rightChild = NULL;

        insertElement(list, i, node);
    }

    //循环结束条件：1.没有任何结点；2.有结点，最后合并到只有一个结点
    while(!isEmpty(list) && getLength(list) != 1){
        //寻找到两个最小的数值
        void *temp;
        BinaryTree minTree1, minTree2;

        //获取到值最小的结点并从列表中删除
        deleteElement(list,getMinTreeIndexInList(list),temp);
        minTree1 = (BinaryTree)temp;

        //获取到值最第二小的结点并从列表中删除
        deleteElement(list,getMinTreeIndexInList(list),temp);
        minTree2 = (BinaryTree)temp;

        //计算新权值并设置其左右子树
        BinaryTreeElementType newNodeData = minTree1->data + minTree2->data;
        BinaryTree newNode = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        newNode->data = newNodeData;
        newNode->leftChild = minTree1;
        newNode->rightChild = minTree2;

        //将新树添加到列表中
        insertElement(list, getLength(list), newNode);
    }


    void* rootTree;
    getElement(list, 0, rootTree);
    BinaryTree tree = (BinaryTree)rootTree;
    printf("\n\nPreOrderTraverse\n");
    PreOrderTraverse(tree);
    printf("\n\nInOrderTraverse\n");
    InOrderTraverse(tree);

    return 0;
}