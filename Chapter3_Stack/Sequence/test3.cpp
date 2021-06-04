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

    //如果输入的字符是#并且操作符栈顶也是#说明输入完毕了
    while(inputChar != '#' || topOperatorChar != '#'){

        printf("topOperatorChar [%c]    inputChar [%c]",topOperatorChar, inputChar);

        //如果输入的数字那么直接入栈
        if(isNumber(inputChar)){
            //这样可以支持n位的数
            int number = 0;
            while(isNumber(inputChar)){
                number *= 10;
                number += (inputChar - '0');
                inputChar = getchar();
            }
            push(operandStack,number);
            printf("    input Number[%d]  push operandStack\n",number);
        }
        //如果输入的是操作符
        else if(isOperator(inputChar)){
            
            //取操作符栈顶元素比较优先级
            getTop(operatorStack, returnValue);
            //操作符栈顶和输入的字符比较
            char priorityChar = precede(returnValue, inputChar);
            printf("    input Operator");

            /**
             * 先算优先级最高的
             * 
             * 操作符栈顶优先级大于输入的字符 说明从输入的字符到开始有优先级较高的符号那么要先计算 操作数出栈两个元素 操作符出栈一个元素 计算并入操作数栈     例：输入 +  栈顶*
             * 操作符栈顶优先级等于输入的字符 说明遇到了左右括号 直接出栈 例：输入)  栈顶 (
             * 操作符栈顶优先级小于输入的字符 说明后输入的运算符优先级较高 直接入栈 例：输入 * 栈顶 +
            */
                
            switch(priorityChar){
                case '<': //输入的字符大于操作符栈顶元素 直接入栈并再接收一个字符
                    printf("    push operatorStack\n");
                    push(operatorStack, inputChar);
                    inputChar = getchar();
                    break;
                case '=': //优先级相等 直接出栈
                    printf("    pop operatorStack\n");
                    pop(operatorStack, returnValue);
                    inputChar = getchar();
                    break;
                case '>': //输入的字符小于操作符栈顶元素   
                    printf("    calcul and push operandStack\n");
                    //操作数连出两个元素
                    int leftValue, rightValue;
                    pop(operandStack, rightValue);
                    pop(operandStack, leftValue);

                    //操作符出栈
                    int operatorChar;
                    pop(operatorStack, operatorChar);

                    //进行运算并将结果入操作数栈
                    int result = operate(leftValue, operatorChar, rightValue);
                    push(operandStack, result);    
                    break;
            }

        } 
        else{
            printf("输入错误了吧？老哥\n");
            break;
        }

        //获取最新的栈顶元素
        getTop(operatorStack, topOperatorChar);
    }

    //最后的运算结果在操作数栈底 需要最后出栈以获取
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
    (inputChar == '*') || (inputChar == '/') ||
    (inputChar == '#') || (inputChar == '(') ||
    (inputChar == ')');
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
        if(priorityTable[0][i] == operator1){
            break;
        }
    }

    //横坐标寻找
    for(j = 0;j < 8;j++){
        if(priorityTable[j][0] == operator2){
            break;
        }
    }

    return priorityTable[i][j];
}