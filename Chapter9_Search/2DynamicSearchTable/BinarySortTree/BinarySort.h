#include "stdio.h"
#include "stdlib.h"

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
    ElementType data;                           //数据域 存储着结点的值
    struct LinkedTreeNodeStruct *leftChild;     //指针域 指向左子结点
    struct LinkedTreeNodeStruct *rightChild;    //指针域 指向右子结点
} BinaryNode, *BinarySortTree;
/*=====================================结构体=====================================*/

/**
 * 功能：在二叉排序树中查找
 * 参数：tree 二叉排序树；key 要查找的关键字；
 * 返回值：若查找成功返回结点指针，查找失败返回NULL
*/
BinarySortTree searchBST(BinarySortTree tree, ElementType key){
    //如果空则返回空
    //如果要查找的值和当前结点值相同，那么返回
    if((tree == NULL) || (tree->data == key)){
        return tree;
    }
    //根据二叉排序树的性质
    //如果要查找的关键字大于结点值，那么继续查找右子树，否则继续查找左子树
    else{        
        return searchBST((key < tree->data) ? tree->leftChild : tree->rightChild, key);
    }
}

/**
 * 功能：在二叉排序树中查找有指定关键字的结点
 * 参数：root 根结点；key 要查找的关键字；parent 双亲；returnTree 通过此参数返回指针
 * 返回值：查找成功返回TRUE，否则返回FALSE
*/
Status searchBST(BinarySortTree root, ElementType key, BinarySortTree parent, BinarySortTree &returnTree){
    //已经查找到最后还是没有找到，返回FALSE
    if(root == NULL){
        returnTree = NULL;
        return FALSE;
    }
    //查找成功，返回该结点的父结点
    else if(root->data = key){
        returnTree = parent;
        return TRUE;
    }
    //如果要查找的值小于结点值，那么继续查找左子树，否则继续查找右子树
    else{
        BinarySortTree searchTree = (key < root->data) ? root->leftChild : root->rightChild;
        return searchBST(searchTree, key, root, returnTree);
    }
}

/**
 * 功能：向二叉排序树中插入结点
 * 参数：bst 二叉排序树；value 要插入的值
 * 返回值：插入成功返回TRUE，否则返回FALSE
*/
Status insertBST(BinarySortTree &bst, ElementType value){
    BinarySortTree parentNode;
    //如果指定结点已经存在，那么插入失败
    if(searchBST(bst, value, NULL, parentNode)){
        return FALSE;
    }
    //具有指定值的结点不存在，构造一个新结点
    else{
        //申请一个新结点并且设置其数据域和指针域
        BinaryNode *node = (BinaryNode *)malloc(sizeof(BinaryNode));
        node->data = value;
        node->leftChild = node->rightChild = NULL;

        //如果具有指定值的结点的双亲也不存在，那么说明这个是一个空树
        if(parentNode == NULL){
            bst = node;
        }

        //根据二叉排序树的性质
        //左子树的值均小于根结点，右子树的值均大于根节点
        if(value < parentNode->data){
            parentNode->leftChild = node;
        }else{
            parentNode->rightChild = node;
        }
        
        return TRUE;
    }
}

/**
 * 功能：删除二叉排序树中的结点
 * 参数：tree 二叉树    左根右
 * 返回值：遍历结果
*/
Status deleteBST(BinarySortTree bst, ElementType value){
    return NULL;
}

/**
 * 功能：中序遍历
 * 参数：tree 二叉树    左根右
 * 返回值：遍历结果
*/
Status inOrderTraverse(BinarySortTree &tree){
    if(tree == NULL){
        return FALSE;
    }else{
        //左根右
        inOrderTraverse(tree->leftChild);
        printf("%d",tree->data);
        inOrderTraverse(tree->rightChild);
        return TRUE;
    }
}