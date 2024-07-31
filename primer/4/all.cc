#include "mai.h"

using namespace std;

void test_36(){
    int i = 25;
    double d = 4.5;
    i *= static_cast<int>(d);
    cout << i << endl;
    return ;
}

void test_37(){
    int i;
    double d;
    const string *ps;
    char *pc;
    void *pv;
    pv = static_cast<void*>(const_cast<string *>(ps));
    i = static_cast<int>(*pc);
    pv = static_cast<void*>(&d);
    pc = static_cast<char*>(pv);
}

int main()
{
    test_36();
    return 0;
}

