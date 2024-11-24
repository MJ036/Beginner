#include <stdio.h>

//是否在单词中扫描
#define OUT 0
#define IN 1

//版本一：
//问题：遇到连续的空白字符会打印出多余空行
void test1(){
    int c,state;
    state = OUT;
    while((c = getchar()) != EOF){
        if(c == '\t' || c == '\n' || c == ' '){
            putchar('\n');
        }else{
            putchar(c);
        }
    }
}


void test2(){
    int c,state;
    state = OUT;
    while((c = getchar()) != EOF){
        if(c == '\t' || c == '\n' || c == ' '){
            if(state == IN){
                putchar('\n');
                state = OUT;
            }
        }else{
            putchar(c);
            state = IN;
        }
    }
    if(state == IN){
        putchar('\n');
    }

}

int main()
{
    test1();
    return 0;
}

