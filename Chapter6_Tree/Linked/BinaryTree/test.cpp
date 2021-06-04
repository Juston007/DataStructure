#include "stdio.h"
#include "BinaryTree.h"

void printAllElement(BinaryTree &tree){
    //前序遍历
    printf("\n");

    if(isEmptyBinaryTree(tree))
        printf("no element");
    else
        preOrderTraverse(tree);

    printf("\n");
}

int countLeaf(BinaryTree tree){
    if(tree == NULL){
        return 0;
    }else{
        if((tree->leftChild == NULL) && (tree->rightChild == NULL)){
            return 1;
        }else{
            return countLeaf(tree->leftChild) + countLeaf(tree->rightChild);
        }
    }
}

int main(){
    BinaryTree binaryTree;
    int code;
    
    //初始化二叉树
    int initCode = initBinaryTree(binaryTree);
    printf("Init Binary Tree    Code = %d\n", initCode);

    int treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);

    //向二叉树中插入一个元素
    BinaryNode returnNode1;
    int insertCode1 = insertNode(binaryTree, returnNode1, TRUE, 1, returnNode1);
    printf("Insert Element%d      Code = %d\n", 1, insertCode1);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);

    //向二叉树中插入一个元素
    BinaryNode returnNode2;
    int insertCode2 = insertNode(binaryTree, *binaryTree, TRUE, 2, returnNode2);
    printf("Insert Element%d      Code = %d\n", 2, insertCode2);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);


    //向二叉树中插入一个元素
    BinaryNode returnNode3;
    int insertCode3 = insertNode(binaryTree, *binaryTree, FALSE, 3, returnNode3);
    printf("Insert Element%d      Code = %d\n", 3, insertCode3);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);


    //向二叉树中插入一个元素
    BinaryNode returnNode4;
    int insertCode4 = insertNode(binaryTree, returnNode2, TRUE, 4, returnNode4);
    printf("Insert Element%d      Code = %d\n", 4, insertCode3);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);

    //向二叉树中插入一个元素
    BinaryNode returnNode5;
    int insertCode5 = insertNode(binaryTree, returnNode3, TRUE, 5, returnNode5);
    printf("Insert Element%d      Code = %d\n", 5, insertCode5);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);

    //向二叉树中插入一个元素
    BinaryNode returnNode6;
    int insertCode6 = insertNode(binaryTree, returnNode2, FALSE, 6, returnNode6);
    printf("Insert Element%d      Code = %d\n", 6, insertCode6);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);

    //向二叉树中插入一个元素
    BinaryNode returnNode7;
    int insertCode7 = insertNode(binaryTree, returnNode6, FALSE, 7, returnNode7);
    printf("Insert Element%d      Code = %d\n", 7, insertCode7);
    printAllElement(binaryTree);

    treeDepth = getBinaryTreeDepth(binaryTree);
    printf("tree depth %d\n",treeDepth);

    // BinaryNode returnNode8;
    // int deleteCode1 = deleteChild(binaryTree, returnNode1, TRUE, returnNode8);
    // printf("Delete Element%d      Code = %d\n", returnNode8.data, deleteCode1);
    // printAllElement(binaryTree);

    // BinaryNode returnNode9;
    // deleteCode1 = deleteChild(binaryTree, returnNode2, TRUE, returnNode9);
    // printf("Delete Element%d      Code = %d\n", returnNode9.data, deleteCode1);
    // printAllElement(binaryTree);


    // int assignCode1 = assign(binaryTree, returnNode1, 9);
    // printf("Assign Element%d      Code = %d\n", 9, assignCode1);
    // printAllElement(binaryTree);

    // treeDepth = getBinaryTreeDepth(binaryTree);
    // printf("tree depth %d\n",treeDepth);

    // int returnValue = -999;
    // returnNode1.data = 9;
    // int valueCode1 = getValue(binaryTree, returnNode1, returnValue);
    // printf("node%d value Element%d      Code = %d\n",returnNode1.data, returnValue, valueCode1);
    // printAllElement(binaryTree);

    // treeDepth = getBinaryTreeDepth(binaryTree);
    // printf("tree depth %d\n",treeDepth);


    // BinaryTree returnChild1;
    // returnNode1.data = 3;
    // int getChildCode1 = getChild(binaryTree, returnNode1, TRUE, returnChild1);
    // printf("Get Child, Root Element%d      Code = %d\n",getChildCode1 == TRUE ? returnChild1->data : 0, getChildCode1);
    // printAllElement(returnChild1);

    // treeDepth = getBinaryTreeDepth(binaryTree);
    // printf("tree depth %d\n",treeDepth);

    // BinaryNode returnSibling1;
    // returnSibling1.data = 999;
    // returnNode1.data = 7;
    // int getSiblingCode = getRightSibling(binaryTree, returnNode1, returnSibling1);
    // printf("Get Left Sibling Element%d      Code = %d\n", returnSibling1.data, getSiblingCode);
    // printAllElement(binaryTree);

    // treeDepth = getBinaryTreeDepth(binaryTree);
    // printf("tree depth %d\n",treeDepth);

    // //向二叉树中插入一个元素
    // BinaryNode returnNode10;
    // returnNode1.data = 9;
    // int insertCode10 = insertNode(binaryTree, returnNode1, TRUE, 8, returnNode10);
    // printf("Insert Element%d      Code = %d\n", 8, insertCode10);
    // printAllElement(binaryTree);

    // treeDepth = getBinaryTreeDepth(binaryTree);
    // printf("tree depth %d\n",treeDepth);


    int leaf = countLeaf(binaryTree);
    printf("leaf count %d", leaf);

    return 1;
}