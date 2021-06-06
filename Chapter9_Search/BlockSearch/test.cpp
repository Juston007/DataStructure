#include "stdio.h"
#include "BlockSearch.h"

void init(SearchTable &searchTable, int searchLength, IndexTable &indexTable, int indexLength){
    searchTable = (SearchTable)malloc(sizeof(KeyElementType));
    if(searchTable == NULL){
        exit(1);
    }

    indexTable = (IndexTable)malloc(sizeof(IndexTable));
    if(indexTable == NULL){
        exit(1);
    }
}

void initData(SearchTable &searchTable, IndexTable &indexTable){
    searchTable[0] = 22;
    searchTable[1] = 12;
    searchTable[2] = 13;
    searchTable[3] = 8;
    searchTable[4] = 9;
    searchTable[5] = 20;

    searchTable[6] = 33;
    searchTable[7] = 42;
    searchTable[8] = 44;
    searchTable[9] = 38;
    searchTable[10] = 24;
    searchTable[11] = 48;

    searchTable[12] = 60;
    searchTable[13] = 58;
    searchTable[14] = 74;
    searchTable[15] = 49;
    searchTable[16] = 86;
    searchTable[17] = 53;

    indexTable[0] = {0, 22};
    indexTable[1] = {6, 48};
    indexTable[2] = {12, 86};
}

int main(){
    SearchTable searchTable;
    IndexTable indexTable;

    int searchLength = 18, indexLength = 3;

    init(searchTable, searchLength, indexTable, indexLength);
    initData(searchTable, indexTable);

    int key;
    scanf("%d", &key);
    
    int index = BlockSearch(searchTable, searchLength, indexTable, indexLength, key);
    printf("key[%d] at index %d\n", key, index);

    // int key = 60;
    // int index = binarySearch(indexTable, indexLength, key);
    // printf("key[%d] at block index %d\n", key, index);

    // int currentBlockLength = indexTable[index + 1].start - indexTable[index].start;
    // printf("current block length %d\n", currentBlockLength);
    // int realIndex = search(searchTable, index, currentBlockLength, key);
    // printf("key[%d] at real index %d\n", key, realIndex);

    return -1;
}