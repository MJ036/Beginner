#include <stdio.h>

int main()
{
    int fahrenheit,celsius;
    int lower,upper,step;
    
    //温度表的下限、上限、步长
    lower = 0;
    upper = 300;
    step = 20;

    printf("华氏度\t摄氏度\n");
    for(fahrenheit = lower; fahrenheit <= upper; fahrenheit += step){
        celsius = 5.0/9.0 * (fahrenheit - 32);
        printf("%d\t%d\n",fahrenheit,celsius);
    }

    return 0;
}

