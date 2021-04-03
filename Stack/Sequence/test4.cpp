#include <stdio.h>
#include <string.h>

int main(){
    //s 特定的数字集合 buf 缓冲区
	char s[20],buf[99];

    //计数变量 以及用于存储竖式中的各个变量
	int count = 0, a, b, x, y, z;

    //输入特定的数字集合
	scanf("%s",s);

	for(a = 100;a <= 999; a++){//三位数     //a表示三位数，b表示两位数 
	    for(b = 10;b <= 99; b++){//二位数
            
            //逗号表达式 自左向右计算表达式 最后一个表达式是整个表达式的值
            //三位数与二位数的个位部分相乘 三位数与二位数的十位部分相乘 然后乘积相加
	 	    x = a * ( b % 10), y = a * ( b / 10 ), z = a * b;

            //把这些数存到buf数组中
            //发送格式化输出到 str 所指向的字符串
	 	    sprintf(buf,"%d%d%d%d%d", a, b, x, y, z); 
            
            //每次循环变量ok都会重新定义 但这并不妨碍程序的正常运行
            //ok被置为0（只有在不符合题意时会这样）后 本次循环的后面的if直接被跳过了 直接进入下次循环
	 	    int ok = 1;
	 	    for(int i = 0;i < strlen(buf);i++){ 
                //将表达式中出现的值与特定的数字集合相比较 如果不存在那么ok = 0
                //strchr 在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置
	 		    if(strchr(s,buf[i]) == NULL)  //竖式中出现了不在特殊的数字集合中的数字 那么ok置为0
	 		        ok = 0;
		    }

            //如果ok为1 那么计数变量加一并且打印竖式    否则什么都不做
	 	    if(ok){
	 	        count++;
	 	        printf("<%d>\n",count);
	            printf("%5d\nX%4d\n-----\n%5d\n%5d\n-----\n%5d\n",a,b,x,y,z); 
	        }

        }
    }

    //打印解的个数
	printf("The number of solutions = %d",count);
	return 0;
}