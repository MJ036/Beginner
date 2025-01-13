#include "mai.h"

using namespace std;

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
    inline double avg_price();

friend istream& read(istream& is, Sales_data& rhs);
friend ostream& print(ostream& os, Sales_data rhs);

};
Sales_data& Sales_data::combine(const Sales_data &rhs){
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
string Sales_data::isbn()const{
    return BookNo;
}
double Sales_data::avg_price(){
    if(units_sold){
        return revenue/units_sold;
    }else{
        return 0;
    }
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

int main(int argc, char* argv[])
{
    // ./a.out text1
    Sales_data total;

    ifstream ifs(argv[1]);
    ofstream ofs(argv[2],ofstream::app);

    if(read(ifs,total)){
        Sales_data trans;
        while(read(ifs,trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(ofs,total);
                ofs << endl;
                total = trans;
            }
        }
        print(ofs,total);
        ofs << endl;
    }else{
        cerr << "error data" << endl;
    }
    return 0;
}

