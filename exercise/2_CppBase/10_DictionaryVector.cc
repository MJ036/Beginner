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

class Dictionary{
public:
    void read(const std::string &filename){

    }

    void dealWord(const string &word){

    }

    void insert(const string &word){

    }

    void store(const std::string &filename){

    }

    

private:
    vector<Record> _dict;
};

int main()
{
    Dictionary dictionary;
    
    dictionary.read("The_Holy_Bible.txt");
    
    dictionary.store("dictVec.dat");
    return 0 ;

    return 0;
}

