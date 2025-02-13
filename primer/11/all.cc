#include "mai.h"
#include "/home/mai/Beginner/primer/07/Sales_data.h"
#include <algorithm>
#include <map>
#include <set>
using namespace std;

void test_4(){
    map<string,size_t> word_count;
    string word;
    while(cin >> word){
        word.erase(remove_if(word.begin(), word.end(),[](unsigned char c){return ispunct(c);}), word.end());
		for_each(word.begin(), word.end(), [](char &c){ c=std::tolower(c); });
		++word_count[word];
    }
    for(auto &w : word_count){
        cout << w.first << " occur " << w.second << (w.second > 1 ? " times" : " time") << endl;
    }
    cout << endl;
}

void test_7(){
    map<string,vector<string>> familys;
    string last_name;
    string first_name;
    vector<string> number;
    cout << "Enter last_name: ";
    cin >> last_name;
    cout << endl;
    cout << "Enter number: ";
    while(cin >> first_name){
        number.push_back(first_name);
    }
    familys[last_name] = number;

    for(auto n : familys){
        cout << n.first << " family, has ";
        for(auto n1 : n.second){
            cout << n1 << " ";
        }
    }
    cout << endl;
}

void test_8(){
    vector<string> words;
    cout << "Enter word: ";
    string word;
    while(cin >> word){
        if(find(words.begin(),words.end(),word) == words.end()){
            words.push_back(word);
        }
        cout << "Enter word: ";
    }
    cout << endl;
    for(auto w : words){
        cout << w << " ";
    }
    cout << endl;
}

void test_9(){
    map<string,list<int>> word_lines;
    string word;
    int line;
    list<int> lines;
    while(cin >> word){
        while(cin >> line){
            lines.push_back(line);
        }
        word_lines[word] = lines;
    }

    for(auto n : word_lines){
        cout << n.first << "at lines: ";
            for(auto n1 : n.second){
                cout << n1 << ",";
            }
    }
    cout << endl;

}
void test_11(){
    using Less = bool (*)(const Sales_data&, const Sales_data&);
    multiset<Sales_data,Less> bookstore(compareIsbn);
}

void test_12_13(){
    vector<pair<string,int>> vec_string_int;
    string a;
    int b;

    vec_string_int.push_back(make_pair(a,b));

    vec_string_int.push_back({a,b});

    vec_string_int.push_back(pair<string,int>(a,b));
}

void test_14(){
    map<string,vector<pair<string,string>>> familys;
}

//test_15
//map<int,vector<int>>. int , int , vector<int>

void test_16(){
    map<int,vector<int>> my_map;
    auto it = my_map.begin();
    vector<int> val;
    it->second = val;
}

//test_17 第二个不合法，multiset没有push_back方法
//test_18 vector<string,size_t>::const_iterator

void test_19(){
    using Less = bool (*)(const Sales_data&, const Sales_data&);
    multiset<Sales_data,Less> bookstore(compareIsbn);
    multiset<Sales_data,Less>::iterator it = bookstore.begin();
    
}

void test_20(){
    map<string,size_t> word_count;
    string word;
    while(cin >> word){
        word.erase(remove_if(word.begin(), word.end(),[](unsigned char c){return ispunct(c);}), word.end());
		for_each(word.begin(), word.end(), [](char &c){ c=std::tolower(c); });
        ++word_count.insert({word,0}).first->second;
    }
    for(auto &w : word_count){
        cout << w.first << " occur " << w.second << (w.second > 1 ? " times" : " time") << endl;
    }
    cout << endl;

}

//test_22
//    map<string,vector<int>>
//    pair<string,vector<int>>
//    pari<map<string,vector<int>>::iterator,bool>

void test_23(){
    multimap<string,vector<string>> familys;
    string last_name;
    string first_name;
    vector<string> number;
    cout << "Enter last_name: ";
    cin >> last_name;
    cout << endl;
    cout << "Enter number: ";
    while(cin >> first_name){
        number.push_back(first_name);
    }
    familys.insert({last_name,number});

    for(auto n : familys){
        cout << n.first << " family, has ";
        for(auto n1 : n.second){
            cout << n1 << " ";
        }
    }
    cout << endl;

}

void test_26(){
    map<int,int> m = {{1,11},{2,22}};
    map<int,int>::key_type key = 1;
    map<int,int>::mapped_type ret = m[key];
    cout << ret << endl;
}

void test_29(){
    map<string,vector<int>> m = {{"mai",{1,2,3}},{"jia",{4,5,6}},{"bao",{7,8,9}}};
    auto fd = m.find("mai");
    for(auto num : fd->second){
        cout << num << " ";
    }
    cout <<endl;
}
void test_31(){
    multimap<string,string> authors{
        {"mai","a"},
            {"jia","b"},
            {"bao","c"},
            {"mai","d"},
            {"bao","e"}
    };
    string author = "mai";
    string work = "d";
    auto cnt = authors.count(author);
    auto found = authors.find(author);
    while(cnt){
        if(found->second == work){
            authors.erase(found);
            break;
        }
        ++found;
        --cnt;
    }

    for(const auto &author : authors){
        cout << author.first << " " << author.second << endl;
    }
}
void test_32(){
    multimap<string,string> authors{
            {"mai","a"},
            {"jia","b"},
            {"bao","c"},
            {"mai","d"},
            {"bao","e"},
            {"bao","a"}
    };
    map<string,multiset<string>> order_authors;
    for(auto author : authors){
        order_authors[author.first].insert(author.second);
    }
    for(auto author : order_authors){
        cout << author.first << ": ";
        for(auto work : author.second){
            cout << work << " ";
        }
        cout << endl;
    }
}

int main()
{
    test_32();

    return 0;
}

