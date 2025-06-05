#include "mai.h"
#include <ostream>
#include "print.h"
using namespace std;



int main(){
    int i = 1;
    float f = 2.0;
    double d = 3.00;
    char c = 'c';
    
    print(cout,i);
    
    cout << "---" << endl;
    print(cout,i,f,d);
    cout << "---" << endl;
    print(cout,i,f,d,"mai",c);
    cout << "---" << endl;


}
