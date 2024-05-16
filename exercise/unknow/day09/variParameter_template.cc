#include <iostream>

using namespace std;

template<typename ...T>
void print(T ...t)
{
    cout << "sizeof...(T) = " << sizeof...(T) << endl;
    cout << "sizeof...(t) = " << sizeof...(t) << endl;
}

void test()
{
    print();

    print(1,"hello");

    print(1,true,3.3,"helloworld");
}

void show()
{
    cout << endl;
}

template <typename T ,typename  ...Args>
void show(T t,Args ...args)
{
    cout << t << " ";
    show(args...);
}

void test2(){
    show();

    show(1,3.4);

    show(1,"hello",3.3);
}

int sum()
{
    return 0;
}

template <typename T,typename ...Args>
T sum(T t, Args ...args)
{
    return t + sum(args...);
}

void test3(){
    cout << "sum(1,2,3,4,5,6,7,8,9,10) = "
        << sum(1,2,3,4,5,6,7,8,9,10) << endl;
}


int main()
{
    test3();
    return 0;
}

