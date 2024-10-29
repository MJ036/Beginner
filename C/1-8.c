#include <stdio.h>

int main()
{
    int c;
    //记录空格、制表符、换行符的数量
    int ns,nt,nl;
    ns = nt = nl = 0;
    while((c = getchar()) != EOF){
        if(c == ' '){
            ns++;
        }
        if(c == '\t'){
            nt++;
        }
        if(c == '\n'){
            nl++;
        }
    }
    printf("\n");
    printf("空格 = %d\n制表符 = %d\n换行符 = %d\n",ns,nt,nl);
    return 0;
}

