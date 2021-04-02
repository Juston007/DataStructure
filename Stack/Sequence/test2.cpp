#include "stdio.h"
#include "Stack_Sequence.h"

int operate(int leftValue, char operatorChar, int rightValue);
Status isNumber(char inputChar);
Status isOperator(char inputChar);

/**
 * 后缀表达式
 * (2)(9)(5)-(2)*+
 * 
 * 注意：下面注释已经弃用
 * 实际上栈中存储的并不是真实的值 而是ASCII码
 * 在运算过程中 中间结果可能会超过0~9的ASCII码
*/
int main(){
    SequenceStack stack;
    initStack(stack);

    char inputChar = getchar();
    while(inputChar != '\n'){

        // 如果是一个数字那么毫不犹疑的入栈
        if(isNumber(inputChar)){
            //这里我们要把输入的字符转换为数字再存储进去
            push(stack,inputChar - '0');
        }
        //如果是一个操作符那么进行一系列的操作
        else if(isOperator(inputChar)){
            //取出左右值
            int leftValue, rightValue;
            pop(stack,rightValue);  
            pop(stack,leftValue);   

            //将左右值和运算符做运算得到结果
            int returnValue = operate(leftValue,inputChar,rightValue);

            //将结果存到栈中
            push(stack, returnValue);
        }
        
        //接着接收下一个字符
        inputChar = getchar();
    }

    //正常情况栈只有一个元素 那就是最后的结果
    int returnValue;
    pop(stack,returnValue);
    printf("result = %d\n", returnValue);
    return 0;
}

//将左右值与操作符做运算
int operate(int leftValue, char operatorChar, int rightValue){
    switch(operatorChar){
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
    }
}

//是否为数字
Status isNumber(char inputChar){
    return (inputChar >= '0') && (inputChar <= '9');
}

//是否为运算符
Status isOperator(char inputChar){
    return (inputChar == '+') || (inputChar == '-') || (inputChar == '*') || (inputChar == '/');
}