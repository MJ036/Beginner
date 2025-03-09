#include<SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
using namespace std;
int main(){
    //建立和rabbitmq的连接
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
    //创建一个消息
    AmqpClient::BasicMessage::ptr_t message = AmqpClient::BasicMessage::Create("hello world!");
    //发送消息
    channel->BasicPublish("test2_exchange","file",message);
    cout << "message is sent" << endl;

}
