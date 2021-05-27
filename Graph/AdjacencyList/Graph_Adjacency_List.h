#include "stdlib.h"
#include "LinearList_Linked_Graph.h"

#define Status  int
#define TRUE    1
#define FALSE   0

#define InfoType    int
#define VertexType  int

/**
 * 图的类型
*/
typedef enum GraphKind{
    Digraph,                //有向图
    DirectedNetwork,        //有向网
    Undigraph,              //无向图
    UndirectedNetwork       //无向网
} GraphKind; 

/**
 * 顶点
*/
typedef struct Vertex{
    VertexType data;                //顶点信息
    LinkedList arcs;                //存储边的列表
} Vertex;

/**
 * 边（弧）
*/
typedef struct Arc{
    Vertex *adjacencyVertex;        //邻接顶点的指针；   注：索引会变，所以改为指针
    //struct ArcNode *nextArc;      //指向下一条弧的指针；注：用链表实现有自带指针域 所以这里弃用
    InfoType *info;                 //该弧相关信息的指针
} Arc;

/**
 * 图
*/
typedef struct Graph{
    LinkedList vertices;            //邻接表
    //AdjaencyList vertices;        //邻接表 用链表实现邻接表  添加删除顶点时，顶点的位置可能会发生改变
    int vertexNumber, arcNumber;    //顶点数目、边（弧）的数目
    GraphKind kind;                 //图的种类
} Graph;

Status deleteArc(Graph &graph, Vertex *tail, Vertex *head);

/**
 * 功能：创建图
 * 参数：graph 图结构体，vertex 顶点集合，kind 图的种类
 * 返回值：创建结果
*/
Status createGraph(Graph &graph, LinkedList vertices, GraphKind kind){

    //设置图的种类
    graph.kind = kind;

    //初始化顶点集合
    initList(graph.vertices);

    graph.vertexNumber = graph.arcNumber = 0;

    //顶点集合为空 不用添加顶点集合
    if(isEmpty(vertices)){
        return TRUE;
    }

    //复制顶点集合到图中
    int vertexLength = getLength(vertices);
    for(int i = 0;i < vertexLength;i++){
        //取出参数中的顶点集合的数据并添加到图中的顶点集合
        void *temp;
        getElement(vertices, i, temp);

        //拷贝副本永久保存        
        Vertex tempVertex = *((Vertex *)temp);
        // Vertex *saveVertex = (Vertex *)malloc(sizeof(Vertex));
        // saveVertex->arcs = tempVertex.arcs;
        // saveVertex->data = tempVertex.data;
        insertElement(graph.vertices, i, temp);

        //计算顶点和边的数目
        graph.arcNumber += getLength(tempVertex.arcs);
        graph.vertexNumber++;
    }

    //如果是无向图，两个顶点共用一条边
    //但是存储时会存储两次，所以边数需要除以2
    if((graph.kind == Undigraph) || (graph.kind == UndirectedNetwork)){
        graph.arcNumber /= 2;
    }

    return TRUE;
}

/**
 * 功能：销毁图
 * 参数：graph 图结构体
 * 返回值：销毁结果
*/
Status destoryGraph(Graph &graph);

/**
 * 功能：返回该顶点在图中位置  可能会发生变化
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：若存在顶点vertex则返回该顶点在图中位置，否则返回-1
*/
int locateVertex(Graph &graph, Vertex *vertex){
    return findElement(graph.vertices, vertex);
}

/**
 * 功能：根据顶点的值获取顶点的指针
 * 参数：graph 图结构体，vertex 顶点值
 * 返回值：顶点的
*/
Vertex * getVertex(Graph &graph, VertexType value){
    int length = getLength(graph.vertices);

    void *temp = NULL;
    for(int i = 0;i < length;i++){
        getElement(graph.vertices, i, temp);

        if(((Vertex *)temp)->data == value){
            return (Vertex *)temp;
        }
    }

    return NULL;
}

