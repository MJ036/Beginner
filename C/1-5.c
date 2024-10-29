#include <stdio.h>

int main()
{
    float fahrenheit,celsius;
    int lower,upper,step;
    
    //温度表的下限、上限、步长
    lower = 0;
    upper = 300;
    step = 20;

    printf("摄氏度\t华氏度\n");
    for(celsius = upper; celsius >= lower; celsius -= step){
        fahrenheit = 9.0/5.0 * celsius + 32;
        printf("%6.2f\t%7.2f\n",celsius,fahrenheit);
    }

    return 0;
}

