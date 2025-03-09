#include <SimpleAmqpClient/Envelope.h>
#include<SimpleAmqpClient/SimpleAmqpClient.h>
#include <iostream>
using namespace std;
int main(){
    //建立和rabbitmq的连接
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create();
    //开启消费：创建事件，盯着队列
    channel->BasicConsume("test2_queue");
    //为信封申请内存
    AmqpClient::Envelope::ptr_t envelope; //先申请一个指针
    //将消息读取到信封中
    bool flag = channel->BasicConsumeMessage(envelope,3000);

    if(flag){
        cout << "Body = " << envelope->Message()->Body() << "\n";
    }else{
        cerr << "timerout\n";
    }

    return 0;
}
