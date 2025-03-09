#include "mai.h"
#include "02_sub.h"
using namespace std;

template <class T>
T add(T t1, T t2){
    return t1 + t2;
}


void test1(){
    int i1 = 1, i2 = 2;
    cout << sub(i1,i2) << endl;
}

template <class T,int kBase>
T multiply(T x, T y){
return x * y * kBase;
}

void test2(){
    int i1 = 3,i2 = 4;
    cout << multiply<int,10>(i1,i2) << endl;
}

//递归的出口
void print(){
cout << endl;
}
void print(int x){
cout << x << endl;
}
//重新定义一个可变参数模板，至少得有一个参数
template <class T,class ...Args>
void print(T x, Args ...args)
{
    cout << x << " ";
    print(args...);
}

void test3(){
    print(1,"hello",3.6,true,100,2);
}

template <class ...Args>//Args 模板参数包
void display(Args ...args)//args 函数参数包
{
    //输出模板参数包中类型参数个数
    cout << "sizeof...(Args) = " << sizeof...(Args) << endl;
    //输出函数参数包中参数的个数
    cout << "sizeof...(args) = " << sizeof...(args) << endl;
}

void test0(){
    display();
    display(1,"hello",3.3,true);
}

int main()
{
    test0();
    return 0;
}

