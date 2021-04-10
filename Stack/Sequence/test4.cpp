#include "stdio.h"
#include "time.h"

/**
 * 将number从source移动到destination
*/
void move(int number, char source, char destination){
    printf("move [%d]  %c ==> %c\n",number ,source, destination);
}

/**
 * 将number  ~ 1的盘子从source经among移动到destination
*/
void hannuo(int number, char source, char among, char destination){
    if(number == 1){
        move(1, source, destination);
    }
    else{
        //将编号[number - 1] ~ [1]的圆盘移动到among上，以destination为辅助
        hannuo(number - 1, source, destination, among);
        //将编号为[number]的圆盘移动到destination上
        move(number, source, destination);
        //将编号[number - 1] ~ [1]的圆盘移动到destination上，以source为辅助
        hannuo(number - 1, among, source, destination);
    }
}

int main(){
    int layer = 10;

    scanf("%d",&layer);

    clock_t startTime,endTime;
    startTime = clock();

    hannuo(layer, 'a', 'b', 'c');

    endTime = clock();
    printf("executing the %d layer Hanno tower cost %d ms\n", layer, endTime - startTime);
}