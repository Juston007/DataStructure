#include "stdio.h"
#include "Graph_Adjacency_List.h"

int main(){
    Graph graph;
    LinkedList vertices, arcG, arcH, arcI, arcK;

    //初始化列表
    initList(vertices);
    initList(arcG);
    initList(arcH);
    initList(arcI);
    initList(arcK);

    //初始化顶点
    Vertex vertexG = {'G', arcG};
    Vertex vertexH = {'H', arcH};
    Vertex vertexI = {'I', arcI};
    Vertex vertexK = {'K', arcK};

    //初始化边 格式：arc 从哪来 到哪去
    Arc arcGH = {&vertexH, NULL};
    Arc arcGK = {&vertexK, NULL};
    Arc arcGI = {&vertexI, NULL};

    Arc arcHG = {&vertexG, NULL};
    Arc arcHK = {&vertexK, NULL};

    Arc arcKH = {&vertexH, NULL};
    Arc arcKG = {&vertexG, NULL};

    Arc arcIG = {&vertexG, NULL};
    
    //添加边到对应的边列表中

    //add arc G
    insertElement(arcG, 0, &arcGH);
    insertElement(arcG, 1, &arcGK);
    insertElement(arcG, 2, &arcGI);

    //add arc H
    insertElement(arcH, 0, &arcHG);
    insertElement(arcH, 1, &arcHK);

    //add arc K
    insertElement(arcK, 0, &arcKH);
    insertElement(arcK, 1, &arcKG);

    //add arc I
    insertElement(arcI, 0, &arcIG);

    //添加边到顶点中
    vertexG.arcs = arcG;
    vertexH.arcs = arcH;
    vertexI.arcs = arcI;
    vertexK.arcs = arcK;

    //添加顶点到顶点集合中
    insertElement(vertices, 0, &vertexG);
    insertElement(vertices, 1, &vertexH);
    insertElement(vertices, 2, &vertexI);
    insertElement(vertices, 3, &vertexK);

    /*************************创建图********************************/
    Status createStatus = createGraph(graph, vertices, Undigraph);
    printf("createGraph     createStatus %d\n", createStatus);

    /*************************定位顶点******************************/
    Status locateIStatus = locateVertex(graph, &vertexI);
    printf("locateVertex     locateIStatus %d\n", locateIStatus);

    Status locateKStatus = locateVertex(graph, &vertexK);
    printf("locateVertex     locateKStatus %d\n", locateKStatus);

    Status locateHStatus = locateVertex(graph, &vertexH);
    printf("locateVertex     locateHStatus %d\n", locateHStatus);

    Status locateGStatus = locateVertex(graph, &vertexG);
    printf("locateVertex     locateGStatus %d\n", locateGStatus);

    return 0;
}