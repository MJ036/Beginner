#include <iostream>
#include <set>
#include <map>
#include <string>
#include <utility>

using namespace std;

void test()
{

    //set<int> number = {1,6,8,23,6,7,2};
    int arr[10] = {1,6,8,23,6,7,2};
    set<int> number(arr,arr+10);

    set<int>::iterator it;
    for(it = number.begin(); it != number.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    for(auto &elem : number){
        cout << elem << " ";
    }
    cout << endl;

    size_t cnt1 = number.count(10);
    size_t cnt2 = number.count(23);
    cout << "cnt1 = " << cnt1 << endl
        << "cnt2 = " << cnt2 << endl;

    //set<int>::iterator it2 = number.find(10);
    auto it2 = number.find(10);
    if(it2 == number.end()){
        cout << "exist" << endl;
    }
    else{
        cout << "not exist" << endl;
    }

    //pair<set<int>::iterator,bool> ret = number.insert(2);
    auto ret = number.insert(2);
    if(ret.second){
        cout << "success" << *ret.first << endl;
    }
    else{
        cout << "failed" << endl;
    }
    
   // cout << number[0];
        cout << endl;
//    auto it3 = number.begin();
//    cout << "*it3 = " << *it3 << endl;
//    *it3 = 100;
}

void test00()
{
    pair<int,string> number(1,"hello");
    cout << number.first << " " << number.second << endl;
}


void test2(){
    map<string,string> number = {
        {"100","武汉"},
        {"200","北京"},
        {"300","武汉"},
        pair<string,string>("004","深圳")
    };
    
    for(auto &elem : number){
        cout << elem.first << " " << elem.second << endl;
    }
    cout << endl;
    
    auto it = number.find("100");
    if(it == number.end()){
        cout << "failed" << endl;
    }
    else{
        cout << "success" << it->first << " " << it->second << endl;
    }

    cout << endl << "print test" << endl;
    auto ret = number.insert({"000","台湾"});
    if(ret.second){
        cout << "success" << ret.first->first << " " << ret.first->second << endl;
    }
    else{
        cout << "failed";
    }
    
    for(auto &elem : number)
    {
        cout << elem.first << " " << elem.second << endl;
    }
    cout << endl;

    cout << endl;
    cout  << "number[\"010\"] = " << number["010"] << endl;
    cout  << "number[\"022\"] = " << number["022"] << endl;

    cout << endl;
    for(auto &elem : number){
        cout << elem.first << " " << elem.second << endl;
    }
    cout << endl;
    
    number["022"] = "东京";
    for(auto &elem : number){
        cout << elem.first << " " << elem.second << endl;
    }
    cout << endl;

    
    
}

int main()
{
    test2();
    
    return 0;
}

