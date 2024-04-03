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
    Singleton(){
        cout << "Singleton" << endl;
    }

class AutoRelease
{
public:
    AutoRelease(){
        cout << "AutoRelease" << endl;
    }   

    ~AutoRelease(){
        cout << "~AutoRelease" << endl;
        if(Singleton::getInstance()){
            delete Singleton::getInstance();
            Singleton::_p= nullptr;
        }
    }
};

    static Singleton *_p;
    static AutoRelease _ar;
};


Singleton * Singleton::_p = nullptr;
Singleton::AutoRelease Singleton::_ar;

int main()
{
    Singleton *p = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    cout << (p == p2) << endl;

    return 0;
}

