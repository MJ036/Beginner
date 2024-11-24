#include <stdio.h>

void test1()
{
    int c;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            printf("\\t");
        }
        else if(c == '\b'){
            printf("\\b");
        }
        else if(c == '\\'){
            printf("\\\\");
        }
        else{
            putchar(c);
        }
    }
}

int main()
{
    test1();
    return 0;
}

