#include <iostream>

using namespace std;

class Singelton
{
    Singelton(int x,int y)
    :_x(x)
     ,_y(y)
    {}

    
    
public:
    static Singelton * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singelton(1,2);
        }
        return _pInstance;
    }

    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
    
    void print()
    {
        cout << "(" << this->_x
            << "," << this->_y
            << ")" << endl;
    }

    void init(int x,int y){
        _x = x;
        _y = y;
    }

private:
    int _x;
    int _y;

    static Singelton * _pInstance;
};

Singelton * Singelton::_pInstance = nullptr;


int main()
{
 //   Singelton *pt = Singelton::getInstance();
 //   Singelton *pt2 = Singelton::getInstance();

 //   cout << pt << endl;
 //   cout << pt2 << endl;

 //   pt2->print();
 //   
 //   return 0;
    Singelton::getInstance()->print();
    Singelton::getInstance()->init(30,20);
    Singelton::getInstance()->print();
    Singelton::destroy();
    return 0;
}

