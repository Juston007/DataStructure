#include "stdio.h"
#include "Graph_Adjacency_List.h"

/**
 * 功能：将listA中的元素追加到listB之后
 * 参数：
 * 返回值：
*/
void addTo(LinkedList &listA,LinkedList &listB){
    void *temp;
    int j = getLength(listB);
    int length = getLength(listA);

    for(int i = 0;i < length;i++){
        //取出listA中第i个元素
        getElement(listA, i, temp);
        //将其放入listB中的最后一个位置
        insertElement(listB, j++, temp);
    }
}

int getSmallestWeightEdgeIndex(LinkedList arcs){
    if(isEmpty(arcs)){
        return ERROR;
    }else{
        void *temp;
        int minIndex = 0;
        Arc *tempArc, *minArc;

        int arcLength = getLength(arcs);
        for(int i = 0;i < arcLength;i++){
            getElement(arcs, i, temp);
            tempArc = (Arc *)temp;

            if(i == 0){
                minArc = tempArc;
                continue;
            }

            if(*(minArc->info) > *(tempArc->info)){
                minArc = tempArc;
                minIndex = i;
            }
        }

        return minIndex;
    }
}

/**
 * Prim         普里姆算法
 * 
 * 时间复杂度：O(n^2) n为顶点数
 * 与网中的边数无关，因此适用于求边稠密的网的最小生成树
 * 
 * 算法：
 * 假设N=(V，{E})是连通网，TE是N上最小生成树中边的集合。
 * 算法从U = {u0} (u0)∈V，TE = {} 开始
 * 
 * 重复执行下述操作：
 * 在所有u∈U，v∈(V-U)中的边(u,v)∈E中找一条代价最小的边(u0,v0)并入集合TE
 * 同时v0并入U，直到U=V为止；
 * 此时TE中必有n-1条边，则T=(V,{TE})为N的最小生成树
*/
void miniSpanTree_Prim(){

}

/**
 * Kruskal      克鲁斯卡尔算法
 * 
 * 时间复杂度：O(eloge) e为网中边的数目
 * 相对比普里姆算法而言，更适合求边稀疏的网的最小生成树
 * 
 * 算法：
 * 1.令最小生成树初始状态为n个顶点而无边的非连通图，图中每个顶点自成一个连通分量
 * 2.在边集合中选择一个代价最小的边，并从边集合中将其删去
 * 3.若该边依附的顶点位于不同的连通分量，那么将他加入
 * 4.否则略去该边
 * 5.一直重复2、3、4过程，直到所有的顶点都在同一连通分量上为止
*/
void miniSpanTree_Kruskal(Graph &graph){
    Graph miniSpanTree;
    LinkedList vertices = graph.vertices;
    LinkedList arcs;

    initList(arcs);

    //初始化新图
    createGraph(miniSpanTree, NULL, UndirectedNetwork);

    // //复制顶点到最小生成树的新图
    // int vertexLength = getLength(vertices);
    // for(int i = 0;i < vertexLength;i++){
    //     //取出顶点集合的顶点并添加到新图中的顶点集合
    //     void *temp;
    //     getElement(vertices, i, temp);

    //     //拷贝副本永久保存        
    //     Vertex *tempVertex = (Vertex *)temp;
    //     addVertex(miniSpanTree, tempVertex->data, tempVertex);
    //     insertElement(graph.vertices, i, temp);
    // }

    
    //将所有的边都统统添加到一个集合中
    int vertexLength = getLength(vertices);
    for(int i = 0;i < vertexLength;i++){
        void *temp;
        getElement(graph.vertices, i, temp);
        Vertex *tempVertex = (Vertex *)temp;

        int arcLength = getLength(tempVertex->arcs);
        for(int j = 0;j < arcLength;j++){
            getElement(tempVertex->arcs, j, temp);
            insertElement(arcs, j, temp);
        }
    }

    int vertexLength = getLength(vertices);
    //是否被访问
    int *visited = (int *)malloc(vertexLength * sizeof(int));
    for(int i = 0;i < vertexLength;i++) {
        visited[i] = 0;
    }

    void *temp;
    Arc *tempArc;
    for(int i = 0;i < vertexLength;i++){
        //选择权值最小的边
        int minEdgeIndex = getSmallestWeightEdgeIndex(arcs);

        getElement(arcs, minEdgeIndex, temp);
        tempArc = (Arc *)temp;

        
        int index = findElement(vertices, tempArc->adjacencyVertex);
        if(visited[index] == 1){
            continue;
        }

        
    }

}

/**
 * 最小生成树
 * 
 * 假设要在n个城市之间建立通信联络网，则连通n个城市只需要n-1条线路。
 * 最小生成树考虑的是如何在最节省经费的情况下建立这个通信网。
 * 
 * 构造连通网的最小代价生成树 Minimum Cost Spanning Tree 
 * 简称最小生成树
*/


int main(){
    return 0;
}