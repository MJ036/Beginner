#include "func.h"

void error(int status, int errnum, const char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errnum));
    exit(status);
}
int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,1);
        // 执行一些代码
    // ...

    // 获取core文件，请在这里填写你的代码：
    switch (fork()) {
    case -1:
        error(1, errno, "fork");
    case 0:
        // child
        abort();
    default:
        // parent
        break;
    }

    // 执行后续逻辑
    // ...

    return 0;
}

