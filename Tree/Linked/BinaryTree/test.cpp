#include "stdio.h"
#include "BinaryTree.h"

void printAllElement(BinaryTree &tree){
    //前序遍历
    printf("\n");
    preOrderTraverse(tree);
    printf("\n");
}

int main(){
    BinaryTree binaryTree;
    int code;
    
    //初始化二叉树
    int initCode = initBinaryTree(binaryTree);
    printf("Init Binary Tree    Code = %d\n", initCode);

    //向二叉树中插入一个元素
    BinaryNode returnNode1;
    int insertCode1 = insertNode(binaryTree, returnNode1, TRUE, 1, returnNode1);
    printf("Insert Element%d      Code = %d\n", 1, insertCode1);
    printAllElement(binaryTree);

    //向二叉树中插入一个元素
    BinaryNode returnNode2;
    int insertCode2 = insertNode(binaryTree, *binaryTree, TRUE, 2, returnNode2);
    printf("Insert Element%d      Code = %d\n", 2, insertCode2);
    printAllElement(binaryTree);


    //向二叉树中插入一个元素
    BinaryNode returnNode3;
    int insertCode3 = insertNode(binaryTree, *binaryTree, FALSE, 3, returnNode3);
    printf("Insert Element%d      Code = %d\n", 3, insertCode3);
    printAllElement(binaryTree);


    //向二叉树中插入一个元素
    BinaryNode returnNode4;
    int insertCode4 = insertNode(binaryTree, returnNode2, TRUE, 4, returnNode4);
    printf("Insert Element%d      Code = %d\n", 4, insertCode3);
    printAllElement(binaryTree);

    //向二叉树中插入一个元素
    BinaryNode returnNode5;
    int insertCode5 = insertNode(binaryTree, returnNode3, TRUE, 5, returnNode5);
    printf("Insert Element%d      Code = %d\n", 5, insertCode5);
    printAllElement(binaryTree);

    //向二叉树中插入一个元素
    BinaryNode returnNode6;
    int insertCode6 = insertNode(binaryTree, returnNode2, FALSE, 6, returnNode6);
    printf("Insert Element%d      Code = %d\n", 6, insertCode6);
    printAllElement(binaryTree);

    //向二叉树中插入一个元素
    BinaryNode returnNode7;
    int insertCode7 = insertNode(binaryTree, returnNode6, FALSE, 7, returnNode7);
    printf("Insert Element%d      Code = %d\n", 7, insertCode7);
    printAllElement(binaryTree);

    BinaryNode returnNode8;
    int deleteCode1 = deleteChild(binaryTree, returnNode1, TRUE, returnNode8);
    printf("Delete Element%d      Code = %d\n", returnNode8.data, deleteCode1);
    printAllElement(binaryTree);

    return 1;
}