#include <iostream>

using namespace std;

void test1()
{
    int a = 10;
    int &ref = a;
    int &ref1 = 10;
    const int &ref2 = 10;

    int &&rref = 10;
    int &&rref1 = a;
    
    String s1 = String("world");
    
    String(String &rhs);
    String(String &&rhs);
    
    

}





















int main()
{

    return 0;
}

