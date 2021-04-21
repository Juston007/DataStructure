#include "stdio.h"
#include "stdlib.h"

//Written by Juston
//2021/04/12 19:04


/*=====================================宏定义=====================================*/
#define Status       int

#define OK           2-3201

#define TRUE         1
#define FALSE        0

#define ERROR       -3
#define INFEASIBLE  -2
#define OVERFLOW    -1

#define ElementType int
/*=====================================宏定义=====================================*/


/*=====================================结构体=====================================*/
typedef struct LinkedTreeNodeStruct{
    ElementType data;                          //数据域 存储着结点的值
    struct Node *leftChild, *rightChild;       //指针域 指向左子结点和右子结点
} BinaryNode, *BinaryTree;
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
/**
 * 功能：初始化二叉树
 * 参数：tree 二叉树
 * 返回值：初始化结果
*/
Status initBinaryTree(BinaryTree &tree){
    tree = NULL;
    return TRUE;
}

/**
 * 功能：销毁树
 * 参数：tree 二叉树
 * 返回值：销毁结果
*/
Status destoryBinaryTree(BinaryTree &tree);

/**
 * 功能：创建二叉树
 * 参数：tree 二叉树
 * 返回值：创建结果
*/
Status createBinaryTree(BinaryTree &tree);

/**
 * 功能：清空二叉树
 * 参数：tree 二叉树
 * 返回值：清空结果
*/
Status clearBinaryTree(BinaryTree &tree){
    
}

/**
 * 功能：是否为空二叉树
 * 参数：tree 二叉树
 * 返回值：是空二叉树 TRUE 否则返回 FALSE
*/
Status isEmptyBinaryTree(BinaryTree &tree){
    return tree == NULL;
}

/**
 * 功能：获取二叉树的深度（层数）
 * 参数：tree 二叉树
 * 返回值：二叉树深度 小于0为错误
*/
int getBinaryTreeDepth(BinaryTree &tree);

/**
 * 功能：获取根结点
 * 参数：tree 二叉树，returnRoot 通过此参数返回根结点值
 * 返回值：销毁结果
 * 
 * 感觉这个函数没用啊
*/
Status getRoot(BinaryTree &tree, ElementType &returnRoot){
    if(isEmptyBinaryTree(tree)){

    }else{
        return FALSE;
    }
}

/**
 * 功能：获取二叉树中某个结点的值
 * 参数：tree 二叉树，node 某个结点，returnValue 通过此参数返回结点的值
 * 返回值：获取结果
 * 
 * 这个也没用
*/
Status getValue(BinaryTree &tree, BinaryNode node, ElementType &returnValue);

/**
 * 功能：给二叉树中某个结点赋值
 * 参数：tree 二叉树，node 某个结点，value 要赋的值
 * 返回值：赋值结果
*/
Status assign(BinaryTree &tree, BinaryNode node, ElementType value);

/**
 * 功能：获取二叉树中某个结点的双亲
 * 参数：tree 二叉树，parentTree 通过此参数返回双亲
 * 返回值：获取结果
*/
Status getParent(BinaryTree &tree, BinaryTree &parentTree);

/**
 * 功能：获取二叉树中某个结点的左子树
 * 参数：tree 二叉树，node 结点，returnChild 通过此参数返回左子树
 * 返回值：获取结果
*/
Status getLeftChild(BinaryTree &tree, BinaryNode node, BinaryTree &returnChild);

/**
 * 功能：获取二叉树中某个结点的右子树
 * 参数：tree 二叉树，node 结点，returnChild 通过此参数返回右子树
 * 返回值：获取结果
*/
Status getRightChild(BinaryTree &tree, BinaryNode node, BinaryTree &returnChild);

/**
 * 功能：获取二叉树中某个结点的左兄弟
 * 参数：tree 二叉树，node 结点，returnSibling 通过此参数返回其右兄弟
 * 返回值：获取结果，如果该结点为二叉树的左子孙或没有左兄弟则返回空
*/
Status getLeftSibling(BinaryTree &tree, BinaryTree node, BinaryTree &returnSibling);

/**
 * 功能：获取二叉树中某个结点的右兄弟
 * 参数：tree 二叉树，node 结点，returnSibling 通过此参数返回其右兄弟
 * 返回值：获取结果，如果该结点为二叉树的右子孙或没有右兄弟则返回空
*/
Status getRightSibling(BinaryTree &tree, BinaryTree node, BinaryTree &returnSibling);

/**
 * 功能：给二叉树中的某个结点插入一个（左or右）子树
 * 参数：tree 二叉树，node 结点，isLeft 左1右0，childTree 要插入的子树
 * 返回值：插入结果
*/
Status insertChild(BinaryTree &tree, BinaryNode node, short isLeft, BinaryTree childTree);

/**
 * 功能：删除二叉树中某个结点的左子树或右子树
 * 参数：tree 二叉树，node 结点，isLeft 左1右0
 * 返回值：删除结果
*/
Status deleteChild(BinaryTree &tree, BinaryNode node, short isLeft);

/**
 * 功能：前序遍历
 * 参数：tree 二叉树
 * 返回值：遍历结果
*/
Status preOrderTraverse(BinaryTree &tree);

/**
 * 功能：中序遍历
 * 参数：tree 二叉树
 * 返回值：遍历结果
*/
Status inOrderTraverse(BinaryTree &tree);

/**
 * 功能：后序遍历
 * 参数：tree 二叉树
 * 返回值：遍历结果
*/
Status postOrderTraver(BinaryTree &tree);

/**
 * 功能：层级遍历
 * 参数：tree 二叉树
 * 返回值：遍历结果
*/
Status levelOrderTraverse(BinaryTree &tree);
/*=====================================函数声明=====================================*/