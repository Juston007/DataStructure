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
    ElementType data;                           //数据域 存储着结点的值
    struct LinkedTreeNodeStruct *leftChild;     //指针域 指向左子结点
    struct LinkedTreeNodeStruct *rightChild;    //指针域 指向右子结点
} BinaryNode, *BinaryTree;
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
Status initBinaryTree(BinaryTree &tree);
Status destoryBinaryTree(BinaryTree &tree);
Status createBinaryTree(BinaryTree &tree);
Status clearBinaryTree(BinaryTree &tree);
Status isEmptyBinaryTree(BinaryTree &tree);
int getBinaryTreeDepth(BinaryTree &tree);
Status getRoot(BinaryTree &tree, ElementType &returnRoot);
Status getValue(BinaryTree &tree, BinaryNode node, ElementType &returnValue);
Status assign(BinaryTree &tree, BinaryNode node, ElementType value);
Status searchTree(BinaryTree tree, ElementType element, BinaryTree &returnTree);
Status getParent(BinaryTree &tree, BinaryNode node, BinaryTree &parentTree);
Status getChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryTree &returnChild);
Status getLeftChild(BinaryTree &tree, BinaryNode parentNode, BinaryTree &returnChild);
Status getRightChild(BinaryTree &tree, BinaryNode parentNode, BinaryTree &returnChild);
Status getLeftSibling(BinaryTree &tree, BinaryNode parentNode, BinaryNode &returnSibling);
Status getRightSibling(BinaryTree &tree, BinaryNode parentNode, BinaryNode &returnSibling);
Status insertChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryTree childTree);
Status deleteChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryNode &returnNode);
Status insertNode(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, ElementType value, BinaryNode &returnNode);
Status preOrderTraverse(BinaryTree &tree);
Status inOrderTraverse(BinaryTree &tree);
Status postOrderTraver(BinaryTree &tree);
Status levelOrderTraverse(BinaryTree &tree);
/*=====================================函数声明=====================================*/



/*=====================================函数定义=====================================*/

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
 * 待测试
 * 功能：销毁树
 * 参数：tree 二叉树
 * 返回值：销毁结果
*/
Status destoryBinaryTree(BinaryTree &tree){
    if(isEmptyBinaryTree(tree)){
        return TRUE;
    }else{
        BinaryTree leftChild = tree->leftChild;
        BinaryTree rightChild = tree->rightChild;

        destoryBinaryTree(tree);
        destoryBinaryTree(leftChild);
        destoryBinaryTree(rightChild);

        return TRUE;
    }
}

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
 * 返回值：二叉树深度
*/
int getBinaryTreeDepth(BinaryTree &tree){
    int depth = 0;

    if(!isEmptyBinaryTree(tree)){
        //如果不为空的话 那么本身算一层
        depth++;
        //计算左子树和右子树的深度
        int leftTreeDepth = getBinaryTreeDepth(tree->leftChild);
        int rightTreeDepth = getBinaryTreeDepth(tree->rightChild);
        //树的深度是深度求子树中深度最高的 所以再加上两者中较大的值并返回
        depth += (leftTreeDepth >= rightTreeDepth ? leftTreeDepth : rightTreeDepth);
        return depth;
    }else{
        return 0;
    }
}

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
    BinaryTree searchResult;
    int resultCode = searchTree(tree, node.data, searchResult);

    if(resultCode == TRUE){
        returnValue = searchResult->data;
        return TRUE;
    }else{
        return ERROR;
    }
}

