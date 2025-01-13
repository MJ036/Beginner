#include "func.h"

int main(int argc,char* argv[])
{
    int pipe_fd1[2],pipe_fd2[2];

    if(pipe(pipe_fd1) == -1 || pipe(pipe_fd2) == -1){
        perror("pipe");
    }

    char buf[MAXSIZE];
    pid_t pid = fork();
    ERROR_CHECK(pid,-1,"fork");

    if(pid == 0){
        //关闭管道1读端
        close(pipe_fd1[0]);
        //关闭管道2写端
        close(pipe_fd2[1]);

        const char* message = "I am baby";
        write(pipe_fd1[1],message,strlen(message) + 1);
        
        read(pipe_fd2[0],buf,sizeof(buf));
        printf("from parent: %s\n",buf);

        close(pipe_fd1[1]);
        close(pipe_fd2[0]);

    }else{
        //关闭管道1的写端
        close(pipe_fd1[1]);
        //关闭管道2的读端
        close(pipe_fd2[0]);

        read(pipe_fd1[0],buf,sizeof(buf));
        printf("from child: %s\n",buf);

        const char* message = "Who's your daddy?";
        write(pipe_fd2[1],message,strlen(message));

        //关闭管道1读端
        close(pipe_fd1[0]);
        //关闭管道2写端
        close(pipe_fd2[1]);
        wait(NULL);


    }

    return 0;
}

