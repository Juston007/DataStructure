#include "stdio.h"
#include "stdlib.h"
#include "LinearList_Sequence.h"

/*=====================================宏定义=====================================*/
#define Status      int
#define TRUE        1
#define FALSE       0

#define KeyElementType      int     //关键字类型
#define ValueElementType    char    //值类型

#define MAX_LIST_SIZE       100
#define P                   97
/*=====================================宏定义=====================================*/


/*=====================================结构体=====================================*/

/**
 * 哈希表中存储的元素
*/
typedef struct ElementStruct{
    KeyElementType      key;        //关键字
    ValueElementType    *value;     //值
} *Element;

/**
 * 哈希表
*/
typedef struct HashTableStruct{
    Element         *elements;      //元素
    unsigned int    size;           //元素个数
    unsigned int    p;              //模除值
    unsigned int    tableLength;    //表长
    unsigned int    collisions;     //冲突个数
} *HashTable;
/*=====================================结构体=====================================*/


/*=====================================函数声明=====================================*/
unsigned int hashGenerateAddress(HashTable hashTable, KeyElementType key);
unsigned int hash(HashTable hashTable, KeyElementType key);
unsigned int conflictResolution(HashTable hashTable,KeyElementType key, unsigned int hashAddress);
unsigned int linearProbing(HashTable hashTable, KeyElementType key, unsigned int hashAddress);
Status initHashTable(HashTable &hashTable);
int size(HashTable hashTable);
Status get(HashTable hashTable, KeyElementType key, Element &returnElement);
Status contains(HashTable hashTable, KeyElementType key);
Status isEmpty(HashTable hashTable);
Status put(HashTable hashTable, KeyElementType key, ValueElementType value);
Status remove(HashTable hashTable, KeyElementType key);
/*=====================================函数声明=====================================*/


/*=====================================函数定义=====================================*/

/**
 * 功能：根据哈希函数生成地址
 * 参数：hashTable 哈希表；key 关键字；
 * 返回值：地址；准确的说这里是指的在数组中的偏移量
*/
unsigned int hashGenerateAddress(HashTable hashTable, KeyElementType key){
    //首先根据哈希函数生成一个地址
    unsigned int offset = hash(hashTable, key);
    //然后调用解决冲突的函数 返回可用的地址
    offset = conflictResolution(hashTable, key, offset);
    return offset;
}


/**
 * 功能：哈希函数
 * 参数：key 关键字；
 * 返回值：地址；准确的说这里是偏移量
*/
unsigned int hash(HashTable hashTable, KeyElementType key){
    //一般情况下，选p为小于表长的最大质数，或不包含小于20的质因数的合数
    return key % hashTable->p;
}

/**
 * 功能：解决冲突
 * 参数：hashTable 哈希表；key 关键字
 * 返回值：地址；准确的说这里是偏移量
*/
unsigned int conflictResolution(HashTable hashTable,KeyElementType key, unsigned int hashAddress){
    return linearProbing(hashTable, key, hashAddress);
}

/**
 * 功能：线性探测
 * 参数：hashTable 哈希表；key 关键字
 * 返回值：查找空位置或者关键字相等的位置，如果都找不到则返回OVERFLOW
*/
unsigned int linearProbing(HashTable hashTable, KeyElementType key, unsigned int hashAddress){

    printf("\ngenerate address %5d\n", hashAddress);

    int d, offset;
    //这里d从0开始，是因为要把刚生成的地址也判断以下是否可用
    for(d = 0;d < hashTable->tableLength;d++){
        //Hi = (H(key) + di) % m
        //i = 1,2,...,k - 1,k   (k <= m - 1) m：表长
        offset = (hashAddress + d) % (hashTable->tableLength);

        //线性探测过程重，如果找到了关键字相同的元素，说明元素已经存在
        //到最后都没有找到相同关键字，但是探测到了空闲的位置，说明元素不存在，此位置可用
        //到最后也没有找到空闲的位置，返回-1

        printf("probing (hash[%d] + d[%d]) %% m[%d] = %d ", hashAddress, d, hashTable->tableLength, offset);
        
        //找到了一个空闲的位置，那么将此地址返回
        if(hashTable->elements[offset] == NULL){
            printf(" is %s null\n", hashTable->elements[offset] == NULL ? "not" : "");
            return offset;
        }

        //找到了一个与指定关键字相同的元素，那么将此地址返回
        if(hashTable->elements[offset]->key == key){
            printf("key is %s equal\n", hashTable->elements[offset]->key == key ? "":"not");
            return offset;
        }

        printf("\n");
    }

    //如果一直找不到，那么返回OVERFLOW
    return OVERFLOW;
}

