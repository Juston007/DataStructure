#include "stdio.h"

int index(char *str1, char *str2, int position);

int main(){
    unsigned char data[] = {0xCA, 0x1F, 0xC2, 0XF4, 0XB2, 0x02, 0x3C, 0xE8, 0x37, 0x66};
    //字符数组的索引为0的位置存储的是该字符串的长度
    char str1[] = "1aaabbbccc";
    str1[0] = 9;

    char str2[] = "1abbbc";
    str2[0] = 5;

    printf("mainString:%s\n", str1);
    printf("subString:%s\n", str2);

    int position = index(str1, str2, 1);
    printf("subString match mainString at index %d\n", position);

    return 0;
}

/**
 * 功能：字符串模式匹配
 * 参数：str1 被匹配的字符串，str2模式串，position 从该位置之后的位置
 * 返回值：返回字串str2在主串中第position个字符之后的位置。若不存在，则返回0
*/
int index(char *str1, char *str2, int position){
    //从position位置开始寻找 游标j指向子串第一个字符 （索引为0的位置存储的是长度 所以不算）
    int i = position, j = 1;

    //获取字符串长度
    int str1Length = str1[0];
    int str2Length = str2[0];

    while((i <= str1Length) && (j <= str2Length)){
        printf("compare  [%d]%c == [%d]%c\n", i, str1[i], j, str2[j]);
        // 主串游标i和子串游标j位置的字符一致，游标+1
        if(str1[i] == str2[j]){
            i++;
            j++;
        }else{
            // 字符不相等 主串游标i退回上一步起始位置 +1的位置
            // 可以用另外的变量k来保存上一步起始位置
            // 也可以通过 游标i - 已经比较过的字符 + 1  子串已经比较过的字符个数子串游标j - 1
            // 也就是 i - (j - 1) + 1  简化为  i - j + 2
            i = i - j + 2;
            // 子串游标j退回到第一个字符
            j = 1;
        }
    }

    return j > str2Length ? i - str2Length : 0;
}