#include "mai.h"
#include <cerrno>
#include <istream>
#include <ostream>
#include <sstream>
#include <sys/mman.h>
using namespace std;


//18_9
class isbn_mismatch
:public logic_error{
public:
    explicit isbn_mismatch(const string& s):logic_error(s){}

    isbn_mismatch(const string& s, const string& lhs, const string& rhs):logic_error(s),left(lhs),right(rhs){
    }

    const string left,right;

};

//7_12
struct Sales_data;
istream& read(istream& is, Sales_data& rhs);

struct Sales_data{
        friend class std::hash<Sales_data>;

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
Sales_data& operator+=(const Sales_data &rhs);

    


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
friend istream &operator>>(istream &is,Sales_data &item);
friend  Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
friend bool operator==(const Sales_data &lhs,const Sales_data &rhs);
};
