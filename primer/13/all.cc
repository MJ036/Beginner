#include "mai.h"
using namespace std;

struct X{
    X(){cout << "X()" << endl;}
    X(const X&){cout << "X(const X&)"<< endl;}
    ~X(){cout << "~X()" << endl;}
    X& operator=(const X& x){cout << "X& operator=(const X&)" << endl;return *this;}
};

void f(const X&rx, X x){
    vector<X> vec;
    vec.reserve(2);
    //push时调用拷贝构造函数
    vec.push_back(rx);
    vec.push_back(x);
}


int main()
{
    //调用默认构造函数
    X *px= new X();
    //传入参数时，第二个参数，调用拷贝构造函数
    f(*px,*px);
    delete px;

    return 0;
}


