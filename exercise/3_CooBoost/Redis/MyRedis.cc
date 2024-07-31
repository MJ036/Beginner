#include "MyRedis.h"

MyRedis::MyRedis()
    :_pConnect(nullptr)
     ,_pReply(nullptr){
         cout << "MyRedis()" << endl;
     }

MyRedis::~MyRedis(){
    cout << "~MyRedis" << endl;

    if(_pConnect){
        redisFree(_pConnect);
        _pConnect = nullptr;
    }

    if(_pReply){
        freeReplyObject(_pReply);
        _pReply = nullptr;
    }
}

bool MyRedis::connect(const string &host, int port){
    _pConnect = redisConnect(host.c_str(),port);
    if(_pConnect == nullptr){
        return false;
    }

    if(_pConnect != nullptr && _pConnect->err){
        std::cerr << "connect error : " << _pConnect->errstr << endl;
        return false;
    }
    return true;
}

void MyRedis::set(string key,string value){
    _pReply = (redisReply *)redisCommand(_pConnect,"SET %s %s",key.c_str(),value.c_str());
    if(_pReply){
        freeReplyObject(_pReply);
        _pReply = nullptr;
    }
}


string MyRedis::get(string key){
    _pReply = (redisReply*)redisCommand(_pConnect,"GET %s",key.c_str());
    if(_pReply){
        if(_pReply->type == REDIS_REPLY_STRING){
            string str = _pReply->str;
            freeReplyObject(_pReply);
            _pReply = nullptr;
            return str;
        }
        else{
            return nullptr;
        }
    }else{
        return nullptr;
    }

}
