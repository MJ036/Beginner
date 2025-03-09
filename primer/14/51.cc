#include "mai.h"
using namespace std;
struct LongDouble {
	LongDouble(double = 0.0);
	operator double();
	operator float();
};
    void calc(int){ cout << "int "<< endl; }
    void calc(LongDouble){ cout << "longdouble" << endl; }
int main()
{
    double dval;
    calc(dval);  //哪个calc？

    return 0;
}

