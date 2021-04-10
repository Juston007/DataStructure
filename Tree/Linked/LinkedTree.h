#include "stdio.h"
#include "stdlib.h"
#include "LinearList_Sequence_Tree.h"


//Written by Juston
//2021/04/09 19:54

/**
 * 1.树
 * 树是一种非线性（一对多）结构，树与线性（一对一）表的逻辑关系不同
 * 
 * 树是 n (n>=0) 个节点（元素）构成的有限集合。
 * 当 n = 0 时，这颗树被称为空树
 * 在一颗非空树中，有且只有一个特殊的节点称为树的根节点，根节点没有前驱节点;
 * 
 * 当 n > 1 时，除根节点之外的其余元素被分成 m (m>0) 个互相相交的集合T1,T2,...,Tm
 * 其中每一个集合Ti(1<=i<=m)本身又是一棵树；树T1,T2,...,Tm称为这个根节点的子树
 * 
 * 2.结点 是数据元素的别名
 * 3.集合 线性表对应的是序列，树对应的是集合
 * 4.结点的度 树中结点所拥有的子树的个数
 * 5.树的度 树中各结点度的最大值  二叉树的度为2
 * 6.叶子节点（终端结点） 度为0的结点
 * 7.分支节点（非终端结点） 度不为0的结点
 * 8.孩子 树中一个结点的子树的根节点
 * 9.双亲 树中一个孩子结点的上层节点（唯一）
 * 10.兄弟 具有同一个双亲的孩子结点互成为兄弟
 * 11.子孙 一个结点的所有子树中的结点称之为该结点的子孙结点
 * 12.祖先 从根结点到该结点所经分支上的所有结点
 * 13.层数 根节点的层数规定为1，其余节点的层数等于它的双亲结点的层数加一
 * 14.深度 所有节点的最大层次
 * 15.堂兄弟 双亲在同一层，且双亲不同的结点互为堂兄弟
 * 16.有序树 
 * 17.森林 m(m>=0)棵不相交的树的集合称为森林
*/



/*=====================================宏定义=====================================*/
#define Status       int

#define OK           2

#define TRUE         1
#define FALSE        0

#define ERROR       -3
#define INFEASIBLE  -2
#define OVERFLOW    -1

#define INIT_SON_TREE_SIZE          10      //子树最大数量
#define INCREAMENT_SON_TREE_SIZE    10      //子树数量的增量


#define ElementType int
/*=====================================宏定义=====================================*/


/*=====================================结构体=====================================*/
typedef struct LinkedTreeNodeStruct{
    ElementType data;                          //数据域 存储着结点的值
    SequenceList child;                            //结点的度 该结点所拥有的子树的个数
}Node,*Tree;
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/

/**
 * 功能：初始化树  没有头节点
 * 参数：tree 树
 * 返回值：初始化结果
*/
Status initTree(Tree &tree){
    tree = NULL;
    return OK;
}

/**
 * 功能：销毁树
 * 参数：tree 树
 * 返回值：销毁结果
*/
void destoryTree(Tree &tree);

/**
 * 功能：创建树
 * 参数：tree 树
 * 返回值：创建结果
*/
void createTree(Tree &tree);

/**
 * 功能：清空树
 * 参数：tree 树
 * 返回值：清空结果
*/
void clearTree(Tree &tree);

/**
 * 功能：是否为空树
 * 参数：tree 树
 * 返回值：是返回TRUE 否则返回FALSE
*/
Status isEmpty(Tree tree){
    return tree == NULL;
}

/**
 * 功能：获取树的深度
 * 参数：tree 树
 * 返回值：树的深度
*/
int getTreeDepth(Tree tree);

/**
 * 功能：获取树的根节点
 * 参数：tree 被初始化的树 returnRoot 通过此参数返回根节点
 * 返回值：获取结果
*/
int getRoot(Tree tree, Node &returnRoot);

/**
 * 功能：获取树中某个节点的值
 * 参数：tree 树 node 节点 returnElement 通过此参数返回节点的值
 * 返回值：获取结果
*/
Status getValue(Tree tree, Node node, ElementType &returnElement);

/**
 * 功能：给树中某个节点赋值
 * 参数：tree 树 node 节点 value 要赋的值
 * 返回值：赋值结果
*/
Status assign(Tree &tree, Node node, ElementType value);

