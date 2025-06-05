#include "mai.h"
using namespace std;

template<typename T, typename ... Args>
void foo(const T &, const Args& ... rest){
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

int main(){
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";

    foo(i,s,43,d);
    foo(i,s,d);
    foo(i,s);
    foo(i);

}
