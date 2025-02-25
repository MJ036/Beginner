#include "mai.h"
#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <cstdio>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

class HttpServer{
public:
    HttpServer(const string& ip, unsigned short port)
        :_fd(-1)
         ,_ip(ip)
         ,_port(port)
    {}
    ~HttpServer(){
        if(_fd > 0){
            close(_fd);
        }
    }

    void start();
    void recvAndShow();
    void HandleRequest();
    string response();

private:
    int _fd;
    string _ip;
    unsigned short _port;
};

void HttpServer::start(){
    _fd = socket(AF_INET,SOCK_STREAM,0);
    if(_fd < 0){
        perror("socket");
        return;
    }
    int on = 1;
    int ret = setsockopt(_fd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
    if(ret < 0){
        perror("setsockopt");
        return;
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(_ip.c_str());
    serveraddr.sin_port = htons(_port);

    ret = bind(_fd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    if(ret < 0){
        perror("bind");
        return;
    }
    ret = listen(_fd,10);
    if(ret < 0){
        perror("listen");
        return;
    }
}
void HttpServer::HandleRequest(){
    int netfd = accept(_fd,nullptr,nullptr);
    char buf[4096];
    ssize_t sret = recv(netfd, buf, 4096, 0);
    buf[sret] =
        '\0';
    printf("Received HTTP request:\n%s\n"
           , buf);
    char head[] =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n";
    char response[8192] = {0};
    int fd = open("login.html"
                  ,O_RDONLY);
    bzero(buf,sizeof(buf));
    sret = read(fd,buf,sizeof(buf));
    sprintf(response,"%sContent-Length:%ld\r\n\r\n%s",head,sret, buf);
    send(netfd, response, strlen(response),0);
}

void HttpServer::recvAndShow(){
    while(true){
        int netfd = accept(_fd,nullptr,nullptr);
        char buff[1024] = {0};
        int ret = recv(netfd,buff,sizeof(buff),0);
        printf("ret: %d\n recv: %s\n", ret,buff);

        string msg = response();
        printf("\r\n%s\n", msg.c_str());
        ret = send(netfd,msg.c_str(),msg.size(),0);
        close(netfd);
    }
}

string HttpServer::response(){
    string startLine = "HTTP/1.1 200 OK\r\n";
    string headers = "Server: MyHttpServer\r\n";
    string body("<html><body>hello,client</body></html>");
        headers += "Content-Type: text/html\r\n";
        headers += "Content-Length: " + to_string(body.size()) + "\r\n";
        string emptyLine("\r\n");
        return startLine + headers + emptyLine + body;
}

void test(){
    HttpServer httpserver("0.0.0.0",1234);
    httpserver.start();
    httpserver.recvAndShow();
    //处理浏览器响应，并返回html文件
    //httpserver.HandleRequest();
}

int main()
{
    test();
    return 0;
}

