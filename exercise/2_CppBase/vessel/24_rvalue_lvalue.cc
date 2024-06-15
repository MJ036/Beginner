#include <iostream>
using std::cout;
using std::endl;

void test(){
    int a = 10;
    int &ref1 = a;
    int &ref2 = 10;

    const int &ref3 = a;
    const int &ref10 = 10;

    int && ref3 = a;
    int &&ref4 = 10;
    auto p = &ref4;
    
}

int &&func(){
    return 10;
}



void test2()
{
    int a = 10;

    int &ref1 = a;
    int &ref2 = 10;
    const int &ref3 = a;
    const int &ref10 = 10;

    int &&ref3 =  a;//error
    int &&ref4 =  10; //ok
    &ref4;//右值引用ref在此处是左值，但是可以绑定到右值

}


int main(int argc, char *argv[])
{
    test();
    &func(); //右值引用在此处是右值，所以引用不了。 综上右值引用既可以是左值又可以是右值
    return 0;
}
