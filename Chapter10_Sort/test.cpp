#include "stdio.h"


#define ElementType     int

#define Status          int
#define TRUE            1
#define FALSE           0

/**
 * 直接插入排序
 * 升序
*/
void StraightInsertionSort(ElementType *array, int length){

    //分为已排序的部分和未排序的部分
    //已排序；未排序

    //step1.先把未排序的第一个元素保存

    //step2.用未排序的第一个元素和已排序的最后一个元素比较
    //如果未排序的元素比较大，那么已排序元素后移一位
    //一直重复此过程，直到未排序的第一个元素在已排序部分中找到了一个合适的位置
    //此时合适位置后面的元素也已经都后移一位，合适位置空出

    //step3.将之前保存的未排序的第一个元素放到排序的合适位置step

    //step4.标识已排序和未排序的字段后移一位

    //step5.一直重复此过程，直到未排序部分没有任何元素

    //i：用来区分已排序和未排序部分
    //已排序[0,i-1] 未排序[i,end]
    for(int i = 1;i < length;i++){
        //用未排序部分的第一个元素和已排序的最后一个元素比较，判断是否需要后移以让出合适位置
        if(array[i] < array[i - 1]){
            //需要后移让出合适位置；因为可能会被覆盖，所以将未排序部分的第一个元素保存
            int j;
            int temp = array[i];

            //边判断边后移；这个代码没有哨兵，所以要记得做边界检查
            for(j = i - 1;(j >= 0) && (temp < array[j]);j--){
                array[j + 1] = array[j];
            }
            //到循环结束时，j+1便是可以插入未排序部分第一个元素的合适位置
            array[j + 1] = temp;
        }
    }
}

/**
 * 折半查找
 * 
 * 在数组中，key排序的合适位置
 * array[i] <= key <= array[j]   (0 <= i,j <= length - 1)
*/
int BinarySearch(ElementType *array, int length, int key){
    int low, height, middle;

    low = 0;
    height = length - 1;

    while(low <= height){
        middle = (low + height) / 2;

        if(array[middle] < key){
            low = middle + 1;
        }else{
            height = middle - 1;
        }
    }

    return height + 1;
}

/**
 * 折半插入排序
 * 
 * 基于直接插入排序，只是减少了比较次数，实际上时间复杂度还是O(n^2)
*/
void BinaryInsertionSort(ElementType *array, int length){
    //i：用来区分已排序和未排序部分
    //已排序[0,i-1] 未排序[i,end]
    for(int i = 1;i < length;i++){
        //折半查找找出合适位置
        int k, temp = array[i];
        int index = BinarySearch(array, i + 1, temp);

        //在已排序部分加未排序部分的第一个元素，合适位置之后的元素后移一位
        for(k = i - 1;k >= index;k--){
            array[k + 1] = array[k];
        }
        //合适位置放置未排序部分的第一个元素
        array[k + 1] = temp;
    }
}

/**
 * 带有步长的直接插入排序
*/
void StraightInsertionSortWithStepSize(ElementType *array, int length, int stepSize){
    for(int i = stepSize + 1;i < length;i++){
        //printf("prior %d[%d] , next %d[%d]\n", i - stepSize, array[i - stepSize] , i, array[i]);

        if(array[i] < array[i - stepSize]){
            int j = i - stepSize;
            int temp = array[i];

            for(;(j >= 0) && (temp < array[j]);j -= stepSize){
                array[j + stepSize] = array[j];
            }

            array[j + stepSize] = temp;
        }
    }
}

/**
 * 希尔排序
 * Shell's Sort
*/
void SheelSort(ElementType *array, int length){

    //希尔排序是基于直接插入排序的，是直接插入排序的改进版

    //直接插入排序在面对小量或基本有序的顺序表时表现良好
    //希尔排序就是抓住了这两点
    //1.小量 希尔排序通过将直接插入排序分成了一个一个小序列的方式来减少数量  不过不是分段，而是通过步长的方式 而且步长逐渐缩小
    //2.基本有序 通过前面的小序列缩小增量的方式使得顺序表基本有序
    //最后步长必定是1，也就是到最后再整体直接插入排序一遍  这个时候基本有序，所以直接插入排序效率较高

    for(int i = length / 2;i > 0;i /= 2){
        //printf("i %d\n", i);
        StraightInsertionSortWithStepSize(array, length, i);
    }
}


/**
 * 起泡（冒泡）排序
 * bubble sort
*/
void BubbleSort(ElementType *array, int length){
    for(int i = 0;i < length - 1;i++){
        int isSwap = FALSE;

        //[length-i,length-1]   已排序区间
        //[0,length-i-1]        未排序区间
        for(int j = 0;j < length - i - 1;j++){
            if(array[j + 1] < array[j]){
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;

                isSwap = TRUE;
            }
        }

        //如果前面都没有交换，那么说明前面是有序的，那么剩下的不需要再比较了
        if(!isSwap){
            break;
        }
    }
}

/**
 * 交换顺序表中子表left至right的记录，使得枢轴记录到位
*/
int partition(ElementType *array, int left, int right){
    //用子表的第一个记录作为枢轴
    int temp;
    int pivotKey = array[left];

    //从表的两端交替的向中间扫描
    while(left < right){
        
        //从右边扫描得到第一个比枢轴小的记录的下标
        while((left < right) && (array[right] >= pivotKey)){
            right--;
        }
        //将比枢轴记录小的记录交换到低端
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        
        
        //从左边扫描得到第一个比枢轴大的记录的下标
        while((left < right) && (array[left] <= pivotKey)){
            left++;
        }
        //将比枢轴记录大的记录交换到高端
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }

    //返回枢轴所在位置
    return left;
}

void QuickSort(ElementType *array, int left, int right){
    if(left < right){
        //交换顺序表中子表left至right的记录，使得枢轴记录到位
        //枢轴左边的数均小于枢轴
        //枢轴右边的数均大于枢轴
        int pivotLocation = partition(array, left, right);

        //对低子表进行递归排序
        QuickSort(array, left, pivotLocation - 1);
        //对高子表进行递归排序
        QuickSort(array, pivotLocation + 1, right);
    }
}

/**
 * 打印所有元素
*/
void printAllElement(ElementType *array, int length, const char *str){
    printf("%s", str);
    printf("\n===============================\n");
    for(int i = 0;i < length;i++){
        printf("%3d", array[i]);
    }
    printf("\n===============================\n\n");
}

void initArray(ElementType *array, int length){
    array[0] = 35;
    array[1] = 22;
    array[2] = 63;
    array[3] = 83;
    array[4] = 13;
    array[5] = 84;
    array[6] = 92;
    array[7] = 69;
    array[8] = 33;
    array[9] = 53;
}

int main(){
    ElementType array[10];

    initArray(array, 10);
    printAllElement(array, 10, "init array");

    BinaryInsertionSort(array, 10);
    printAllElement(array, 10, "binary insertion sort");

    initArray(array, 10);
    printAllElement(array, 10, "init array");

    StraightInsertionSort(array, 10);
    printAllElement(array, 10, "straight insertion sort");

    initArray(array, 10);
    printAllElement(array, 10, "init array");

    SheelSort(array, 10);
    printAllElement(array, 10, "sheel sort");

    initArray(array, 10);
    printAllElement(array, 10, "init array");

    BubbleSort(array, 10);
    printAllElement(array, 10, "bubble sort");

    QuickSort(array, 0, 9);
    printAllElement(array, 10, "quickq sort");

    return 0;
}