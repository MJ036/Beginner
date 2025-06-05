#include "mai.h"
#include "template.h"
#include "Blob_template.h"
#include "../shared/Sales_data.h"
#include "Screen.h"
#include "Vec_template.h"
#include "print_template.h"
#include "DebugDelete.h"
using namespace std;

void test_2(){
    string str1("a");
    string str2("b");
    int i1 = 2;
    int i2 = 1;
    cout << my::compare(str1,str2) << endl;
    cout << my::compare(i1,i2) << endl;
}


void test_3(){
    Sales_data s1("001",1,10);
    Sales_data s2("002",1,15);
    //cout << compare(s1,s2) << endl;
}

void test_4(){
    vector<int> vec{1,2,3,4,5,6,7,8};
    auto ret = my::find(vec.begin(),vec.end(),3);
    if(ret != vec.end()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    list<string> lst{"a","b","c","d"};
    string str("z");
    auto ret1 = my::find(lst.begin(),lst.end(),str);
    if(ret1 != lst.end()){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}

void test_5(){
    int a[5] = {1,2,3,4,5};
    my::print(a);
}

void test_12(){
    Blob<std::string> strBlob{"mai","jia","bao"};
    strBlob.push_back("tai shuai la");
    while(!strBlob.empty()){
        cout << strBlob.back();
        strBlob.pop_back();
    }
}

void test_15(){
    Screen<4,4> s('s');
    cout << s;
}

void test_16(){
    Vec<string> strvec{"mai","jia","bao"};
    auto beg = strvec.begin();
    auto end = strvec.end();
    while(beg != end){
        cout << *beg << endl;
        beg++;
    }
}

void test_19(){
    vector<int> vec = {1,2,3,4,5};
    string str = {"maijiabao"};
    vector<string> vs = {"mai jia bao", "tai shuai la"};
    print(vs);
    
}

void test_21(){
    DebugDelete d(cout);   
    auto p = new int;
    d(p);
}

void test_24(){

    vector<std::string> strBlob{"mai","jia","bao"};
    Blob<string> strb(strBlob.begin(),strBlob.end());
    while(!strb.empty()){
        cout << strb.back();
        strb.pop_back();
    }
}
int main()
{
    test_24();
    return 0;
}

