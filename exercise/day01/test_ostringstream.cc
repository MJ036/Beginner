#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ostringstream oss;
    int num = 123,num2 = 567;
    oss << "num = " << num << " num2 = " << num2;
    string s = oss.str();
    cout << s <<endl ;
    return 0;
}

