#include "mai.h"

#define OUT 0
#define IN 1

int main(int argc,char* argv[])
{
    // ./wc file
    ARGS_CHECK(argc,2);

    FILE* fp = fopen(argv[1],"rb");
    ERROR_CHECK(fp,NULL,"fopen");

    int c,nl,nw,nc,state;
    state = OUT;
    nl = nw = nc = 0;

    while((c = fgetc(fp)) != EOF){
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

    fclose(fp);



    return 0;
}

