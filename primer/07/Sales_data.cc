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


int main()
{
    vector<Sales_data> vec;
    vec.push_back(Sales_data("003"));
    vec.push_back(Sales_data("009"));
    vec.push_back(Sales_data("002"));
    vec.push_back(Sales_data("001"));
    //sort(vec.begin(),vec.end(),compareIsbn);
    sort(vec.begin(),vec.end(),[](Sales_data &sale1, Sales_data &sale2){
            return sale1.isbn() < sale2.isbn();
         });
    for(auto num : vec){
        cout << num.isbn() << " ";
    }
    cout << endl;
    return 0;
}

