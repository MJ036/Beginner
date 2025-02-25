#include "mai.h"
using namespace std;

class A{
public:
    int operator()(bool a, int b ,int c){
        return a ? b : c;
    }

};
int main()
{
    A my_class;
    cout << my_class(1,10,100) << endl;
    cout << my_class(0,10,100) << endl;

    return 0;
}

