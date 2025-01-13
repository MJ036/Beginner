#include "func.h"

int main(int argc, char* argv[])
{
    ARGS_CHECK(argc,2);
    struct hostent* pHost = gethostbyname(argv[1]);
    printf("hname = %s\n",pHost->h_name);
    for(int i = 0;pHost->h_aliases[i] != NULL; ++i){
        printf("alignas = %s\n",pHost->h_aliases[i]);
    }
    printf("addrtype = %d\n",pHost->h_addrtype);
    printf("addrlength = %d\n",pHost->h_length);
    char buf[128] = {0};
    for(int i = 0;pHost->h_addr_list[i] != NULL; ++i){
        memset(buf,0,sizeof(buf));
        inet_ntop(pHost->h_addrtype,pHost->h_addr_list[i],buf,sizeof(buf));
        printf("addr = %s\n",buf);
    }

    return 0;
}

