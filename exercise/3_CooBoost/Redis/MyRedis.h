#ifndef __MAI_H__
#include "mai.h"

using std::cout;
using std::endl;

using  std::string;

class MyRedis
{
public:
    MyRedis();
    ~MyRedis();
    bool connect(const string &host, int port);
    void set(string key,string value);
    string get(string key);

private:
    redisContext *_pConnect;
    redisReply *_pReply;

};

#endif
