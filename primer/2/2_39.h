#include "mai.h"

using namespace std;

/* struct Foo{ */

/* } */

struct Sales_data{
    string bookNo;
    unsigned units_sold;
    double revenue;
};

int testSum(Sales_data data1,Sales_data data2){
    double price;
    cin >> data1.bookNo >> data1.units_sold >> price; 
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price; 
    data2.revenue = data2.units_sold * price;
    
    if(data1.bookNo == data2.bookNo){
        unsigned total_sold = data1.units_sold + data2.units_sold;
        double total_revenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << total_sold << " " << total_revenue << " ";
        if(total_sold != 0){
            std::cout << total_revenue/total_sold << endl;
        }
        else{
            cout << "(no sales)" << endl;
            return 0;
        }
    }
    else{
        cout << "data must refer to the same ISBN" << endl;
            return -1;
    }
    return 0 ;
}
