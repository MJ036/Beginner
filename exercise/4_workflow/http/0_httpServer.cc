#include "mai.h"
#include <54func.h>

using namespace std;

class HttpServer {
public:
    HttpServer(const string &ip, unsigned short port)
    :_ip(ip),_port(port),_sockfd(-1)
    {}

    ~HttpServer(){
        if(_sockfd > 0){
            close(_sockfd);
        }
    }

    void start(); // socket->bind->listen
    void recvAndShow(); //accept --> recv --> cerr
    string response(); //回复一个响应
private:
    string _ip;
    unsigned short _port;
    int _sockfd;
};
void HttpServer::start(){
    _sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(_sockfd < 0){
        perror("socket");
        exit(1);
    }
    int reuse = 1;
    int ret = setsockopt(_sockfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse));
    if(ret < 0){
        perror("setsockopt");
        exit(1);
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr,0,sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(_ip.c_str());
    serverAddr.sin_port = htons(_port);
    
    ret = ::bind(_sockfd,(struct sockaddr *)&serverAddr,sizeof(serverAddr));
    if(ret < 0){
        perror("bind");
        exit(1);
    }
    listen(_sockfd,10);
}
void HttpServer::recvAndShow(){
    while(true){
        // NULL ((void *)0)
        int netfd = accept(_sockfd,nullptr,nullptr);
        char buf[4096] = {0};
        ssize_t sret = recv(netfd,buf,sizeof(buf),0);
        printf("sret = %ld, buf = %s\n", sret, buf);

        //添加响应功能
        string resp = response();
        send(netfd,resp.c_str(),resp.size(),0);
        close(netfd);
    }
}

string HttpServer::response(){
    string startLine = "HTTP/1.1 200 OK\r\n";
    string headers = "Server:MyHttpServer\r\n";
    string body = "<html>Hello world</html>";
    headers += "Content-Type: text/html\r\n";
    //headers += "Content-Type: text/plain\r\n";
    //headers += "Content-Type: application/octet-stream\r\n";
    headers +="Content-Length:" + std::to_string(body.size())+"\r\n";
    string emptyLine = "\r\n";
    return startLine + headers + emptyLine +body;
}

//发送一个html文件
//string HttpServer::response(){
//    string startLine = "HTTP/1.1 200 OK\r\n";
//    string headers = "Server:MyHttpServer\r\n";
//
//    int fd = open("test.html",O_RDWR);
//    char buf[4096] = {0};
//    read(fd,buf,sizeof(buf));
//    string body = buf;
//    headers += "Content-Type: text/html\r\n";
//    headers +="Content-Length:" + std::to_string(body.size())+"\r\n";
//    string emptyLine = "\r\n";
//    return startLine + headers + emptyLine +body;
//}
//重定向
//string HttpServer::response(){
//    string startLine = "HTTP/1.1 302 Found\r\n";
//    string headers = "Server:MyHttpServer\r\n";
//    headers += "Content-Type: text/html\r\n";
//    headers += "Location: http://www.baidu.con\r\n";
//    string emptyLine = "\r\n";
//    return startLine + headers + emptyLine;
//}


int main(){
    HttpServer server("172.19.79.160",1234);
    server.start();
    server.recvAndShow();
    return 0;
}

