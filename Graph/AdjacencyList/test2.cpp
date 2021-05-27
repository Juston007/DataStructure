#include "stdio.h"
#include "Graph_Adjacency_List.h"

//遍历顶点所有信息
void traverseVertex(LinkedList vertexList){
    printf("\n======================start========================\n");
    if(isEmpty(vertexList) == TRUE){
        printf("There are no vertices.\n");
    }else{
        void *temp;
        int vertexLength = getLength(vertexList);

        for(int i = 0;i < vertexLength;i++){
            getElement(vertexList, i, temp);

            Vertex *vertex = (Vertex *)temp;

            //打印顶点值
            printf("vertex data = %c\n", vertex->data);

            
            //打印顶点相关的边
            int arcLength = getLength(vertex->arcs);
            for(int j = 0;j < arcLength;j++){
                getElement(vertex->arcs, j, temp);
                Arc *arc = (Arc *)temp;
                printf("Adjacency Vertex[%c] = %#x", arc->adjacencyVertex->data, arc->adjacencyVertex);

                if(arc->info != NULL){
                    printf("     Info     %d\n", *(arc->info));
                }else{
                    printf("     not have info\n");
                }
            }

            if(arcLength <= 0){
                printf("There are no arc.\n");
            }

            printf("******************end*****************************\n");
        }
    }
    printf("======================end========================\n");
}

//打印所有顶点的地址
void printAllVertexAddress(LinkedList vertexList){
    if(isEmpty(vertexList) == TRUE){
        printf("There are no vertices.\n");
    }else{
        void *temp;
        int vertexLength = getLength(vertexList);

        printf("\n======================start========================\n");
        for(int i = 0;i < vertexLength;i++){
            getElement(vertexList, i, temp);
            Vertex *vertex = (Vertex *)temp;
            printf("Vertex[%c] address = %#x\n", vertex->data, vertex);
        }
        printf("======================end========================\n");
    }
}

int main(){
    Graph graph;
    Vertex *vertexG, *vertexH, *vertexD, *vertexB, *vertexF;
    Vertex testVertex;
    testVertex.data = 'L';

    //创建无向图 测试通过
    createGraph(graph, NULL, Digraph);
    traverseVertex(graph.vertices);

    //添加顶点 测试通过
    addVertex(graph, 'G', vertexG);
    addVertex(graph, 'H', vertexH);
    addVertex(graph, 'D', vertexD);
    addVertex(graph, 'B', vertexB);
    addVertex(graph, 'F', vertexF);

    //打印所有顶点地址
    printAllVertexAddress(graph.vertices);
    traverseVertex(graph.vertices);

    //添加边 测试通过
    addArc(graph, vertexG, vertexH, NULL);
    addArc(graph, vertexH, vertexD, NULL);
    addArc(graph, vertexD, vertexH, NULL);
    addArc(graph, vertexD, vertexB, NULL);
    addArc(graph, vertexD, vertexF, NULL);
    addArc(graph, vertexB, vertexF, NULL);
    addArc(graph, vertexG, vertexF, NULL);
    traverseVertex(graph.vertices);

    //删除顶点 测试通过
    Vertex test;
    deleteVertex(graph, vertexD);
    traverseVertex(graph.vertices);

    // //删除边 测试通过
    // Vertex *tail, *head;
    // tail = vertexH;
    // head = vertexG;
    // Status deleteResult = deleteArc(graph, tail, head);
    // printf("deleteArc  tail[%c]-->head[%c]   deleteResult = %d\n",tail != NULL ? tail->data : '-', head != NULL ? head->data : '-', deleteResult);

    // traverseVertex(graph.vertices);


    // //定位顶点位置 测试通过
    // Vertex *tempVertexPointer = vertexF;
    // int index = locateVertexIndex(graph, tempVertexPointer);
    // printf("locateVertexIndex    [%c]  %d", index >= 0 ? tempVertexPointer->data :'0', index);

    // //获取顶点指针 测试通过
    // char ch = 'H';
    // Vertex *tempVertexPointer = getVertexPointer(graph, ch);
    // printf("getVertexPointer    [%c]  %#x", ch, tempVertexPointer);

    // //修改顶点值 测试通过
    // Vertex test;
    // putVertex(graph, &test, 'C');

    return 1;
}