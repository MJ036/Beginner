//C Linux 阶段使用
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>  //获取文件信息

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <syslog.h>
#include <signal.h>
#include <sys/time.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <sys/sendfile.h>
#include <shadow.h>
#include <crypt.h>
#include <mysql/mysql.h>
#include <openssl/evp.h>

#define ARGS_CHECK(argc,num) {if((argc) != num) {fprintf(stderr,"argc error!\n");exit(-1);}}
#define ERROR_CHECK(ret,num,msg) {if(ret == num) {perror(msg);exit(-1);}}
#define THREAD_ERROR_CHECK(ret,msg) {if(ret != 0) {fprintf(stderr,"%s:%s\n",msg,strerror(ret));exi

#define SIZE(a) (sizeof(a)/sizeof(a[0]))
//C++阶段使用


#include <memory>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>

#include <mutex>


#include <hiredis/hiredis.h>
