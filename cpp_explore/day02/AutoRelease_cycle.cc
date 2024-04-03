#include <iostream>

using namespace std;

class Singleton{
    Singleton(int x, int y)
        :_ix(x)
         ,_iy(y)
    {
        cout << "Singleton(int, int)" << endl;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

    Singleton(const Singleton & rhs) = delete;
    Singleton &operator=(const Singleton& rhs) = delete;
public:
    static Singleton * getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Singleton(1,2);
        }
        return _pInstance;
    }

    void init(int x, int y){
        _ix = x;
        _iy = y;
    }
    
    void print()
    {
        cout << "(" << this->_ix
            <<"," << this->_iy
            << ")" << endl;
    }

    friend class AutoRelease;

private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
};

class AutoRelease{
public:
    AutoRelease(Singleton * p)
        :_p(p)
    {
        cout << "AutoRelease(Singleton*)" << endl;
    }

    ~AutoRelease(){
        cout << "~AutoRelease()" << endl;
        if(_p){
            delete _p;
            _p = nullptr;
        }
    }

private:
    Singleton *_p;
};

Singleton *Singleton::_pInstance = nullptr;

void test0(){
    AutoRelease ar(Singleton::getInstance());

    Singleton::getInstance()->init(100,200);
    Singleton::getInstance()->print();
}

int main()
{
    test0();
    return 0;
}

