
#define Status          int
#define TRUE            1
#define FALSE           1

#define ElementType     int

/**
 * 指针标志位 
 * 说明该指针是指向前驱或后继还是指向其孩子
*/
typedef enum PointerTag{
    Link,           //链接
    Thread          //线索
};

/**
 * 线索二叉树的结构体定义
 * 其中指向结点前驱和后继的指针叫做线索
 * 以某种次序遍历使其变为线索二叉树的过程叫做线索化
*/
typedef struct ThreadBinaryNode{
    ElementType data;                       //数据域
    struct ThreadBinaryNode *leftChild;     //指针域 指向左孩子
    struct ThreadBinaryNode *rightChild;    //指针域 指向右孩子
    PointerTag leftTag;                     //左标志位
    PointerTag rightTag;                    //右标志位
} ThreadBinaryNode, ThreadBinaryTree;


Status InOrderTraverse_Thread(ThreadBinaryTree tree){
    return FALSE;
}

Status InOrderThreading(ThreadBinaryTree &tree,ThreadBinaryTree t){
    return FALSE;
}