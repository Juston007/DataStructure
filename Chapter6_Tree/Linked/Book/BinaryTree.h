#include "stdio.h"
#include "stdlib.h"
#include "Stack_Sequence.h"

//状态
#define Status      int
#define TRUE        1
#define FALSE       0

//数据类型
#define BinaryTreeElementType   int


//二叉树结点结构体定义
typedef struct BinaryTreeNode{
    BinaryTreeElementType data;             //数据
    struct BinaryTreeNode *leftChild;       //左子树
    struct BinaryTreeNode *rightChild;      //右子树
} BinaryTreeNode, *BinaryTree;


/**
 * 功能：前序创建二叉树
 * 参数：tree 树
 * 返回值：创建结果
*/
Status createBinaryTree(BinaryTree &tree){
    char inputChar;
    scanf("%c", &inputChar);

    //如果输入的为字符*  那么说明这个结点为空
    if(inputChar == '*'){
        //将这个结点的指针设置为NULL
        tree = NULL;
        return FALSE;
    }else{
        //否则就去申请一个结点的内存空间作为其子树
        tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        
        //给子树根节点的数据域赋值
        tree->data = inputChar;
        //并递归调用设置其左右子树
        createBinaryTree(tree->leftChild);
        createBinaryTree(tree->rightChild);

        return TRUE;
    }
}

/**
 * 功能：获取二叉树深度
 * 参数：tree 树
 * 返回值：该树的深度
*/
int getTreeDepth(BinaryTree tree){
    if(tree == NULL){
        return 0;
    }else{   
        //本层也算一层 
        int depth = 1;

        //计算左右子树深度
        int leftSubTreeDepth = getTreeDepth(tree->leftChild);
        int rightSubTreeDepth = getTreeDepth(tree->rightChild);

        //得出左右子树中较高的树深度
        depth += leftSubTreeDepth > rightSubTreeDepth ? leftSubTreeDepth : rightSubTreeDepth;
        return depth;
    }
}

/**
 * 功能：先序遍历
 * 参数：tree 树
*/
void PreOrderTraverse(BinaryTree &tree){
    if(tree != NULL){
        printf("%4d",tree->data);
        PreOrderTraverse(tree->leftChild);
        PreOrderTraverse(tree->rightChild);
    }
}

/**
 * 功能：中序遍历
 * 参数：tree 树
*/
void InOrderTraverse(BinaryTree &tree){
    void *pointer;
    SequenceStack stack;

    initStack(stack);
    push(stack, tree);

    while(!isEmpty(stack)){

        //寻找到最左边的指针 沿途的指针依次入栈
        //当寻找到最左边结点的左孩子 肯定是空指针
        while(getTop(stack,pointer) && pointer != NULL){
            push(stack, ((BinaryTree)pointer)->leftChild);
        }

        //栈顶目前是最左边叶子结点的左孩子 也就是空指针 将其退栈
        pop(stack,pointer);

        //如果栈不为空的话
        if(!isEmpty(stack)){
            //再次出栈 出栈的是最左结点
            pop(stack,pointer);
            //打印结点值
            printf("%4d",((BinaryTree)pointer)->data);
            //其右结点入栈  注意，这里原本的最左结点没有再次入栈
            push(stack,((BinaryTree)pointer)->rightChild);
        }
    }
}

/**
 * 功能：交换子树
 * 参数：tree 树
*/
void exchangeSubTree(BinaryTree tree){
    if(tree != NULL){
        BinaryTree temp = tree->rightChild;
        tree->rightChild = tree->leftChild;
        tree->leftChild = temp;

        exchangeSubTree(tree->leftChild);
        exchangeSubTree(tree->rightChild);
    }
}

/**
 * 功能：复制结点
 * 参数：node 结点
 * 返回值：新结点
*/
BinaryTree copyNode(BinaryTree node){
    if(node == NULL){
        return NULL;
    }else{
        BinaryTree newTree = (BinaryTree)malloc(sizeof(BinaryTreeNode));
        newTree->data = node->data;
        newTree->leftChild = node->leftChild;
        newTree->rightChild = node->rightChild;
        return newTree;
    }
}

/**
 * 功能：复制树
 * 参数：source 从哪复制，destination 复制到
 * 返回值：无
*/
void copyBinaryTree(BinaryTree source, BinaryTree &destination){
    if(source == NULL){
        destination = NULL;
    }else{
        //复制到新结点
        BinaryTree newTree = copyNode(source);

        //递归复制左右子树
        copyBinaryTree(source->leftChild, newTree->leftChild);
        copyBinaryTree(source->rightChild, newTree->rightChild);

        //修改目的树的指针
        destination = newTree;
    }
}