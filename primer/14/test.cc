#include "mai.h"
#include "String.h"
#include "Sales_data.h"
using namespace std;

int test()
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

void test1(){
    String s("maijiabao");
    String s1("Maijiabao");
    String s2("maijiabao");
    cout << s << endl;
    cout << (s == s1) << endl;
    cout << (s == s2) << endl;
    cout << s[1] << endl;
}

void test2(){
    
}

int main()
{
    test1();

    return 0;
}

