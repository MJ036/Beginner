#include "mai.h"
#include <algorithm>
#include <openssl/bn.h>
using namespace std;

class Class{
public:
    Class(){cout << "Class()" << endl;}
};
class Base :public Class{
public:
    Base(){ cout << "Base()" << endl; }
    Base(const Base&){}
    Base(const int&){ cout << "Base(int)" << endl; }
};
class D1 : virtual public Base{
public:
    D1() = default;
    D1(const D1& d1){}
    D1(const int& i ):Base(i){cout << "D1(int)" << endl;}
};
class D2 : virtual public Base{
public:
    D2() = default;
    D2(const D2&):Base(){}
    D2(const int& i ):Base(i){cout << "D2(int)" << endl;}

};
class Mi : public D1,public D2{
public:
    Mi() = default;
    Mi(const Mi& mi){}
    Mi(const int& i):D1(i),D2(i){cout << "Mi(int)" << endl;}
};
class Final : public Mi, public Class{
public:
    Final() = default;
    Final(const Final& fi){}
    //这里Final类会控制虚基类Base的构造，如果不给Base传入参数，会调用Base的默认构造函数
    Final(const int& i):Mi(i),Base(i){cout << "Final(int)" << endl;}
};

int main(){
    Base *pb;
    Class *pc;
    Mi *pmi;
    D2 *pd2;

    int i = 2;
    Final f1(i);
    //pb = new Class;
    //pc = new Final;
    //pmi = pb;
    //pd2 = pmi;
}
