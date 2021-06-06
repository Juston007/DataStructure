#include "stdio.h"

/**
 * 功能：针对有序数组的折半查找
 * 参数：array 数组；length 数组长度；key 要查找的元素
 * 返回值：查找成功返回下标，否则返回-1
*/
int binarySearch(int *array, int length, int key){
    int low, height, middle, count;

    //初始化
    low = 0;
    count = 0;
    height = length - 1;

    //当low大于height时，说明全部查找完了都没有查找到，循环结束
    while(height >= low){
        count++;

        printf("from index[%d](%d) to index[%d](%d)\n", low, array[low] , height, array[height]);

        //计算中间的下标
        middle = (low + height) / 2;

        //判断当前选中的元素是否为要查找的元素
        int value = array[middle];
        if(value == key){
            printf("search count = %d\n", count);
            return middle;
        }

        //要查找的值小于当前值，在前半区间继续查找
        if(key < value){
            height = middle - 1;
        }
        //要查找的值大于当前值，在后半区间继续查找
        else{
            low = middle + 1;
        }
    }

    printf("search count = %d\n", count);

    return -1;
}

int main(){
    int array[100];
    int length = sizeof(array) / sizeof(int);

    //初始化
    for(int i = 0;i < length;i++){
        array[i] = i;
    }

    //折半查找
    int element = 51;
    int index = binarySearch(array, length, element);
    printf("element %d index at %d", element, index);

    return 0;
}