/**
 * 功能：初始化哈希表
 * 参数：hashTable 哈希表；
 * 返回值：初始化成功返回TRUE，否则返回FALSE
*/
Status initHashTable(HashTable &hashTable){

    //申请一个新HashTable变量的空间并赋值
    hashTable = (HashTable)malloc(sizeof(HashTableStruct));

    if(hashTable == NULL){
        exit(0);
    }

    //初始化各个字段
    hashTable->size = 0;                        //元素数量
    hashTable->collisions = 0;                  //冲突数量
    hashTable->tableLength = MAX_LIST_SIZE;     //表长

    //一般情况下，选p为小于表长的最大质数，或不包含小于20的质因数的合数
    //TODO 这里写死了 等会再改
    hashTable->p = 97;

    //用一个数组来存储元素
    hashTable->elements = (Element *)malloc(MAX_LIST_SIZE * sizeof(Element));

    //分配内存失败
    if(hashTable->elements == NULL){
        exit(0);
    }

    //每个元素初始状态为NULL
    for(int i = 0;i < hashTable->tableLength;i++){
        hashTable->elements[i] = NULL;
    }

    return TRUE;
}

/**
 * 功能：获取哈希表所存储的元素数量
 * 参数：hashTable 哈希表；
 * 返回值：哈希表指针不为空返回元素数量，否则返回-1
*/
int size(HashTable hashTable){
    return hashTable != NULL ? hashTable->size : -1;
}

/**
 * 功能：在哈希表中查找具有指定关键字的元素
 * 参数：hashTable 哈希表；key 指定关键字；returnElemnt 通过此参数返回元素；
 * 返回值：查找成功返回TRUE，并通过参数[returnElemnt]返回指定元素的指针，否则返回FALSE
*/
Status get(HashTable hashTable, KeyElementType key, Element &returnElement){
    //哈希表为空，返回ERROR
    if(hashTable == NULL){
        return ERROR;
    }

    if(hashTable->size == 0){
        returnElement = NULL;
        return FALSE;
    }

    //获取到可用的地址
    unsigned int offset = hashGenerateAddress(hashTable, key);

    //offset为-1说明没有空闲的空间了
    if(offset == OVERFLOW){
        return OVERFLOW;
    }

    //通过参数返回具有指定关键字元素的指针
    returnElement = hashTable->elements[offset];

    //如果函数生成的地址中有元素存在，说明具有指定关键字的元素存在
    return returnElement != NULL;
}

/**
 * 功能：在哈希表中查找是否存在指定关键字的元素
 * 参数：hashTable 哈希表；key 指定关键字；
 * 返回值：元素存在返回TRUE，否则返回FALSE
*/
Status contains(HashTable hashTable, KeyElementType key){
    Element element;
    return get(hashTable, key, element) == TRUE;
}

/**
 * 功能：该哈希表是否为空表
 * 参数：hashTable 哈希表；
 * 返回值：该哈希表为空表返回TRUE，否则返回FALSE
*/
Status isEmpty(HashTable hashTable){
    if(hashTable == NULL){
        return ERROR;
    }else{
        return hashTable->size == 0;
    }
}

/**
 * 功能：向哈希表中添加一个元素
 * 参数：hashTable 哈希表；element 要插入的元素
 * 返回值：添加成功返回TRUE，否则返回FALSE
*/
Status put(HashTable hashTable, KeyElementType key, ValueElementType *value){
    //哈希表为空，返回ERROR
    if(hashTable == NULL){
        return ERROR;
    }

    //使用函数生成可用的地址
    unsigned int offset = hashGenerateAddress(hashTable, key);

    //offset为OVERFLOW说明没有空闲的空间了
    if(offset == OVERFLOW){
        return OVERFLOW;
    }

    //指定位置上没有元素，说明不存在相同关键字的元素
    if(hashTable->elements[offset] == NULL){
        //生成一个新的元素并赋值
        Element element = (Element)malloc(sizeof(ElementStruct));
        element->key = key;
        element->value = value;

        //在哈希表中添加元素；
        hashTable->elements[offset] = element;
        //元素数量加一
        hashTable->size++;

        return TRUE;
    }else{
        return FALSE;
    }
}

/**
 * 功能：在哈希表移除具有指定关键字的元素
 * 参数：hashTable 哈希表；key 指定关键字
 * 返回值：移除成功返回TRUE，否则返回FALSE
*/
Status remove(HashTable hashTable, KeyElementType key){
    if(hashTable == NULL){
        return ERROR;
    }

    if(hashTable->size == 0){
        return FALSE;
    }

    //使用函数生成可用的地址
    unsigned int offset = hashGenerateAddress(hashTable, key);

    //offset为OVERFLOW说明没有空闲的空间了
    if(offset == OVERFLOW){
        return OVERFLOW;
    }

    //如果指定地址上没有元素说明不存在具有指定关键字的元素
    if(hashTable->elements[offset] == NULL){
        return FALSE;
    }else{
        //否则就将其释放掉
        free(hashTable->elements[offset]);
        //并将其从哈希表中删除
        hashTable->elements[offset] = NULL;
        //元素数量减一
        hashTable->size--;
        return TRUE;
    }
}
/*=====================================函数定义=====================================*/