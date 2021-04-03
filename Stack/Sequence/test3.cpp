#include "stdio.h"
#include "Stack_Sequence.h"

Status isNumber(char inputChar);
Status isOperator(char inputChar);
char precede(char operator1,char operator2);
int operate(int leftValue, char operatorChar, int rightValue);

//优先级表格
char priorityTable[8][8] = {
    ' ','+','-','*','/','(',')','#',
    '+','>','>','<','<','<','>','>',
    '-','>','>','<','<','<','>','>',
    '*','>','>','>','>','<','>','>',
    '/','>','>','>','>','<','>','>',
    '(','<','<','<','<','<','=',' ',
    ')','>','>','>','>','>',' ','>',
    '#','<','<','<','<','<',' ','=',
};

int main(){

    //            操作符栈        操作数栈
    SequenceStack operatorStack, operandStack;
    int returnValue;

    //初始化操作数栈和操作符栈
    initStack(operatorStack);
    initStack(operandStack);

    //操作符入栈# 优先级最低的符号
    push(operatorStack,'#');

    char inputChar = getchar();
    int topOperatorChar = '#';

    while(inputChar != '#' || topOperatorChar != '#'){

        //如果输入的数字那么直接入栈
        if(isNumber(inputChar)){
            push(operandStack,inputChar - '0');
            inputChar = getchar();
        }
        //如果输入的是操作符
        else if(isOperator(inputChar)){
            
            //取操作符栈顶元素比较优先级
            getTop(operatorStack, returnValue);
            char priorityChar = precede(inputChar, returnValue);
                
            switch(priorityChar){
                case '>': //输入的字符大于操作符栈顶元素 直接入栈并再接收一个字符
                    push(operatorStack, inputChar);
                    inputChar = getchar();
                    break;
                case '=': //优先级相等 直接出栈
                    pop(operatorStack, returnValue);
                    inputChar = getchar();
                    break;
                case '<': //输入的字符小于操作符栈顶元素 操作数连出两个元素 操作符出栈 进行运算并将结果入操作数栈
                    int leftValue, rightValue;
                    pop(operandStack, rightValue);
                    pop(operandStack, leftValue);

                    int operatorChar;
                    pop(operatorStack, operatorChar);

                    int result = operate(leftValue, operatorChar, rightValue);
                    push(operandStack, result);    
                    break;
            }

        } 
        else{
            printf("输入错误了吧？老哥\n");
            break;
        }

        getTop(operatorStack, topOperatorChar);
    }

    pop(operandStack,returnValue);
    printf("res = %d",returnValue);

}



//是否为数字
Status isNumber(char inputChar){
    return (inputChar >= '0') && (inputChar <= '9');
}

//是否为运算符
Status isOperator(char inputChar){
    return (inputChar == '+') || (inputChar == '-') ||
     (inputChar == '*') || (inputChar == '/');
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

//获取优先级
char precede(char operator1,char operator2){

    int i, j;

    //纵坐标寻找
    for(i = 0;i < 8;i++){
        if(priorityTable[0][i] == operator2){
            break;
        }
    }

    //横坐标寻找
    for(j = 0;j < 8;j++){
        if(priorityTable[j][0] == operator1){
            break;
        }
    }

    return priorityTable[i][j];
}