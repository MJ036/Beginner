#include "mai.h"
#include <exception>
using namespace std;

class exceptionType{};

int main(){
    //(a)
    exceptionType* p;
    throw p;

    //(b) 随便throw

    //(c)
    typedef int EXCPTYPE;
    int a;
    throw(a);
}


