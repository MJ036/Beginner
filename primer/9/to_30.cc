#include "mai.h"
using namespace std;
//9_2
//list<deque<int>> myList;

bool test_4(vector<int>::iterator beg,vector<int>::iterator end, int val){
    while(beg != end){
        if(*beg == val){
            return true;
        }
        beg++;
    }
    return false;
}

vector<int>::iterator test_5(vector<int>::iterator beg,vector<int>::iterator end, int val){
    while(beg != end){
        if(*beg == val){
            return beg;
        }
        beg++;
    }
    return end;
}

void test_13(){
    list<int> num1{1,3,5,7,9};
    vector<int> num2{1,3,5,7,9};
    //vector<double> num(num1.begin(),num1.end());
    vector<double> num(num1.begin(),num1.end());
    for(auto n : num){
        cout << n << " ";
    }
    cout << endl;
}

void test_14(){
    char str1[] = "hello";
    char str2[] = "world";
    char str3[] = "morning";
    list<char*> mylist{str1,str2,str3};
    vector<string> vec(mylist.begin(),mylist.end());
    for(auto n : vec){
        cout << n << " ";
    }
    cout << endl;

}

void test_18_19(){
    string str;
    list<string> cta;
    while(cin >> str){
        cta.push_back(str);
    }
    for(auto n : cta){
        cout << n << " ";
    }
    cout << endl;
}
void test_20(){
    list<int> lst{1,3,5,7,8,10};
    deque<int> odd;
    deque<int> even;
    for(auto num : lst){
        if(num % 2 != 0){
            odd.push_back(num);
        }else{
            even.push_back(num);
        }
    }
    for(auto n : odd){
        cout << n << " ";
    }
    cout << endl;
    for(auto n : even){
        cout << n << " ";
    }
    cout << endl;
}

void test_22(){
    vector<int> vec{1,3,5,7,8,10};
    auto iter = vec.begin();
    auto mid = vec.begin() + vec.size()/2;
    int val;
    cin >> val;
    while(iter != mid){
        if(*iter == val){
            iter = vec.insert(iter,2 * val);
            iter++;
            mid = vec.begin() + vec.size()/2;
        }
        iter++;
    }
    for(auto n : vec){
        cout << n << " ";
    }
    cout << endl;
}

void test_24(){
    vector<int> vec{1,3,5,7,8,10};
    cout << vec.at(1) << endl;
    cout << vec[1] << endl;
    cout << vec.front() << endl;
    cout << vec.back() << endl;

}

void test_25(){
    vector<int> vec{1,3,5,7,8,10};
    vec.erase(vec.end(),vec.end());
    for(auto &num : vec){
        cout << num << " ";
    }
    cout << endl;
}

void test_26(){
    int ia[] = {1,3,5,7,8,10};
    vector<int> vec(begin(ia),end(ia));
    list<int> lst(begin(ia),end(ia));

    auto it = vec.begin();
    while(it != vec.end()){
        if(*it % 2){
            it++;
        }else{
            it = vec.erase(it);
        }
    };
    for(auto &num : vec){
        cout << num << " ";
    }
    cout << endl;

    auto it2 = lst.begin();
    while(it2 != lst.end()){
        if(*it2 % 2){
            it2 = lst.erase(it2);
        }else{
            it2++;
        }
    };
    for(auto &num : lst){
        cout << num << " ";
    }
    cout << endl;
}

void test_27(){
    forward_list<int> lst{1,3,5,7,8,10};
    auto pre = lst.before_begin();
    auto cur = lst.begin();
    while(cur != lst.end()){
        if(*cur % 2){
            cur = lst.erase_after(pre);
        }else{
            pre = cur;
            ++cur;
        }
    }

    for(auto &num : lst){
        cout << num << " ";
    }
    cout << endl;
}

void test_28(forward_list<string> &lst,const string str1,const string str2){
    auto pre = lst.before_begin();
    auto cur = lst.begin();
    while(cur != lst.end()){
        if(*cur == str1){
            lst.insert_after(cur,str2);
            break;
        }else{
            pre = cur;
            ++cur;
        }
    }
    if(cur == lst.end()){
        lst.insert_after(pre,str2);
    }
}

int main()
{
    forward_list<string> lst{"mai","jia","bao"};
    string str1 = "ji";
    string str2 = "shuai";
    for(auto &num : lst){
        cout << num << " ";
    }
    cout << endl;
    test_28(lst,str1,str2);
    for(auto &num : lst){
        cout << num << " ";
    }
    cout << endl;
//    vector<int> vec{1,3,5,7,8,10};
//    auto beg = vec.begin();
//    auto end = vec.end();
//    int val;
//    cin >> val;
//    auto flag = test_5(beg,end,val);
//    if(flag == end){
//        cout << "false" << endl;
//    }else{
//        cout <<"true" << endl;
//    }
    return 0;
}

