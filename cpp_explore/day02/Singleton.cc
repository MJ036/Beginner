#include <iostream>

using namespace std;

class Singleton
{
public:
    static Singleton * getInstance(){
        if(_p == nullptr){
            _p = new Singleton();
        }
        return _p;
    }
private:
    Singleton(){}

    static Singleton *_p;
};

Singleton * Singleton::_p = nullptr;

int main()
{
    Singleton *p = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    cout << (p == p2) << endl;

    return 0;
}