/**
 * 功能：给二叉树中某个结点赋值
 * 参数：tree 二叉树，node 某个结点，value 要赋的值
 * 返回值：赋值结果
 * 
 * 没用+1
*/
Status assign(BinaryTree &tree, BinaryNode node, ElementType value){
    BinaryTree searchResult;
    int resultCode = searchTree(tree, node.data, searchResult);

    if(resultCode == TRUE){
        searchResult->data = value;
        return TRUE;
    }else{
        return ERROR;
    }
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
        //如果当前结点元素值和要寻找的元素值相同那么返回该结点的指针
        if(element == tree->data){
            returnTree = tree;
            return TRUE;
        }else{
            //否则就去递归搜索左子树和右子树
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
 * 功能：获取二叉树中某个结点的子树
 * 参数：tree 二叉树，node 结点，isLeft 是否为左子树，returnChild 通过此参数返回(左/右)子树
 * 返回值：获取结果
*/
Status getChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryTree &returnChild){
    BinaryTree searchResult;
    int resultCode = searchTree(tree, parentNode.data, searchResult);

    if(resultCode == TRUE){
        returnChild = isLeft ? searchResult->leftChild : searchResult->rightChild;
        return returnChild != NULL;
    }else{
        return ERROR;
    }
}

/**
 * 功能：获取二叉树中某个结点的左子树
 * 参数：tree 二叉树，node 结点，returnChild 通过此参数返回左子树
 * 返回值：获取结果
*/
Status getLeftChild(BinaryTree &tree, BinaryNode parentNode, BinaryTree &returnChild){
    return getChild(tree, parentNode, TRUE, returnChild);
}

/**
 * 功能：获取二叉树中某个结点的右子树
 * 参数：tree 二叉树，node 结点，returnChild 通过此参数返回右子树
 * 返回值：获取结果
*/
Status getRightChild(BinaryTree &tree, BinaryNode parentNode, BinaryTree &returnChild){
    return getChild(tree, parentNode, FALSE, returnChild);
}

/**
 * 功能：获取二叉树中某个结点的左兄弟
 * 参数：tree 二叉树，node 结点，returnSibling 通过此参数返回其右兄弟
 * 返回值：获取结果，如果该结点为二叉树的左子孙或没有左兄弟则返回空
*/
Status getLeftSibling(BinaryTree &tree, BinaryNode parentNode, BinaryNode &returnSibling){
    BinaryTree returnTree;
    Status resultCode = getChild(tree, parentNode, TRUE, returnTree);

    if(resultCode == TRUE){
        returnSibling = *returnTree;
        return TRUE;
    }

    return FALSE;
}

/**
 * 功能：获取二叉树中某个结点的右兄弟
 * 参数：tree 二叉树，node 结点，returnSibling 通过此参数返回其右兄弟
 * 返回值：获取结果，如果该结点为二叉树的右子孙或没有右兄弟则返回空
*/
Status getRightSibling(BinaryTree &tree, BinaryNode parentNode, BinaryNode &returnSibling){
    BinaryTree returnTree;
    Status resultCode = getChild(tree, parentNode, FALSE, returnTree);

    if(resultCode == TRUE){
        returnSibling = *returnTree;
        return TRUE;
    }

    return FALSE;
}

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
        //查找其父节点
        BinaryTree searchResult;
        Status resultCode = searchTree(tree, parentNode.data, searchResult);
        if(resultCode == TRUE){
            //查找成功 将要插入的子树赋值给父结点的左子树或右子树
            if(isLeft){
                searchResult->leftChild = childTree;
            }else{
                searchResult->rightChild = childTree;
            }
            return TRUE;
        }else{
            //查找失败 返回FALSE
            return FALSE;
        }
    }
}

/**
 * 功能：删除二叉树中某个结点的左子树或右子树
 * 参数：tree 二叉树，parentNode 结点，isLeft 左1右0
 * 返回值：删除结果
*/
Status deleteChild(BinaryTree &tree, BinaryNode parentNode, Boolean isLeft, BinaryNode &returnNode){
    if(isEmptyBinaryTree(tree)){
        return ERROR;
    }else{
        // 查找父结点
        BinaryTree searchResult;
        int resultCode = searchTree(tree, parentNode.data, searchResult);

        if(resultCode == TRUE){
            // 将父结点的左子树或者右子树赋值给参数returnTree
            BinaryTree returnTree = (isLeft ? searchResult->leftChild : searchResult->rightChild);
            if(returnTree != NULL)
                returnNode = *returnTree;

            // 随后删除对应子树并返回TRUE
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
    // 动态申请一个结点 并给其数据域赋值 指针域设为NULL
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
        inOrderTraverse(tree->leftChild);
        printf("%d",tree->data);
        inOrderTraverse(tree->rightChild);
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
        postOrderTraver(tree->rightChild);
        postOrderTraver(tree->leftChild);
        return TRUE;
    }
}

/**
 * 功能：层级遍历
 * 参数：tree 二叉树
 * 返回值：遍历结果
*/
Status levelOrderTraverse(BinaryTree &tree);
/*=====================================函数定义=====================================*/