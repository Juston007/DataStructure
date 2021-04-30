#include "stdio.h"
#include "stdlib.h"

//Written by Juston
//2021/04/12 19:04


/*=====================================宏定义=====================================*/
#define Status       int

#define OK           2

#define Boolean      char
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
    struct LinkedTreeNodeStruct *leftChild;
    struct LinkedTreeNodeStruct *rightChild;       //指针域 指向左子结点和右子结点
} BinaryNode, *BinaryTree;
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
Status isEmptyBinaryTree(BinaryTree &tree);
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
    if(isEmptyBinaryTree(tree))
        return FALSE;

    //destoryBinaryTree(tree);
    tree = NULL;
    return TRUE;
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
        return FALSE;
    }else{
        returnRoot = tree->data;
        return TRUE;
    }
}

/**
 * 功能：获取二叉树中某个结点的值
 * 参数：tree 二叉树，node 某个结点，returnValue 通过此参数返回结点的值
 * 返回值：获取结果
 * 
 * 这个也没用
*/
Status getValue(BinaryTree &tree, BinaryNode node, ElementType &returnValue){
    return OK;
}

/**
 * 功能：给二叉树中某个结点赋值
 * 参数：tree 二叉树，node 某个结点，value 要赋的值
 * 返回值：赋值结果
*/
Status assign(BinaryTree &tree, BinaryNode node, ElementType value){
    return OK;
}

/**
 * 功能：搜索树中某个结点的元素值
 * 参数：tree 树 element 要搜索的元素 returnNode 通过此参数返回节点的指针
 * 返回值：搜索结果
*/
Status searchTree(BinaryTree tree, ElementType element, BinaryTree &returnTree){
    if(isEmptyBinaryTree(tree)){
        return FALSE;
    }else{
        //如果当前结点元素值和要寻找的元素值相同那么直接返回
        if(element == tree->data){
            returnTree = tree;
            return TRUE;
        }else{
            //否则就去搜索左子树和右子树
            int code = searchTree((BinaryTree)tree->leftChild, element, returnTree);
            if(code == TRUE)
                return TRUE;

            code = searchTree((BinaryTree)tree->rightChild, element, returnTree);
            return code;
        }
    }
}

/**
 * 功能：获取二叉树中某个结点的双亲
 * 参数：tree 二叉树，parentTree 通过此参数返回双亲
 * 返回值：获取结果
*/
Status getParent(BinaryTree &tree, BinaryNode node, BinaryTree &parentTree){
    return searchTree(tree, node.data, parentTree);
}

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
 * 参数：tree 二叉树，parentNode 父结点，isLeft 左1右0，childTree 要插入的子树
 * 返回值：插入结果
*/
Status insertChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryTree childTree){
    if(isEmptyBinaryTree(tree)){
        tree = childTree;
        return TRUE;
    }else{
        BinaryTree searchResult;
        Status resultCode = searchTree(tree, parentNode.data, searchResult);
        if(resultCode == TRUE){
            if(isLeft){
                searchResult->leftChild = childTree;
            }else{
                searchResult->rightChild = childTree;
            }
            return TRUE;
        }else{
            return FALSE;
        }
    }
}

/**
 * 功能：删除二叉树中某个结点的左子树或右子树
 * 参数：tree 二叉树，node 结点，isLeft 左1右0
 * 返回值：删除结果
*/
Status deleteChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryNode &returnNode){
    if(isEmptyBinaryTree(tree)){
        return ERROR;
    }else{
        BinaryTree searchResult;
        int resultCode = searchTree(tree, parentNode.data, searchResult);
        if(resultCode == TRUE){
            returnNode = *(isLeft ? searchResult->leftChild : searchResult->rightChild);

            if(isLeft){
                searchResult->leftChild = NULL;
            }else{
                searchResult->rightChild = NULL;
            }
            return TRUE;
        }else{
            return ERROR;
        }
    }
}

/**
 * 功能：给二叉树中的某个结点插入一个（左or右）子树
 * 参数：tree 二叉树，parentNode 父结点，isLeft 左1右0，childTree 要插入的子树
 * 返回值：插入结果
*/
Status insertNode(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, ElementType value, BinaryNode &returnNode){
    BinaryTree childNode = (BinaryNode *)malloc(sizeof(BinaryNode));
    childNode->data = value;
    childNode->leftChild = childNode->rightChild = NULL;
    returnNode = *childNode;

    return insertChild(tree, parentNode, isLeft, childNode);
}

/**
 * 功能：前序遍历
 * 参数：tree 二叉树    根左右
 * 返回值：遍历结果
*/
Status preOrderTraverse(BinaryTree &tree){
    if(isEmptyBinaryTree(tree)){
        return FALSE;
    }else{
        //根左右
        printf("%d",tree->data);
        preOrderTraverse(tree->leftChild);
        preOrderTraverse(tree->rightChild);
        return TRUE;
    }
}

/**
 * 功能：中序遍历
 * 参数：tree 二叉树    左根右
 * 返回值：遍历结果
*/
Status inOrderTraverse(BinaryTree &tree){
    if(isEmptyBinaryTree(tree)){
        return FALSE;
    }else{
        //左根右
        preOrderTraverse(tree->leftChild);
        printf("%d",tree->data);
        preOrderTraverse(tree->rightChild);
        return TRUE;
    }
}

/**
 * 功能：后序遍历
 * 参数：tree 二叉树    左右根
 * 返回值：遍历结果
*/
Status postOrderTraver(BinaryTree &tree){
    if(isEmptyBinaryTree(tree)){
        return FALSE;
    }else{
        //左右根
        printf("%d",tree->data);
        preOrderTraverse(tree->rightChild);
        preOrderTraverse(tree->leftChild);
        return TRUE;
    }
}

/**
 * 功能：层级遍历
 * 参数：tree 二叉树
 * 返回值：遍历结果
*/
Status levelOrderTraverse(BinaryTree &tree);
/*=====================================函数声明=====================================*/