#include "mai.h"
using namespace std;

namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//位置1
//using Exercise::ivar;  //error_1
//using Exercise::dvar;
//using Exercise::limit;
//using namespace Exercise;

void mainip() {
	//位置2
    using Exercise::ivar;
    using Exercise::dvar;   //error_2
    using Exercise::limit;

    //using namespace Exercise;   //error_3 
	double dvar = 3.1416;   
	int iobj = limit + 1;
	++ivar;
	++::ivar;

}
