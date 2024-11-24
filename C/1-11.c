#include <stdio.h>
/*
 * 测试方法
 * 1. 单字符单词
 * 2. 一个多字符单词
 * 3. 两个多字符单词
 *  3.1 两个单词在同一行
 *  3.2 两个单词在不同行
 * 4. 边界条件：
 *  4.1 没有输入
 *  4.2 没有单词，只有符号
 *  ...
 * */

//是否在单词中扫描
#define OUT 0
#define IN 1

int main()
{
    //当前处理字符、总行数、总单词数、总字符数、当前处理字符的状态
    int c,nl,nw,nc,state;
    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF){
        ++nc;
        if(c == '\n'){
            nl++;
        }
        if(c == '\t' || c == '\n' || c == ' '){
            state = OUT;
        }else if(state == OUT){
            state = IN;
            ++nw;
        }
    }
    printf("\n");
    printf("总字符数 = %d\n总行数 = %d\n总单词数 = %d\n",nc,nl,nw);
    return 0;
}

