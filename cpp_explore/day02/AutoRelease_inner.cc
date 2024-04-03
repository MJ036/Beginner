#include <iostream>

using namespace std;

class Singleton{
    class AutoRelease{
    public:
        AutoRelease()
        {
            cout << "AutoRelease(Singleton*)" << endl;
        }

        ~AutoRelease(){
            cout << "~AutoRelease()" << endl;
            if(_pInstance){
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };

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

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
            _pInstance = nullptr;
        }
        cout << "delete heap" << endl;
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


private:
    int _ix;
    int _iy;
    static Singleton * _pInstance;
    static AutoRelease _ar;
};


Singleton *Singleton::_pInstance = nullptr;
Singleton::AutoRelease Singleton::_ar;

void test0(){

    Singleton::getInstance()->init(100,200);
    Singleton::getInstance()->print();
    Singleton::destroy();
}

int main()
{
    test0();
    Singleton::getInstance()->print();
    return 0;
}

