#include "mai.h"

using namespace std;

void test_1(vector<int> vec){
    cout << count(vec.begin(),vec.end(),1) << endl;
    list<string> lst = {"mai","jia","bao","mai","mai"};
    cout << count(lst.begin(),lst.end(),"mai") << endl;
}

int test_2(vector<double> vec){
    int sum = accumulate(vec.begin(),vec.end(),0.0);
    return sum;
}

void test_5(){
    char str1[] = "maijiabao";
    char str2[] = "maijiabai";
    if(equal(begin(str1),end(str1),begin(str2))){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}

void test_6(vector<int> &vec){
    fill_n(vec.begin(),5,0);
}

void test_9(vector<string> &vec){
    sort(vec.begin(),vec.end());
    auto end = unique(vec.begin(),vec.end());
    vec.erase(end,vec.end());
}

bool isShorter(string str1, string str2){
    return str1.size() < str2.size();
}

void test_11(vector<string> &vec){
    test_9(vec);
    stable_sort(vec.begin(),vec.end(),isShorter);

}

// 10_12 详见第七章Sales

bool test_13_predicate(string str){
    return str.size() > 5;
}
void test_13(vector<string> &vec){
    partition(vec.begin(),vec.end(),test_13_predicate);

}

void test_14(){
    auto add_int = [](int a, int b){
        return a+b;
    };
    cout << add_int(2,3) << endl;
}

void test_15(){
    int out = 5;
    auto add_int = [out](int a){
        return a+out;
    };
    cout << add_int(2) << endl;
}

void test_16(vector<string> &words, vector<string>::size_type sz){
    test_11(words); //按字典序排序、去重、按照字符串长度从短到长排序
    auto wc = find_if(words.begin(),words.end(),
            [sz](vector<string> &str){return str.size() >= sz; }
            );
    auto count  = words.end() - wc;
    cout << "count = " << count << endl;
    for_each(wc,words.end(),[](string &str){cout << str << " ";});
    cout << endl;


}

int main()
{
    vector<int> vec = {1,2,3,4,5,1,2,3,4,5,6,7,8,1,2};
    vector<string> vec1 = {"mai","mai","jia","bao","tai","mai","shuai","maijiabao","maijialong"};
    test_16(vec1,4);
//    for(auto &num : vec1){
//        cout << num << " " ;
//    }
//    cout << endl;
//    return 0;
}

