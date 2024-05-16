#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Record{
    Record(const string & word, int frequency)
        :_word(word)
         ,_frequency(frequency)
    {}

    string _word;
    int _frequency;
};

bool operator<(const Record &lhs, const Record & rhs){
    return lhs._word < rhs._word;
}

class Dictionary
{
public:
    Dictionary(int capacity)
    {
        _dict.reserve(capacity);
    }

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
                insert(newWord);
            }
        }
        sort(_dict.begin(),_dict.end());
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

    void insert(const string & word){
        if(word == string()){
            return;
        }
        
        size_t idx = 0;
        for(; idx < _dict.size(); ++idx){
            if(word == _dict[idx]._word){
                ++_dict[idx]._frequency;
                    break;
            }
        }

        if(idx == _dict.size()){
            _dict.push_back(Record(word,1));
        }
    }

    void store(const std::string &filename){
        ofstream ofs(filename);
        if(!ofs){
            cout << "fail" << endl;
            return;
        }

        for(size_t idx = 0; idx < _dict.size(); ++idx){
            cout << _dict[idx]._word << "  " << _dict[idx]._frequency << endl;
        }
        ofs.close();
    }
private:
    vector<Record> _dict;
};

void test0(){
    Dictionary dict(10000);
    cout << "before reading ..." << endl;
    time_t beg = time(NULL);
    dict.read("The_Holy_Bible.txt");
    time_t end = time(NULL);
    cout << "time:" << (end - beg) << "s" << endl;
    cout << "after reading ..." << endl;
    dict.store("dictVector.dat");
} 

int main()
{
    test0();
    return 0;
}

