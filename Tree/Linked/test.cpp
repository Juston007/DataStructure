#include "stdio.h"
#include "LinkedTree.h"

int main(){

    Tree tree;
    Node returnNode, parentNode;

    initTree(tree);
    printf("init tree!\n");

    int code = insertNode(tree, returnNode, 1, 2, returnNode);
    printf("code = %d insert root node element [%d]\n", code, 111);

    code = insertNode(tree, *tree, 11, 0, returnNode);
    printf("code = %d insert element [%d]\n", code, 11);

    code = insertNode(tree, *tree, 12, 1, returnNode);
    printf("code = %d insert element [%d]\n", code, 12);

    code = insertNode(tree, *tree, 13, 2, returnNode);
    printf("code = %d insert element [%d]\n", code, 13);

    
    parentNode = returnNode;

    code = insertNode(tree, parentNode, 111, 0, returnNode);
    printf("code = %d insert element [%d]\n", code, 131);
    
    code = insertNode(tree, parentNode, 112, 1, returnNode);
    printf("code = %d insert element [%d]\n", code, 132);



    parentNode = returnNode;

    code = insertNode(tree, parentNode, 1321, 0, returnNode);
    printf("code = %d insert element [%d]\n", code, 1321);
    
    code = insertNode(tree, parentNode, 1322, 1, returnNode);
    printf("code = %d insert element [%d]\n", code, 1322);




    Tree returnTree = NULL;
    code = searchTree(tree,1,returnTree);
    printf("code = %d    search element [%d]  address %x\n", code, 1,returnTree);
}