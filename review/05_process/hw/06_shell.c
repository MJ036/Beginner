#include "func.h"
#define MAX_ARGS 64

void parse_command(char* cmd,char** args){
    int i = 0;
    args[i] = strtok(cmd," \t\n");
    while(args[i] != NULL){
        i++;
        args[i] = strtok(NULL," \t\n");
    }
}

int main(int argc,char* argv[])
{
    char cmd[MAXSIZE]; //存储用户输入的命令
    char* args[MAX_ARGS]; // 存储解析后的命令参数

    for(;;){
        //输出提示符
        printf("myshell > ");
        fflush(stdout);

        //读取输入
        if(fgets(cmd,MAXSIZE,stdin) == NULL){
            break;
        }

        //移除输入末尾的换行符
        if(cmd[strlen(cmd) - 1] == '\n'){
            cmd[strlen(cmd) - 1] = '\0';
        }

        //检查指令是否是exit
        if(strcmp(cmd,"exit") == 0){
            printf("Exiting shell ...\n");
            break;
        }

        //解析命令
        parse_command(cmd,args);

        pid_t pid = fork();

        if(pid == 0){
            //会在环境变量PATH中的目录，寻找名为args[0]的可执行文件
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
                exit(1);  // 如果命令失败，退出子进程
            }
        }else if(pid > 0){
            int status; 
            waitpid(pid,&status,0);
            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child terminated by signal %d\n", WTERMSIG(status));
            }
        }else{
            perror("fork");
        }
    }
    return 0;
}

