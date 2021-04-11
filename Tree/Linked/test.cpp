#include "stdio.h"
#include "LinkedTree.h"

void printTreeAllElement(Tree tree);

int main(){

    Tree tree;
    Node parentNode, returnNode;

    initTree(tree);
    printf("init tree!\n\n");
    //printf("parentNode address %x   returnNode address %x\n", &parentNode, &returnNode);


    int code = insertNode(tree, returnNode, 1, 2, returnNode);
    printf("code = %d insert root node element [%d]\n\n", code, 1);

    printTreeAllElement(tree);
    printf("\n\n");



    code = insertNode(tree, *tree, 11, 0, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 11);

    code = insertNode(tree, *tree, 12, 1, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 12);

    code = insertNode(tree, *tree, 13, 2, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 13);

    printTreeAllElement(tree);
    printf("\n\n");


    
    parentNode = returnNode;

    code = insertNode(tree, parentNode, 131, 0, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 131);
    
    code = insertNode(tree, parentNode, 132, 1, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 132);

    Node deleteNode;
    code = deleteChild(tree, parentNode, 0, deleteNode);
    printf("code = %d delete element [%d]\n\n", code, deleteNode.data);

    printTreeAllElement(tree);
    printf("\n\n");



    parentNode = returnNode;

    //printf("parentNode address %x   returnNode address %x\n", &parentNode, &returnNode);

    code = insertNode(tree, parentNode, 1321, 0, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 1321);
    
    code = insertNode(tree, parentNode, 1322, 1, returnNode);
    printf("code = %d insert element [%d]\n\n", code, 1322);

    printTreeAllElement(tree);
    printf("\n\n");


/*
    Tree returnTree = NULL;
    code = searchTree(tree,1321,returnTree);
    printf("code = %d    search element [%d]  address %x\n\n", code, 1321,returnTree);*/



    Tree sonTree = (Node *)malloc(sizeof(Node));
    sonTree->data = 1323;
    initList(sonTree->child);
    
    code = insertChild(tree, parentNode, 2, sonTree);
    printf("code = %d insert element [%d]\n\n", code, 1323);

    printTreeAllElement(tree);
    printf("\n\n");


    /* Search Tree */
    Tree returnTree = NULL;
    code = searchTree(tree,1323,returnTree);
    printf("code = %d    search element [%d]  address %x\n\n\n", code, 1323,returnTree);
    

    Node deleteNode2;
    deleteNode2.data = 1323;

    code = deleteChild(tree, parentNode, deleteNode2);
    printf("code = %d delete element [%d]\n\n", code, deleteNode2.data);

    printTreeAllElement(tree);
    printf("\n\n");

    returnTree = NULL;
    code = searchTree(tree,1323,returnTree);
    printf("code = %d    search element [%d]  address %x\n\n\n", code, 1323,returnTree);

    Node node3;
    node3.data = 132;
    Tree returnParentNode = NULL;
    code = getParentNode(tree,NULL, node3, returnParentNode);
    printf("code = %d get [%d] parent node [%x]\n\n", code, node3.data, returnParentNode);


    Tree returnLeftTree;
    Node node4;
    node4.data = 1;
    int position = 3;
    code = getChild(tree, node4, position, returnLeftTree);
    printf("code = %d get [%d] position[%d] tree [%x]\n\n", code, node4.data, position, returnLeftTree);

    Node node5;
    node5.data = 1323;
    int assignValue = 999;
    code = assign(tree, node5, assignValue);
    printf("code = %d assign [%d] value [%d]\n\n", code, node5.data, assignValue);
    printTreeAllElement(tree);
    printf("\n\n");
}

void printTreeAllElement(Tree tree){
    int length = getListLength(tree->child);

    for(int i = 0;i < length;i++){
        ListElementType sonTreePtr;
        getListElement(tree->child, i, sonTreePtr);

        printTreeAllElement((Tree)sonTreePtr);
    }

    printf("%7d",tree->data);
}