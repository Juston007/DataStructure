#include "stdlib.h"
#include "LinearList_Linked_Graph.h"

/*=====================================宏定义=====================================*/
#define Status  int
#define TRUE    1
#define FALSE   0

#define InfoType    int
#define VertexType  char

/*=====================================结构体=====================================*/
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
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
Status deleteArc(Graph &graph, Vertex *tail, Vertex *head);
/*=====================================函数声明=====================================*/


/*=====================================函数定义=====================================*/
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

    //初始化顶点以及边的数目
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
 * 功能：返回该顶点在图中位置  （位置并不绝对，可能会发生变化）
 * 参数：graph 图结构体，vertex 顶点指针
 * 返回值：若存在顶点vertex则返回该顶点在图中位置，否则返回-1
*/
int locateVertexIndex(Graph &graph, Vertex *vertex){
    return findElement(graph.vertices, vertex);
}

/**
 * 功能：根据顶点的值获取顶点的指针
 * 参数：graph 图结构体，value 顶点值
 * 返回值：顶点的指针
*/
Vertex * getVertexPointer(Graph &graph, VertexType value){
    void *temp = NULL;
    Vertex *tempVertex;
    int length = getLength(graph.vertices);

    //如果顶点集合的第i个顶点
    for(int i = 0;i < length;i++){
        getElement(graph.vertices, i, temp);

        //第i个顶点的数据域与用户要找的相同
        tempVertex = (Vertex *)temp;
        if(tempVertex->data == value){
            //那么返回顶点的指针
            return tempVertex;
        }
    }

    //循环结束都没有找到用户要找的，直接返回空
    return NULL;
}

/**
 * 功能：对顶点的数据域赋值
 * 参数：graph 图结构体，vertex 顶点指针，value 数据
 * 返回值：赋值结果
*/
Status putVertex(Graph &graph, Vertex *vertex, VertexType value){
    if(vertex == NULL){
        return ERROR;
    }

    //查询该顶点是否存在顶点集合中
    int index = findElement(graph.vertices, vertex);
    if(index >= 0){
        //修改数据域
        vertex->data = value;
        return TRUE;
    }else{
        return FALSE;
    }
}

/**
 * 功能：获取某顶点的第一个邻接顶点
 * 参数：graph 图结构体，vertex 顶点指针
 * 返回值：获取结果
*/
Vertex * firstAdjacency(Graph &graph, Vertex *v){
    if(isEmpty(graph.vertices)){
        return NULL;
    }else{
        //获取下标为0的边
        void *temp;
        getElement(v->arcs, 0, temp);

        //提取出边中的顶点信息并返回
        Arc *arc = (Arc *)temp;
        return arc->adjacencyVertex;
    }
}

/**
 * 功能：获取顶点v的邻接顶点w的下一个邻接顶点
 * 参数：graph 图结构体，v 顶点指针，w 是v的邻接顶点
 * 返回值：获取结果
*/
Vertex * nextAdjacency(Graph &graph, Vertex *v, Vertex *w){
    if(isEmpty(graph.vertices)){
        return NULL;
    }else{
        //获取下标为0的边
        void *temp;
        Arc *tempArc;
        int flag = FALSE;

        int arcLength = getLength(v->arcs);
        for(int i = 0;i < arcLength;i++){
            getElement(v->arcs, i, temp);
            tempArc = (Arc *)temp;

            if(flag == TRUE){
                return tempArc->adjacencyVertex;
            }

            if(tempArc->adjacencyVertex == w){
                flag = TRUE;
            }
        }
 
        return NULL;
    }
}

/**
 * 功能：插入新顶点
 * 参数：graph 图结构体，value 顶点数据，returnVertex 通过此参数返回刚创建的顶点的指针
 * 返回值：插入结果
*/
Status addVertex(Graph &graph, VertexType value, Vertex *&returnVertex){
    //生成一个新顶点
    Vertex *newVertex = (Vertex *)malloc(sizeof(Vertex));

    if(newVertex == NULL){
        exit(0);
    }

    //初始化其数据域和指针域
    newVertex->data = value;
    initList(newVertex->arcs);

    //将新顶点添加到顶点集合中
    if(insertElement(graph.vertices, graph.vertexNumber, newVertex) == OK){
        //将新顶点指针返回；并计算顶点数目
        returnVertex = newVertex;
        graph.vertexNumber++;
        return TRUE;
    }else{
        return ERROR;
    }
}

