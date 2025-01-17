#include "mai.h"
#include "Sales_item.h"
#include <algorithm>
#include <fstream>
#include <iterator>
#include <numeric>

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
            [sz](string &str){return str.size() >= sz; }
            );
    auto count  = words.end() - wc;
    cout << "count = " << count << endl;
    for_each(wc,words.end(),[](string &str){cout << str << " ";});
    cout << endl;
}
void test_18(vector<string> &words, vector<string>::size_type sz){
    test_11(words); //按字典序排序、去重、按照字符串长度从短到长排序
    auto wc = stable_partition(words.begin(),words.end(),
              [sz](string &str){return str.size() > sz;
              });
    auto count  = words.end() - wc;
    cout << "count = " << count << endl;
    for_each(wc,words.end(),[](string &str){cout << str << " ";});
    cout << endl;
}

void test_20(vector<string> &words){
    auto cn = count_if(words.begin(),words.end(),[](string &str){
                        return str.size() > 6;
                       });
    cout << cn << endl;
}

void test_21(){
    int a = 20;
    auto dec = [&a](){
        while(a > 0){
            a--;
        }
    };
    dec();
    cout << "a = " << a << endl;
}

bool less_equal_count(string &word,string::size_type sz){
    return  word.size() <= sz;
}

void test_22(vector<string> &words){
    using namespace placeholders;
    auto cn = count_if(words.begin(),words.end(),bind(less_equal_count,_1,6));
    cout << cn << endl;
}

bool check_size(const string &str1, string::size_type sz){
    return str1.size() < sz;
}
void test_24(){
    string str("mai");
    vector<int> vec = {1,2,3,4,5,1,2,3,4,5,6,7,8,1,2};
    using namespace placeholders;
    auto iter = find_if(vec.begin(),vec.end(),bind(check_size,str,_1));
    cout << *iter << endl;
}

void test_25(vector<string> &words, vector<string>::size_type sz){
    test_11(words); //按字典序排序、去重、按照字符串长度从短到长排序
    using namespace placeholders;
    auto wc = stable_partition(words.begin(),words.end(),bind(check_size,_1,sz));
    auto count  = words.end() - wc;
    cout << "count = " << count << endl;
    for_each(wc,words.end(),[](string &str){cout << str << " ";});
    cout << endl;
}

void test_27(vector<int> vec){
    vector<int> out;
    sort(vec.begin(),vec.end());
    unique_copy(vec.begin(),vec.end(),back_inserter(out));
    for_each(out.begin(),out.end(),[](int &str){cout << str << " ";});
}
void test_28(){
    list<int> lst;
    list<int> lst1;
    list<int> lst2;
    list<int> lst3;
    for(int i = 0; i < 10; i++){
        lst.push_back(i);
    }
    for(int i = 0;i < 10; i++){
        *back_inserter(lst1) = i;
        *front_inserter(lst2) = i;
        *inserter(lst3,lst3.begin()) = i;
    }
    for_each(lst1.begin(),lst1.end(),[](int &str){cout << str << " ";});
    cout << endl;
    for_each(lst2.begin(),lst2.end(),[](int &str){cout << str << " ";});
    cout << endl;
    for_each(lst3.begin(),lst3.end(),[](int &str){cout << str << " ";});
    cout << endl;
}

void test_29(){
    ifstream ifs("test");
    istream_iterator<string> item_iter(ifs),eof;
    ostream_iterator<string> otem_iter(cout," ");
    vector<string> vec;
    while(item_iter != eof){
        vec.push_back(*item_iter++);
    }
    copy(vec.begin(),vec.end(),otem_iter);
}
void test_30(){
    istream_iterator<int> item_iter(cin),eof;
    ostream_iterator<int> otem_iter(cout," ");
    vector<int> vec;
    while(item_iter != eof){
        vec.push_back(*item_iter++);
    }
    sort(vec.begin(),vec.end());
    unique_copy(vec.begin(),vec.end(),otem_iter);
    cout << endl;
}

void test_32(){
    istream_iterator<Sales_item> item_iter(cin),eof;
    ostream_iterator<Sales_item> otem_iter(cout," ");
    vector<Sales_item> vec;
    while(item_iter != eof){
        vec.push_back(*item_iter++);
    }
    sort(vec.begin(),vec.end(),compareIsbn);
    for(auto beg = vec.begin(), end = beg; beg != vec.end(); beg = end){
        end = find_if(beg,vec.end(),[beg](Sales_item sale){return sale.isbn() != beg->isbn(); });
        cout << accumulate(beg,end,Sales_item(beg->isbn())) << endl;
    }

}
void test_33(){
    ifstream ifs("test");
    ofstream ofs1("test1");
    ofstream ofs2("test2");
    istream_iterator<int> ist_ite(ifs), eof;
    ostream_iterator<int> ost_ite1(ofs1," ");
    ostream_iterator<int> ost_ite2(ofs2,"\n");
    while(ist_ite != eof){
        if(*ist_ite % 2 != 0){
            ost_ite1 = *ist_ite++;
        }else{
            ost_ite2 = *ist_ite++;
        }
    }
}

void test_34_35(vector<int> vec){
    for_each(vec.rbegin(),vec.rend(),[](int &a){cout << a << " ";});
    cout << endl;

    for(auto end = vec.end(); end != vec.begin();){
        cout << *--end << " ";
    }
    cout << endl;
}

void test_36(vector<int> vec){
    list<int> lst(vec.begin(),vec.end());
    auto c =find(lst.rbegin(),lst.rend(),0);
    cout << *++c << endl;
}

void test_37(){
    vector<int> vec;
    for(int i = 0; i < 10; i++){
        vec.push_back(i);
    }
    list<int> lst;
    copy(vec.rbegin() + 2, vec.rend() - 3,back_inserter(lst));
    for(auto num : lst){
        cout << num << " ";
    }
    cout << endl;

}

void test_42(list<int> &lst){
    lst.sort();
    lst.unique();
}

int main()
{
    list<int> lst = {1,2,3,4,5,1,2,3,4,5,6,7,8,1,2,0};
    vector<string> vec1 = {"mai","mai","jia","bao","tai","mai","shuai","maijiabao","maijialong"};
    test_42(lst);
    for(auto num : lst){
        cout << num << " ";
    }
    cout << endl;
    
    
}

