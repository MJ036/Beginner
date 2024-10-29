#include <stdio.h>

int main()
{
    int c;
    while((c = getchar()) != EOF){
        putchar(c);
    }
    printf("EOF的值为：%d\n",c);
    return 0;
}

