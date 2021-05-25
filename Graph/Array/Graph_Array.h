#include "stdlib.h"

#define Status  int
#define TRUE    1
#define FALSE   0

#define MAX_VERTEX_NUMBER           20

#define VertexElementType           int
#define VertexRelationshipType      int
#define InfoType                    int

typedef enum {
    Digraph,                //有向图
    DirectedNetwork,        //有向网
    Undigraph,              //无向图
    UndirectedNetwork       //无向网
} GraphKind; //图的类型

typedef struct Vertex{
    VertexElementType data;                 //顶点值
} Vertex;    //顶点

typedef struct Arc{
    VertexRelationshipType vrType;          //顶点关系类型
    InfoType *info;                         //弧相关信息的指针
} AdjacentMatrix[MAX_VERTEX_NUMBER][MAX_VERTEX_NUMBER];//邻接矩阵

typedef struct{
    Vertex vertexs[MAX_VERTEX_NUMBER];      //顶点向量（顶点）
    AdjacentMatrix arcs;                    //邻接矩阵（关系）
    int vertexNumber, arcNumber;            //图的当前顶点数和弧数
    GraphKind kind;                         //图的种类标志
} Graph;    //图

/**
 * 功能：创建图
 * 参数：graph 图结构体，vertex 顶点集合，vr顶点关系集合
 * 返回值：创建结果
*/
Status createGraph(Graph &graph, Vertex vertex, VertexRelationship vr);

/**
 * 功能：销毁图
 * 参数：graph 图结构体
 * 返回值：销毁结果
*/
Status destoryGraph(Graph);

/**
 * 功能：返回该顶点在图中位置  ？
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：若存在顶点vertex则返回该顶点在图中位置，否则返回其他信息
*/
Status locateVertex(Graph &graph, Vertex vertex);

/**
 * 功能：获取顶点的值
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：获取结果
*/
Status getVertex(Graph &graph, Vertex vertex);

/**
 * 功能：添加顶点
 * 参数：graph 图结构体，vertex 顶点集合
 * 返回值：添加结果
*/
Status putVertex(Graph &graph, Vertex vertex,Value);

/**
 * 功能：获取vertex的第一个邻接顶点
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：获取结果
*/
Status firstAdjacent(Graph &graph, Vertex v);

/**
 * 功能：获取v的下一个邻接顶点
 * 参数：graph 图结构体，v 顶点，w 是v的邻接顶点
 * 返回值：获取结果
*/
Status nextAdjacent(Graph &graph, Vertex v, Vertex w);

/**
 * 功能：插入新顶点
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：插入结果
*/
Status insertVertex(Graph &graph, Vertex vertex);

/**
 * 功能：删除顶点及其相关的弧
 * 参数：graph 图结构体，vertex 顶点
 * 返回值：删除结果
*/
Status deleteVertex(Graph &graph, Vertex vertex);

/**
 * 功能：插入新弧
 * 参数：graph 图结构体，v 顶点，w 顶点
 * 返回值：插入结果
*/
Status insertArc(Graph &graph, Vertex v, Vertex w);

/**
 * 功能：删除弧
 * 参数：graph 图结构体，v 顶点，w 顶点
 * 返回值：删除结果
*/
Status deleteArc(Graph &graph, Vertex v, Vertex w);

/**
 * 功能：创建图
 * 参数：graph 图结构体，vertex 顶点集合，vr顶点关系集合
 * 返回值：创建结果
*/
Status DFSTraverse();

/**
 * 功能：创建图
 * 参数：graph 图结构体，vertex 顶点集合，vr顶点关系集合
 * 返回值：创建结果
*/
Status BFStRAVERSE();

