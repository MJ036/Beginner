#include "mai.h"
#include <vector>
using namespace std;

struct X{
    X(){cout << "X()" << endl;}
    X(const X&){cout << "X(const X&)"<< endl;}
    ~X(){cout << "~X()" << endl;}
    X& operator=(const X& x){cout << "X& operator=(const X&)" << endl;return *this;}
};

void f(const X&rx, X x){
    vector<X> vec;
    cout << "2" << endl;
    vec.reserve(2);
    cout << "3" << endl;
    vec.push_back(rx);
    cout << "4" << endl;
    vec.push_back(x);
}

int main()
{
    X *px= new X();
    cout << "1" << endl;
    f(*px,*px);
    delete px;

    return 0;
}

