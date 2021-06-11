#include "stdio.h"
#include "HashTable.h"

void printfAllElement(HashTable hashTable){
    printf("\n============================================\n");
    for(int i = 0;i < hashTable->tableLength;i++){
        Element element = hashTable->elements[i];
        if(element != NULL){
            printf("at index[%d]    key %10d     value   %s\n", i, element->key, element->value);
        }
    }
    printf("============================================\n\n");
}

int main(){
    HashTable hashTable;

    Status initStatus = initHashTable(hashTable);
    printf("init hash table %d\n", initStatus);

    int tableSize = size(hashTable);
    printf("tableSize %d\n", tableSize);

    Status emptyRes = isEmpty(hashTable);
    printf("isEmpty %d\n\n", emptyRes);



    /*=====================================插入元素=====================================*/
    int putKey = 2;
    char *putValue = "what";
    Status putRes = put(hashTable, putKey, putValue);
    printf("put element res %d       key [%d] value [%s]\n",putRes, putKey, putValue);
    printfAllElement(hashTable);

    putKey = 3;
    char *putValue2 = "is";
    putRes = put(hashTable, putKey, putValue2);
    printf("put element res %d       key [%d] value [%s]\n",putRes, putKey, putValue2);
    printfAllElement(hashTable);

    putKey = 99;
    char *putValue3 = "your";
    putRes = put(hashTable, putKey, putValue3);
    printf("put element res %d       key [%d] value [%s]\n",putRes, putKey, putValue3);
    printfAllElement(hashTable);

    putKey = 100;
    char *putValue4 = "name";
    putRes = put(hashTable, putKey, putValue4);
    printf("put element res %d       key [%d] value [%s]\n",putRes, putKey, putValue4);
    printfAllElement(hashTable);

    putKey = 100;
    char *putValue5 = "?";
    putRes = put(hashTable, putKey, putValue5);
    printf("put element res %d       key [%d] value [%s]\n",putRes, putKey, putValue5);
    printfAllElement(hashTable);

    int containKey = 99;
    Status containRes = contains(hashTable, containKey);
    printf("contains element res %d       key[%d]\n", containRes, containKey);

    /*=====================================删除元素=====================================*/
    int removeKey = 99;
    Status removeRes = remove(hashTable, removeKey);
    printf("remove element res %d       key[%d]\n", removeRes, removeKey);
    printfAllElement(hashTable);

    /*=====================================获取元素=====================================*/
    int getKey = 99;
    Element getElement;
    Status getRes = get(hashTable, getKey, getElement);
    printf("\nget element res %d       key [%d] value [%s]\n", getRes, getKey, getRes ? getElement->value : "null");
    

    /*=====================================元素数量=====================================*/
    tableSize = size(hashTable);
    printf("tableSize %d\n", tableSize);

    return 0;
}