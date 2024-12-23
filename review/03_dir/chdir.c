#include "mai.h"


int main(int argc, char* argv[])
{
    //./chdir dir
    ARGS_CHECK(argc,2);

    char buf[256];
    getcwd(buf,SIZE(buf));
    puts(buf);

    int ret = chdir(argv[1]);
    ERROR_CHECK(ret,-1,"chdir");

    getcwd(buf,SIZE(buf));
    puts(buf);


    


    return 0;
}

