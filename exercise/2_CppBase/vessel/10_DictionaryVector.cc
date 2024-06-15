#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::sort;

//统计词典中，单词次数。 定义一个结构体存储单词及其次数。
//打开文件，读一行，从中读单词，处理，缓存，写入文件

struct Record{
    Record(const string &word,int frequency):_word(word),_frequency(frequency){}

    string _word;
    int _frequency;
};

bool operator<(const Record &lhs, const Record &rhs){
    return lhs._word < rhs._word;
}

class Dictionary{
public:
    void read(const std::string &filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "ifstream is not good" << endl;
            return;
        }

        string line;
        while(getline(ifs,line)){
            string word;
            istringstream iss(line);
            while(iss >> word){
                string newWord = dealWord(word);
                insert(newWord);
            }
        }

        sort(_dict.begin(),_dict.end());

        ifs.close();
    }


    string dealWord(const string &word){
        for(size_t idx = 0; idx != word.size(); ++idx){
            if(!isalpha(word[idx])){
                return string();
            }
        }
        return word;
    }

    void insert(const string &word){
        if(word == string()){
            return;
        }
        size_t idx = 0;
        for(idx = 0;idx != _dict.size(); ++idx){
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
            cerr << "ofstream is not good" << endl;
            return ;
        }
        for(size_t idx = 0; idx != _dict.size(); ++idx){
            ofs << _dict[idx]._word << " " << _dict[idx]._frequency << endl;
        }
        ofs.close();
    }

    

private:
    vector<Record> _dict;
};

int main()
{
    Dictionary dictionary;
    
    dictionary.read("./source/The_Holy_Bible.txt");
    
    dictionary.store("./source/dictVec.dat");

    return 0;
}