/**
 * 功能：获取树中某个节点的双亲
 * 参数：tree 被初始化的树 node 节点 returnParent 通过此参数返回节点的双亲
 * 返回值：获取结果
*/
Status getParent(Tree tree, Node node, Node &returnParent);

/**
 * 功能：获取某个节点的左子树
 * 参数：tree 树 node 当前节点 returnLeftChild 通过此参数返回左子树
 * 返回值：获取结果
*/
Status getLeftChild(Tree tree, Node node, Node returnLeftChild);

/**
 * 功能：获取某个节点的右子树
 * 参数：tree 树 node 当前节点 returnRightChild 通过此参数返回右子树
 * 返回值：获取结果
*/
Status getRightChild(Tree tree, Node node, Node returnRightChild);

/**
 * 功能：搜索树中某个结点的元素值
 * 参数：tree 树 element 要搜索的元素 returnNode 通过此参数返回节点的指针
 * 返回值：搜索结果
*/
Status searchTree(Tree tree, ElementType element, Tree &returnTree){
    //如果为空的话直接返回FALSE
    if(isEmpty(tree)){
        return FALSE;
    }
    else{
        //如果该结点的数据和我们要查找的数据相同那么返回其指针
        if(tree->data == element){
            returnTree = tree;
            return TRUE;
        }
        else{
            //否则的话递归 寻找其第i个子节点是否符合
            int length = getListLength(tree->child);

            for(int i = 0;i < length;i++){
                //获取第i个子结点的指针
                ListElementType returnNodePtr;
                int code = getListElement(tree->child,i,returnNodePtr);
                //printf("code = %d returnNodePtr %d\n", code, returnNodePtr);

                if(code == OK){
                    code = searchTree((Node *)returnNodePtr, element, returnTree);
                    if(code == TRUE)
                        return TRUE;
                }
            }

            return FALSE;
        }
    }
}

/**
 * 功能：在某个节点插入子树
 * 参数：tree 树 node 当前节点 i 所指节点的度+1 sonTree 子树
 * 返回值：插入结果
*/
Status insertChild(Tree &tree, Node &node,int i, Tree &sonTree){
    return OK;
}

/**
 * 功能：在某个节点插入子树
 * 参数：tree 树 parentNode 插入结点的父节点 value 要插入的结点元素值 i 所指节点的度+1 returnNode 通过此参数返回新生成的结点
 * 返回值：插入结果
*/
Status insertNode(Tree &tree, Node &parentNode, ElementType value, int i, Node &returnNode){

    //如果为空树那么新建一个结点给数据赋值并返回
    if(isEmpty(tree)){
        tree = (Node *)malloc(sizeof(Node));

        if(tree == NULL)
            exit(0);

        tree->data = value;
        //初始化子节点顺序表
        initList(tree->child);
        returnNode = *tree;

        printf("create tree  node[%d] address %x     newNode.child = %x\n", value, (void*)tree, &(tree->child));
        
        return OK;
    }else{
        //寻找其父结点是否存在
        Tree searchResult;
        searchTree(tree, parentNode.data, searchResult);

        //如果其父节点不存在树中那么返回ERROR
        if(searchResult == NULL){
            return ERROR;
        }
        else{
            //否则新建一个结点给数据域赋值并返回
            Tree newNode = (Node *)malloc(sizeof(Node));
            printf("insert  new node[%d] address %x     newNode.child = %x\n", value, (void*)newNode, &(newNode->child));
            
            if(&newNode == NULL)
                exit(0);

            initList(newNode->child);
            newNode->data = value;
            returnNode = *newNode;

            //将新结点插入其父结点的数据域顺序表中
            return listInsertElement(parentNode.child,i,(void*)newNode);
        }
    }
}

/**
 * 功能：删除某个节点的子树
 * 参数：tree 树 node 当前节点 i 节点的度
 * 返回值：删除结果
*/
Status deleteChild(Tree &tree, Node &node,int i){
    return OK;
}


/**
 * 功能：遍历树
 * 参数：tree 树 void Visit() 遍历函数
 * 返回值：遍历结果
*/
Status traverseTree(Tree tree, void Visit());
/*=====================================函数声明=====================================*/