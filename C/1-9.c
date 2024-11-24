#include <stdio.h>

void test1()
{
    int c;
    int ns = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            ++ns;
        }
        else{
            ns = 0;
        }

        if(ns > 1){
            ;
        }
        else{
            putchar(c);
        }
    }
}

void test2(){
    int c;
    int ns;
    ns = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            ns++;
        }
        else{
            ns = 0;
        }
        if(ns > 1){
            ;
        }
        else{
            putchar(c);
        }
    }
}

int main()
{
    test2();
    return 0;
}

