#include <iostream>
#include <string>
using namespace std;
void test0(){
    string a = "hello";
    a.append(" world").append("end!");
    cout << a << endl;
}
int main()
{
    test0();   
    return 0;
}

