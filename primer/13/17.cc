#include "mai.h"
using namespace std;

class numbered{
public:
    numbered(){
        mysn = unique++;
    }
    numbered(numbered& n){
        mysn = unique++;
    }
    int mysn;
    static int unique;
};
int numbered::unique = 1;

void f1(const numbered& s){
    cout << s.mysn << endl;
}
int main()
{
    numbered a, b = a, c = b;
    f1(a);f1(b);f1(c);

    return 0;
}

