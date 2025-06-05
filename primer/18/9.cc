#include "mai.h"
#include <exception>
#include <stdexcept>
#include "../shared/Sales_data.h"

using namespace std;

int main(){
    Sales_data book1("001",2,10);
    Sales_data book2("002",3,30);
    Sales_data book3("001",2,30);
    try{
        book1 += book2;
        //book1 += book3;
       cout << book1 << endl;;
    }catch(runtime_error&){
        cout << "This has an error\n";
    }


}
