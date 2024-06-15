#include <iostream>
#include <string>

using namespace std;

void func(){
    cout << " func" << endl;
}

void test(){
    int a = 100;

    []()->void{
        cout << "hello" << endl;
    }();

    [a]()mutable->void{
        ++a;
        cout << "a = " << a << endl;
        cout << "hello" << endl;
    }();
    
    [&a]()->void{
        ++a;
        cout << "a = " << a << endl;
        cout << "hello" << endl;
    }();

    cout << " ---- a = " << a << endl;
}


void test2(){
    [](const string &name){
        cout << "test2" << endl;
        cout << "name = " << name << endl;
    }("wangdao");

    cout << endl << endl;
    auto f = [](const string &name){
        cout << "test2" << endl;
        cout << "name = " << name << endl;
    };
    f("test");

    cout << endl << endl;

    typedef void(*pFunc)(const string &);
    /* using pFunc = void (const string &); */
    pFunc pf = [](const string &name){
        cout << "test2" << endl;
        cout << "name = " << name << endl;
    };
    pf("wuhan wangdao");
}

int main()
{
    test2();
    return 0;
}

