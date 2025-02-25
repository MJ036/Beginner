#include "Sales_data.h"
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

ostream &operator<<(ostream &os,const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
istream &operator>>(istream &is,Sales_data &item){
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

Sales_data& Sales_data::operator+=(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs){
    auto sum = lhs;
    sum += rhs;
    return sum;
}


