#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;
class Dictionary
{
public:

    void read(const std::string &filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "if open file fail" << endl;
            return;
        }
        
        string line;
        while(getline(ifs,line)){
            istringstream iss(line);
            string word;
            while(iss >> word){
                string newWord = dealWord(word);
                if(newWord != string()){
                    ++_map[newWord];
                }
            }
        }
        ifs.close();
    }

    string dealWord(string word){
        for(size_t idx = 0; idx != word.size(); ++idx){
            if(!isalpha(word[idx])){
                return string();
            }else if(isupper(word[idx])){
                word[idx] = tolower(word[idx]);
            }
        }
        return word;
    }

    void store(const std::string &filename){
        ofstream ofs(filename);
        if(!ofs){
            cout << "fail" << endl;
            return;
        }

        map<string,int>::iterator it = _map.begin();
        for(; it != _map.end(); ++it){
            ofs << it->first << " " << it->second << endl;
        }

        ofs.close();
    }
private:
    map<string,int> _map;
};

void test0(){
    Dictionary dict;
    cout << "before reading ..." << endl;
    time_t beg = time(NULL);
    dict.read("The_Holy_Bible.txt");
    time_t end = time(NULL);
    cout << "time:" << (end - beg) << "s" << endl;
    cout << "after reading ..." << endl;
    dict.store("dictVector.dat");
} 

void test(){
    map<string,int> m2 = {{"abandon",5}};
    ++m2["abandon"];
    auto it = m2.begin();
    cout << it->first << " " << it->second << endl;
}

int main()
{
    test0();
    return 0;
}

