#include "mai.h"

using namespace std;

void test_31(){
    forward_list<int> lst  = {0,1,2,3,4,5,6,7,8,9};
    auto pre = lst.before_begin();
    auto cur = lst.begin();
    while(cur != lst.end()){
        if(*cur % 2){
            cur = lst.insert_after(pre,*cur);
            cur++;
            pre = cur;
            cur++;
        }else{
            pre = cur;
            cur++;
        }
    }
    for(auto num : lst){
        cout << num << " ";
    }
    cout << endl;
}

void test_33(){
    vector<int> vec = {0,1,2,3,4};
    auto begin = vec.begin();
    while(begin != vec.end()){
        ++begin;
        vec.insert(begin,10);
        ++begin;
    }
}
void test_34(){
    vector<int> vec = {0,1,2,3,4};
    auto it = vec.begin();
    while(it != vec.end()){
        if(*it % 2) it = vec.insert(it,*it);
        it++;
    }
}

void test_41(){
    vector<char> vec{'h','e','l','l','o'};
    string str(vec.begin(),vec.end());
    for(auto num : str){
        cout << num << " ";
    }
    cout << endl;
}
void test_42(){
    vector<char> vec{'h','e','l','l','o'};
    string str(vec.begin(),vec.end());
    str.reserve(100);
    cout << str.capacity() << endl;
}

void test_43(string &s, string oldVal, string newVal){
    auto it = s.begin();
    while(it != s.end()){
        auto cur = it;
        bool match = true;
        for(size_t i = 0; i < oldVal.length(); ++i){
            if(cur == s.end() || *cur != oldVal[i]){
                match = false;
                break;
            }
            ++cur;
        }
        if(match){
            it = s.erase(it,it + oldVal.length());
            it = s.insert(it,newVal.begin(),newVal.end());
            it +=newVal.length();
        }else{
            ++it;
        }
    }
}


void test_44(string &s, string oldVal, string newVal){
    for(size_t i = 0; i <= s.size()-oldVal.size();){
        if(s.substr(i,oldVal.length()) == oldVal){
            s.replace(i,oldVal.length(),newVal);
            i += newVal.length();
        }else{
            ++i;
        }
    }
}

void test_45(string &s, string str1, string str2){
    s.insert(0,str1);
    //test_45
    //s.append(str2);
    //test_46
    s.insert(s.size(),str2);
}

void test_47(){
    string str1("ab2c3d7R4E6");
    string num("1234567890");
    size_t pos = 0;
    while((pos = str1.find_first_not_of(num,pos)) != string::npos){
        cout << "pos:" << pos << " target:" << str1[pos] << endl;
        pos++;
    }
}

bool is_up_or_down(string &word){
    string up("bdfhijklt");
    string down("fgjpqy");
    for(auto c : word){
        c = tolower(c);
        if(up.find(c) != string::npos || down.find(c) != string::npos){
            return true;
        }
    }
    return false;
}

void test_49(ifstream &file){
    string word;
    string maxWord;
    while(file >> word){
        if(!is_up_or_down(word)){
            if(word.length() > maxWord.length()){
                maxWord = word;
            }
        }
    }
    if(!maxWord.empty()){
        cout << "maxWord:" <<  maxWord << endl;
    }else{
        cout << "no word" << endl;
    }
}

void test_50(){
    vector<string> vec{"1","2","3","4","5.5","6.5","7.5","8.5","9.5"};
    int i = 0;
    float f = 0;
    for(auto num : vec){
        i += stoi(num);
        f += stof(num);
    }
    cout << "i = " << i << endl;
    cout << "f = " << f << endl;
}

int main()
{
    test_50();
    //    string s("jia");
    //    string str1("mai");
    //    string str2("bao");
    //    test_45(s,str1,str2);
    //    cout << s << endl;
    //    string s = "This is a test tho this is only a test thru the end";
    //    string oldVal1 = "tho";
    //    string oldVal2 = "thru";
    //    string newVal1 = "though";
    //    string newVal2 = "through";
    //    test_44(s,oldVal1,newVal1);
    //    test_44(s,oldVal2,newVal2);
    //    cout << s << endl;
    return 0;
}