/**
 * 功能：删除顶点及其相关的弧
 * 参数：graph 图结构体，vertex 待删除顶点的指针
 * 返回值：删除结果
*/
Status deleteVertex(Graph &graph, Vertex *deleteVertex){
    //要删除的顶点不存在
    if(deleteVertex == NULL){
        return ERROR;
    }else{
        //找到要删除顶点的下标
        int index = findElement(graph.vertices, deleteVertex);
        void *temp;

        //如果顶点存在
        if(index >= 0){
            //删除弧尾为该顶点的边
            int deleteVertexArcLength = getLength(deleteVertex->arcs);
            while(!isEmpty(deleteVertex->arcs)){
                //这里返回的是删除的边的指针   
                //调用deleteArc函数时，会操作顶点的邻接表 可能会导致错误 
                //只删除第0个，也可从后往前删除
                Status res = getElement(deleteVertex->arcs, 0, temp);
                deleteArc(graph, deleteVertex, ((Arc *)temp)->adjacencyVertex);
            }

            Vertex *tmepVertex;
            int vertexLength = getLength(graph.vertices);
            //删除弧头为该顶点的边
            for(int i = 0;i < vertexLength;i++){
                getElement(graph.vertices, i, temp);

                tmepVertex = (Vertex *)temp;
                deleteArc(graph, tmepVertex, deleteVertex);
            }

            //删除顶点并计算顶点数目
            deleteElement(graph.vertices, index, temp);
            graph.vertexNumber--;

            return TRUE;            
        }else{
            return FALSE;
        }
    }
}

/**
 * 功能：插入新边（弧）
 * 参数：graph 图结构体，tail 弧尾顶点指针，head 弧头顶点指针
 * 返回值：插入结果
*/
Status addArc(Graph &graph, Vertex *tail, Vertex *head, InfoType *info){
    int tailIndex = locateVertexIndex(graph, tail);
    int headIndex = locateVertexIndex(graph, head);

    //判断两个顶点是否存在顶点集合中
    if((tailIndex >= 0) && (headIndex >= 0)){

        //不允许自己指向自己
        if(tailIndex == headIndex){
            return ERROR;
        }

        //构造一个边并添加到邻接表中
        //tail-->head
        Arc *arcTailHead = (Arc *)malloc(sizeof(Arc));
        arcTailHead->adjacencyVertex = head;
        arcTailHead->info = info;
        insertElement(tail->arcs, 0, arcTailHead);

        //如果是无向图（网），那么另一个顶点也需要添加这条边的信息
        if((graph.kind == Undigraph) || (graph.kind == UndirectedNetwork)){
            //构造一个边并添加到邻接表中
            //head-->tail
            Arc *arcHeadTail = (Arc *)malloc(sizeof(Arc));
            arcHeadTail->adjacencyVertex = tail;
            arcHeadTail->info = info;
            insertElement(head->arcs, 0, arcHeadTail);
        }

        //图的边数目加一
        graph.arcNumber++;

        return TRUE;
    }else{
        return ERROR;
    }
}

/**
 * 功能：删除边（弧）
 * 参数：graph 图结构体，tail 弧尾顶点指针，head 弧头顶点指针
 * 返回值：删除结果
*/
Status deleteArc(Graph &graph, Vertex *tail, Vertex *head){
    int tailIndex = locateVertexIndex(graph, tail);
    int headIndex = locateVertexIndex(graph, head);

    //判断两个顶点是否存在顶点集合中
    if((tailIndex >= 0) && (headIndex >= 0)){

        if(tailIndex == headIndex){
            return ERROR;
        }

        void *temp;
        int tailArcLength = getLength(tail->arcs);
        int headArcLength = getLength(head->arcs);

        //printf("deleteArc  tail[%c]-->head[%c]\n",tail != NULL ? tail->data : '-', head != NULL ? head->data : '-');
        int isFound = FALSE;
        //找到（弧尾为tail，弧头为head）的边
        for(int i = 0;i < tailArcLength;i++){
            getElement(tail->arcs, i, temp);

            //找到对应边并删除
            if(((Arc *)temp)->adjacencyVertex == head){
                deleteElement(tail->arcs, i, temp);
                isFound = TRUE;
                //printf("delete\n");
                break;
            }
        }

        if(isFound != TRUE){
            return INFEASIBLE;
        }

        //边的数目减一
        graph.arcNumber--;

        //如果是无向图的话那么需要双向删除
        if((graph.kind == Undigraph) || (graph.kind == UndirectedNetwork)){
            //找到（弧尾为head，弧头为tail）的边
            for(int i = 0;i < headArcLength;i++){
                getElement(head->arcs, i, temp);

                //找到对应边并删除
                if(((Arc *)temp)->adjacencyVertex == tail){
                    deleteElement(head->arcs, i, temp);
                    break;
                }
            }
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
/*=====================================函数定义=====================================*/