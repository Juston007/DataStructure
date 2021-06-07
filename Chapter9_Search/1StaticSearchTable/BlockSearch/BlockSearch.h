#include "stdio.h"
#include "stdlib.h"

/*=====================================宏定义=====================================*/
#define Status          int
#define TRUE            1
#define FALSE           0

#define KeyElementType     int
/*=====================================宏定义=====================================*/


/*=====================================结构体=====================================*/
/**
 * 索引
*/
typedef struct Index{
    int start;                  //起始索引
    KeyElementType maxKey;      //最大关键字
} Index;

typedef char*   SearchTable;    //查找表
typedef Index*  IndexTable;     //索引表
/*=====================================结构体=====================================*/


/*=====================================函数定义=====================================*/
/**
 * TODO:这里还没有搞明白怎么查找的
 * 功能：从索引表中折半查找指定索引
 * 参数：table 索引表，length 索引表长度；key 要查找的关键字
 * 返回值：查找成功返回索引，否则返回-1
*/
int binarySearch(IndexTable table, int length, KeyElementType key){
    int low, height, middle;

    low = 0;
    height = length - 1;

    while(low <= height){
        //计算区间中间的索引
        middle = (low + height) / 2;

        //调整区间
        if(key <= table[middle].maxKey){
            height = middle - 1;
        }else{
            low = middle + 1;
        }
    }

    return height + 1;
}

/**
 * 
 * 功能：普通查找；从指定位置开始，在查找表中查找指定长度
 * 参数：table 查找表；start 开始下标；length 查找长度；key 要查找的关键字；
 * 返回值：查找成功返回下标，否则返回-1
*/
int search(SearchTable table, int start, int length, KeyElementType key){
    int endIndex = start + length - 1;
    printf("from %d to %d search %d\n", start, endIndex, key);
    for(int i = start;i <= endIndex;i++){
        if(table[i] == key){
            return i;
        }
    }
    return -1;
}

/**
 * 功能：分块查找；首先确定待查记录所在的块；然后在块中顺序查找
 * 参数：searchTable 查找表；searchlength 查找表长度；indexTable 索引表；indexLength 索引表长度；key 要查找的关键字
 * 返回值：查找成功返回下标，否则返回-1
*/
int BlockSearch(SearchTable searchTable, int searchlength, IndexTable indexTable, int indexLength, KeyElementType key){
    //首先确定要查找的块
    int blockIndex = binarySearch(indexTable, indexLength, key);
    printf("key[%d] at block %d     index start %d\n", key, blockIndex, indexTable[blockIndex].start);

    //查找失败
    if((blockIndex == -1) || (blockIndex > indexLength - 1)){
        //块不存在
        return -1;
    }

    //计算块的长度
    int currentBlockLength;
    if(blockIndex == indexLength - 1){
        //最后一个块，用查找表长度减去该块起始下标
        currentBlockLength = searchlength - indexTable[blockIndex].start;
    }else{
        //不是最后一个块，用后一个块的起始下标减去当前块的起始下标
        currentBlockLength = indexTable[blockIndex + 1].start - indexTable[blockIndex].start;
    }

    printf("current block length %d\n", currentBlockLength);
    return search(searchTable,  indexTable[blockIndex].start, currentBlockLength, key);
}
/*=====================================函数定义=====================================*/