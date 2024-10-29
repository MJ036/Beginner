#include <stdio.h>

int main()
{
    //C语言中没有\c的转移字符，所以无法通过编译，编译器报错
    printf("Hello,world\n\c");
    return 0;
}

