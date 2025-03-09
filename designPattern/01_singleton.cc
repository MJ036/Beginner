#include "mai.h"
using namespace std;

class Point{
private:
    Point(int x,int y)
    : _ix(x)
    ,_iy(y){}

public:
    static Point *getInstance(){
        if(_pInstance == nullptr){
            _pInstance = new Point(1,2);
        }
        return _pInstance;
    }
    void print() const{
        cout << "(" << this->_ix
            << "," << this->_iy
            << ")" << endl;
    }

private:
    int _ix;
    int _iy;
    static Point* _pInstance;
};
Point *Point::_pInstance = nullptr;

int main()
{
    Point::getInstance()->print();

    return 0;
}

