#include "stdio.h"
#include "BinaryTree.h"

int main(){
    BinaryTree tree;

    //pre ABD***C**
    //in **D*B**CA
    Status createStatus = createBinaryTree(tree);
    printf("createStatus %s\n", createStatus == TRUE ? "TRUE": "FALSE");

    printf("\n\nPreOrderTraverse\n");
    PreOrderTraverse(tree);

    printf("\n\nInOrderTraverse\n");
    InOrderTraverse(tree);

    // printf("\n\nExchangeSubTree\n");
    // exchangeSubTree(tree);
    // PreOrderTraverse(tree);

    // printf("\n\nCopyBinaryTree\n");
    // BinaryTree newTree;
    // copyBinaryTree(tree, newTree);
    // PreOrderTraverse(newTree);

    return 0;
}