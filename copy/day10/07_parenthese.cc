#include <iostream>

using namespace std;

class FunctionObject
{
public:
    FunctionObject()
        :_count(0)
    {

    }
    
    int operator()(int x, int y)
    {
        cout << "int operator()(int,int)" << endl;
        ++_count;
        return x + y;
    }       

    int operator()(int x, int y, int z)
    {
        cout << "int operator()(int, int, int)" << endl;
        ++_count;
        return x * y * z;
    }
private:
    int _count;
};

int add(int x,int y)
{
    cout << "int add(int, int)" << endl;
    static int cnt = 0;
    ++cnt;
    return x + y;
}

int main()
{
    int a = 3,b = 4, c = 5;

    FunctionObject fo;
    cout << "fo(a,b) = " << fo(a,b) << endl;
    cout << "fo(a,b,c) = " << fo(a,b,c) << endl;
    cout << "add(a,b) = " << add(a,b) << endl;
    int *pInt;
    pInt = &a;

    typedef int (*pFunc)(int,int);
    pFunc pf = &add;
    cout << "pf(a,b) =" << pf(a,b) << endl;

    return 0;
}

