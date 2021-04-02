#include "stdio.h"
#include "Stack_Sequence.h"

Status isNumber(char inputChar);
Status isOperator(char inputChar);

int main(){

    //            操作符栈        操作数栈
    SequenceStack operatorStack, operandStack;
    initStack(operatorStack);
    initStack(operandStack);

    char inputChar = getchar();

    while(inputChar != '\n'){
        if(isNumber(inputChar)){
            push(operandStack,inputChar - '0');
        }
        else if(isOperator(inputChar)){

            if(inputChar == '(' || inputChar == ')'){

            }
        } 
        else{
            printf("输入错误了吧？老哥\n");
            return;
        }
    }

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

char precede(char operator1,char operator2){
    if(operator1 == operator2)
        return '>';

    if(operator1 == '(')
        return '<';
    
    if(operator2 == ')'){
        return operator1 == '(' ? '=' : '>' ;
    }

    if(operator1 == '#'){
        return operator2 == '#' ? '=' : '>';
    }

    if(operator1 == '+' || operator1 == '-'){
        return operator2 == '*' || operator2 == '\\';
    }
    else{
        return '>';
    }
}