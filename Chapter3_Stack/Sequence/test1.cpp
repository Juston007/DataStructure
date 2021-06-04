#include "stdio.h"
#include "Stack_Sequence.h"

//函数声明 如果是定义的话必须在其调用者前面就定义 或者像是我这样声明一下
void fromDecimalToOther(int value, int R);
Status bracketMatching();
void lineEdit();

int main(){

    //进制转换
    //fromDecimalToOther(123,2);

    //括号检验
    /*Status code = bracketMatching();
    printf("code = %d  aaa\n", code);*/

    //行编辑
    lineEdit();

    return 0;
}


/**
 * 数制转换
 * 十进制数N和其他d进制数进制数的转换
 * 
 * N = (N div d) * d + N mod d
 * 其中div为整除运算 mod为求余运算
*/

/**
 * 作用：从十进制转换为R进制
 * 参数：value 要转换的十进制数 R R进制
 * 返回值：无
*/
void fromDecimalToOther(int value, int R){
    //初始化栈
    SequenceStack stack;
    initStack(stack);

    //R进制 R为一个占位符 可以替换为我们常见的10（10进制） 2（2进制） 16（16进制）

    //辗转相除法
    while(value != 0){
        push(stack,value % R);
        value /= R;
    }

    //将所有元素出栈
    //按照FILO原则 最先入栈的元素最后出栈
    //所以其值是倒着（从下往上）的余数
    int returnValue;
    while(!isEmpty(stack)){
        pop(stack,returnValue);
        printf("%d",returnValue);
    }

    destoryStack(stack);
}

/**
 * 括号匹配
 * 括号必须两两相对  结束符 #
 * 正确格式 [()()[()()()]]#
 * 错误格式 [()(()]#
*/
Status bracketMatching(){
    //printf("code = %d\n", 1);

    //初始化顺序栈
    SequenceStack stack;
    initStack(stack);

    //接收一个字符
    char inputChar;

    inputChar = getchar();
    //scanf("%c",&inputChar);

    //如果字符是#那么说明输入结束直接退出
    while(inputChar != '#'){

        //如果输入的是左括号那么毫不犹疑的入栈
        if((inputChar == '(') || (inputChar == '[')){
            push(stack,inputChar);
        }
        //如果输入的是右括号那么需要做出一些判断
        else if((inputChar == ')') || (inputChar == ']')){

            //如果栈不为空那么与栈顶元素比较 否则直接将元素入栈
            if(!isEmpty(stack)){
                int returnValue;
                getTop(stack,returnValue);

                //如果栈顶是左括号（区分大小） 输入的是相对应的右括号那么出栈
                //因为太长了所以分成两个if写
                if((returnValue == '(') && (inputChar == ')')){
                    pop(stack,returnValue);
                }
                else if((returnValue == '[') && (inputChar == ']')){
                    pop(stack,returnValue);
                }
                else{
                    push(stack,inputChar);
                }
            }
            else{
                push(stack,inputChar);
            }

        }
        //输入了一些其他的字符 直接退出
        else{
            printf("输入错误！");
            break;
        }

        //接收一个字符
        inputChar = getchar();
        //scanf("%c",&inputChar);

    }

    //如果栈为空 那么说明匹配没有问题
    return isEmpty(stack);
}

/**
 * 行编辑程序
 * #退格
 * @退行
*/
void lineEdit(){

    //初始化栈
    SequenceStack stack;
    initStack(stack);

    //接收一个字符
    char inputChar = getchar();
    ElementType returnValue;

    //EOF 全文结束符
    //当遇到EOF时说明输入结束 结束循环
    while(inputChar != EOF){

        //里面再嵌套一个循环是专门为了接收一行数据
        //当换行时清空缓冲区
        while(inputChar != '\n'){

            switch(inputChar){
            case '#':
                pop(stack,returnValue);
                break;
            case '@':
                clearStack(stack);
                break;
            default:
                push(stack,inputChar);
                break;
            }

            inputChar = getchar();
        }

        //换行了 将缓冲区数据送出并清空
        clearStack(stack);
        //push(stack,'\n');
        //printf("\nclear cache\n");
        
        inputChar = getchar();
    }


    /*================================输出内容================================*/
    int length = getLength(stack);
    char *str = (char *)malloc(length * sizeof(ElementType));

    for(int i = 0;!isEmpty(stack);i++){
        ElementType returnValue;
        pop(stack,returnValue);
        *(str + i) = returnValue;
    }

    for(int i = length - 1;i >= 0;i--){
        printf("%c",*(str + i));
    }

}