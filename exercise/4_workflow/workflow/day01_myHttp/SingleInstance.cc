#include "mai.h"

class SingleInstance{
public:
    static SingleInstance* GetInstance();
    static void deleteInstance();
    
    void Print();

private:
    SingleInstance();
    ~SingleInstance();

    SingleInstance(const SingleInstance & );
    const SingleInstance &operator=(const SingleInstance &);

private:
    static SingleInstance* _pInstance;
    static std::mutex _mutex;
};

SingleInstance* SingleInstance::_pInstance = nullptr;
std::mutex _mutex;

SingleInstance* SingleInstance::GetInstance(){
    if(_pInstance == nullptr){
        std::unique_lock<std::mutex> lock(_mutex);
        if(_pInstance == nullptr){
            auto temp = new SingleInstance();
            _pInstance = temp;
        }
    }
    return _pInstance;
}

void SingleInstance::deleteInstance(){
        std::unique_lock<std::mutex> lock(_mutex);
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
}

void SingleInstance::Print(){
    std::cout << "地址：" << this << std::endl;
}


