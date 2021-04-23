#include "stdio.h"
#include "stdlib.h"

#define ElementType		int
#define MAXSIZE			10000

#define Status			int
#define TRUE			1
#define FALSE			1

//三元组结构体
typedef struct TripleStruct {
	int i, j;
	ElementType value;
} Triple;

//矩阵结构体
typedef struct MatrixStruct {
	Triple *data;
	int row, column, notZeroNumber;
} Matrix;


//初始化矩阵
void initMatrix(Matrix &matrix) {
	matrix.row = 3;
	matrix.column = 5;
	matrix.notZeroNumber = 5;
	matrix.data = (Triple *)malloc(sizeof(Matrix) * matrix.notZeroNumber);
}

//添加元素到矩阵
void addElementToMatrix(Matrix &matrix) {
	int k = 0;

	Triple triple = {0, 0, 1};
	matrix.data[k++] = triple;

	triple = {0, 4, 7};
	matrix.data[k++] = triple;

	triple = {1, 0, 2};
	matrix.data[k++] = triple;

	triple = {1, 1, 4};
	matrix.data[k++] = triple;

	triple = {2, 2, 1};
	matrix.data[k++] = triple;
}


//打印三元组数组的所有元素
void printAllTriplesElement(Triple *triples, int elementNumber) {
	for(int i = 0; i < elementNumber; i++) {
		printf("i[%d] j[%d] = value[%d]\n",triples[i].i, triples[i].j, triples[i].value);
	}
}

//压缩稀疏矩阵 
//已弃用
Triple *compressSparseMatrix(Matrix matrix) {
	int k = 0;
	//如果是在函数内部定义的结构体数组，是没有办法正常返回的
	//因为c语言不能返回一个数组，只能返回一个指针，而函数内部定义的数组在函数结束后其生命就结束了
	//会被回收 但是将要返回的数据定义为全局变量或者动态分配就可以避免此情况
	Triple *triples = (Triple *)malloc(sizeof(Triple) * matrix.notZeroNumber);

	for(int i = 0; i < matrix.row; i++) {
		for(int j = 0; j < matrix.column; j++) {
			int index = i * matrix.column + j;
			if(matrix.data[index].value != 0) {
				printf("i[%d] j[%d] = value[%d]\n",i,j,matrix.data[index].value);
				triples[k++] = matrix.data[index];
			}
		}
	}

	//printAllTriplesElement(triples,matrix.notZeroNumber);

	printf("\n\n");

	//matrix.data = triples;

	return triples;
}

//矩阵转置
Triple *transposeMatrix(Matrix &matrix){

	Triple *triples = (Triple *)malloc(sizeof(Triple) * matrix.notZeroNumber);

	//该变量用来记录新三元组数组的下标
	int index = 0;
	//columnCursor列游标
	for(int columnCursor = 0;columnCursor < matrix.column;columnCursor++){
		//序号游标 游标 可以移动的序号
		for(int indexCursor = 0;indexCursor < matrix.notZeroNumber;indexCursor++){
			//如果序号游标位置的三元组的列号与列游标相同 
			//行列互换后 将其存入新的三元组数组
			//原本的三元组行号就是递增的 互换后成为列号还是递增的 所以不用对列再排序
			if(matrix.data[indexCursor].j == columnCursor){
				//行列互换
				Triple triple;
				triple.i = matrix.data[indexCursor].j;
				triple.j = matrix.data[indexCursor].i;
				triple.value = matrix.data[indexCursor].value;

				//存入新的三元组数组 index标志着它再新数组中的位置
				triples[index++] = triple;
			}
		}
	}

	return triples;
}

int main() {
	Matrix matrix;

	//初始化
	initMatrix(matrix);
	//添加测试元素到矩阵
	addElementToMatrix(matrix);
	//打印所有元素
	printAllTriplesElement(matrix.data, matrix.notZeroNumber);

	printf("\n\n");

	//压缩稀疏矩阵
	//Triple *triples = compressSparseMatrix(matrix);
	//printAllTriplesElement(matrix.data, matrix.notZeroNumber);

	//矩阵转置
	printf("\ntranspose Matrix\n");
	Triple *triples2 = transposeMatrix(matrix);
	printAllTriplesElement(triples2, matrix.notZeroNumber);

	return 1;
}
