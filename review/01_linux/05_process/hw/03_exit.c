#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//参数status，是由exit()传递给on_exit的，通常是程序退出时的状态值
void onExitFunc1(int status, void* arg) {
    printf("onExitFunction call: stat-%d, arg=%ld\n", status, (long)arg);
}

void function1(void) { 
    printf("但是咸粽子才是最强的\n");
}

void function2(void) { 
    printf("豆腐脑配什么都好吃,\n");
}

int main() {
    on_exit(onExitFunc1, (void*)10); // 使用 on_exit 注册退出时调用的函数，并传递额外参数 10
    atexit(function1); // 使用 atexit 注册退出时调用的函数
    atexit(function2); // 使用 atexit 注册退出时调用的函数
    on_exit(onExitFunc1, (void*)20); // 再次使用 on_exit 注册退出时调用的函数，并传递额外参数 20

    printf("纷争开始了\n");
    sleep(3); // 暂停 3 秒，模拟程序运行
    return 0;
}

