#include <stdio.h>

int main()
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
    return 0;
}

