#include <iostream>

using namespace std;

class Singleton
{
friend class AutoRelease;
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

    static Singleton *_p;
};

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

Singleton * Singleton::_p = nullptr;

int main()
{
    AutoRelease ar;
    Singleton *p = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    cout << (p == p2) << endl;

    return 0;
}

