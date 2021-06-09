#include "stdio.h"
#include "BinarySort.h"

int main(){
    BinarySortTree bst;
    initTree(bst);


    int data[] = {6, 3, 7, 2, 4, 8, 11, 1, 5, 9, 10};
    int length = 11, input;
    //scanf("%d", &length);
    for(int i = 0;i < length;i++){
        //scanf("%d", &input);
        Status res = insertBST(bst, data[i]);
        printf("\ninsert value %3d   result %s", data[i], res ? "success" : "failure");
    }


    //查找某个结点
    int searchKey = 4;
    BinarySortTree searchRes = searchBST(bst, searchKey);
    printf("\n\nsearchRes is %s null   value %4d\n\n", searchRes == NULL ? "" : "not", searchRes != NULL ? searchRes->data : 0);
    inOrderTraverse(bst);

    //删除某个结点
    int deleteKey = 6;
    Status deleteRes = deleteBST(bst, deleteKey);
    printf("\ndelete key %3d delete %s\n", deleteKey, deleteKey ? "success" : "failure");
    inOrderTraverse(bst);

    return 0;
}