/**
 * 功能：对顶点的数据域赋值
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：赋值结果
*/
Status putVertex(Graph &graph, Vertex *vertex, VertexType value){
    if(vertex == NULL){
        return ERROR;
    }

    int index = findElement(graph.vertices, vertex);

    if(index >= 0){
        vertex->data = value;
        return TRUE;
    }else{
        return FALSE;
    }
}

/**
 * 功能：获取vertex的第一个邻接顶点
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：获取结果
*/
Status firstAdjacent(Graph &graph, Vertex v, Vertex &returnAdjacency){
    if(isEmpty(graph.vertices)){
        return FALSE;
    }else{
        void *temp;
        getElement(v.arcs, 0, temp);

        Arc arc = *((Arc*)temp);
        returnAdjacency = *arc.adjacencyVertex;
        return TRUE;
    }
}

/**
 * 功能：获取v的下一个邻接顶点
 * 参数：graph 图结构体，v 顶点，w 是v的邻接顶点
 * 返回值：获取结果
*/
Status nextAdjacent(Graph &graph, Vertex v, Vertex w);

/**
 * 功能：插入新顶点；无视顶点中的邻接表
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：插入结果
*/
Status addVertex(Graph &graph, Vertex *insertVertex){
    if(insertVertex == NULL){
        return FALSE;
    }

    if(findElement(graph.vertices, insertVertex) >= 0){
        return INFEASIBLE;
    }

    initList(insertVertex->arcs);

    if(insertElement(graph.vertices, graph.vertexNumber, insertVertex) == OK){
        graph.vertexNumber++;
        return TRUE;
    }else{
        return ERROR;
    }
}

/**
 * 功能：删除顶点及其相关的弧
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：删除结果
*/
Status deleteVertex(Graph &graph, Vertex *deleteVertex){
    if(deleteVertex == NULL){
        return ERROR;
    }else{
        //找到要删除顶点的下标
        int index = findElement(graph.vertices, deleteVertex);
        if(index >= 0){
            void *temp;
            //删除顶点
            deleteElement(graph.vertices, index, temp);

            //删除顶点相关联的边
            while(!isEmpty(deleteVertex->arcs)){
                deleteElement(deleteVertex->arcs, 0, temp);
                deleteArc(graph, deleteVertex, (Vertex *)temp);
            }
            return TRUE;            
        }else{
            return FALSE;
        }
    }
}

/**
 * 功能：插入新边（弧）
 * 参数：graph 图结构体，tail 顶点，head 顶点
 * 返回值：插入结果
*/
Status addArc(Graph &graph, Vertex *tail, Vertex *head){
    int tailIndex = locateVertex(graph, tail);
    int headIndex = locateVertex(graph, head);

    if((tailIndex >= 0) && (headIndex >= 0)){
        insertElement(tail->arcs, 0, head);
        return TRUE;
    }else{
        return ERROR;
    }
}

/**
 * 功能：删除边（弧）
 * 参数：graph 图结构体，v 顶点，w 顶点
 * 返回值：删除结果
*/
Status deleteArc(Graph &graph, Vertex *tail, Vertex *head){
    int tailIndex = locateVertex(graph, tail);
    int headIndex = locateVertex(graph, head);

    if((tailIndex >= 0) && (headIndex >= 0)){
        void *temp;
        deleteElement(tail->arcs, headIndex, temp);

        //如果是无向图的话那么需要双向删除
        if((graph.kind == Undigraph) || (graph.kind == UndirectedNetwork)){
            deleteElement(head->arcs, tailIndex, temp);
        }
        return TRUE;
    }else{
        return ERROR;
    }
}

/**
 * 功能：Depth First Search 深度优先搜索
 * 参数：graph 图结构体，vertex 顶点集合，vr顶点关系集合
 * 返回值：创建结果
*/
Status DFSTraverse();

/**
 * 功能：Breadth First Search 广度优先搜索
 * 参数：graph 图结构体，vertex 顶点集合，vr顶点关系集合
 * 返回值：创建结果
*/
Status BFSTraverse();