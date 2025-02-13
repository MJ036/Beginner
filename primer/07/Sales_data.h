#include "mai.h"
#include <sys/mman.h>
using namespace std;

//7_12
struct Sales_data;
istream& read(istream& is, Sales_data& rhs);

struct Sales_data{
public:
    Sales_data(string s, unsigned cnt, double price):BookNo(s),units_sold(cnt),revenue(price){
        cout << "Sales_data(string s, unsigned cnt, double price) " << endl;
    }
//7_11
    Sales_data():Sales_data("",0,0){
        cout << "Sales_data()" << endl;
    }
//7_14
    Sales_data(const string& s):Sales_data(s,0,0){
        cout << " Sales_data(const string& s)" << endl;
    }
//7_12
    Sales_data(istream& is):Sales_data(){
        cout << "Sales_data(istream& is)" << endl;
        read(is,*this);
    }


    Sales_data& combine(const Sales_data &rhs);
    string isbn()const;

private:
    string BookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    inline double avg_price()const;

friend istream& read(istream& is, Sales_data& rhs);
friend ostream& print(ostream& os, Sales_data rhs);
friend ostream &operator<<(ostream &os,const Sales_data &item);
friend istream &operator<<(istream &is,Sales_data &item);
};
ostream &operator<<(ostream &os,const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
istream &operator<<(istream &is,Sales_data &item){
    double price;
    is >> item.BookNo >> item.units_sold >> price;
    if(is){
        item.revenue = item.units_sold * price;
    }else{
        item = Sales_data();
    }
    return is;

}

//10_12
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() < rhs.isbn();
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
string Sales_data::isbn()const{
    return BookNo;
}
double Sales_data::avg_price()const{
    if(units_sold){
        return revenue/units_sold;
    }else{
        return 0;
    }
}

//test_7
Sales_data add(const Sales_data& lhs, const Sales_data& rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
//read : BookNo, units_sold,  price
istream& read(istream& is, Sales_data& rhs){
    double price = 0;
    is >> rhs.BookNo >> rhs.units_sold >> price;
    rhs.revenue = price * rhs.units_sold;
    return is;
}
ostream& print(ostream& os, Sales_data rhs){
    os << rhs.isbn() << " " << rhs.units_sold << " " 
        << rhs.revenue << " " << rhs.avg_price();
    return os;
}
