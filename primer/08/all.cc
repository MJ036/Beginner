#include "mai.h"

using namespace std;

istream& test_1(istream& io){
    char buf[1024] = {0};
    while(io >> buf){
        cout << buf;
    }
    io.clear();
    return io;
}

void test_4(){
    string file1("text");
    ifstream ifs(file1);

    vector<string> vec;
    string line;
    while(getline(ifs,line)){
        vec.push_back(line);
    }
    for(auto num : vec){
        cout << num << endl;
    }
}

void test_5(){
    string file1("text");
    ifstream ifs(file1);
    vector<string> vec;
    string line;
    while(ifs >> line){
        vec.push_back(line);
    }
    for(auto num : vec){
        cout << num << endl;
    }
}

void test_9(){
    string str("maijiabao");
    istringstream iss(str);
    test_1(iss);
    cout << endl;
}

void test_10(){
    ifstream ifs("text");
    string line;
    vector<string> vec;
    while(getline(ifs,line)){
        vec.push_back(line);
    }
    string word;
    for(auto num : vec){
            istringstream iss(num);
            while(iss >> word){
                cout << word << " ";
            }
    }
    cout << endl;
}

struct PersonInfo{
    string name;
    vector<string> phones;
};

bool valid(const string& str){
    for(auto num : str){
        if(!isdigit(num)){
            return false;
        }
    }
    return true;
}

string format(const string &s){
    return s;
}

void test_11_13(){
    ifstream ifs("text4");
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while(getline(ifs,line)){
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while(record >> word){
            info.phones.push_back(word);
        }
        record.clear();
        people.push_back(info);
    }
    for(const auto &entry : people){
        ostringstream badNums, formatted;
        cout << entry.name << " ";
        for(const auto &nums : entry.phones){
            if(!valid(nums)){
                badNums << " " <<  nums;
            }else{
                formatted << " " << nums;
            }
        }
        if(badNums.str().empty()){
            cout << entry.name << " " << formatted.str() << endl;
        }else{
            cerr << "input error: " << entry.name << " invalid number(S) " << badNums.str() << endl;
        }
        cout << endl;
    }
}

int main()
{
    test_11_13();
    return 0;
}

