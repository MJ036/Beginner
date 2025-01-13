#include "mai.h"
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
    inline double avg_price();

friend istream& read(istream& is, Sales_data& rhs);
friend ostream& print(ostream& os, Sales_data rhs);

};

//10_12
bool compareIsbn(Sales_data lhs, Sales_data rhs){
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
double Sales_data::avg_price(){
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
//void test_1(){
//    Sales_data total;
//    if(cin >> total.BookNo >> total.units_sold >> total.revenue){
//        Sales_data trans;
//        while(cin >> trans.BookNo >> trans.units_sold >> trans.revenue){
//            if(total.BookNo == trans.BookNo){
//                total.units_sold += trans.units_sold;
//                total.revenue+= trans.revenue;
//            }
//            else{
//                cout << total.BookNo << " " << total.units_sold << " " << total.revenue << endl;
//                total = trans;
//            }
//        }
//        cout << total.BookNo << " " << total.units_sold << " " << total.revenue << endl;
//    }else{
//        cerr << "error data" << endl;
//    }
//}
//
//void test_3(){
//    Sales_data total;
//    if(cin >> total.BookNo >> total.units_sold >> total.revenue){
//        Sales_data trans;
//        while(cin >> trans.BookNo >> trans.units_sold >> trans.revenue){
//            if(total.isbn() == trans.isbn()){
//                total.combine(trans);
//            }
//            else{
//                cout << total.BookNo << " " << total.units_sold << " " << total.revenue << endl;
//                total = trans;
//            }
//        }
//        cout << total.BookNo << " " << total.units_sold << " " << total.revenue << endl;
//    }else{
//        cerr << "error data" << endl;
//    }
//}
//

void test_7(){
    Sales_data total;
    if(read(cin,total)){
        Sales_data trans;
        while(read(cin,trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(cout,total);
                cout << endl;
                total = trans;
            }
        }
        print(cout,total);
        cout << endl;
    }else{
        cerr << "error data" << endl;
    }
}

void test_13(){
    Sales_data total(cin);
    if(!total.isbn().empty()){
        Sales_data trans;
        while(read(cin,trans)){
            if(total.isbn() == trans.isbn()){
                total.combine(trans);
            }
            else{
                print(cout,total);
                cout << endl;
                total = trans;
            }
        }
        print(cout,total);
        cout << endl;
    }else{
        cerr << "error data" << endl;
    }
}


int main()
{
    vector<Sales_data> vec;
    vec.push_back(Sales_data("003"));
    vec.push_back(Sales_data("009"));
    vec.push_back(Sales_data("002"));
    vec.push_back(Sales_data("001"));
    sort(vec.begin(),vec.end(),compareIsbn);
    for(auto num : vec){
        cout << num.isbn() << " ";
    }
    cout << endl;
    return 0;
}

