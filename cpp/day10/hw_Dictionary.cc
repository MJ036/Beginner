#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

struct Record
{
    Record(const string &word,int frequency)
        :_word(word)
         ,_frequency(frequency)
    {}
    string _word;
    int _frequency;
};

bool operator<(const Record &lhs,const Record &rhs)
{
    return lhs._word < rhs._word;
}

class Dictionary
{
public:
    Dictionary(int capa)
    {
        _dict.reserve(capa);
    }
    void read(const string &filename)
    {
        ifstream ifs(filename);
            if(!ifs)
            {
                cerr << "open" << filename << "fail" << endl;
                return;
            }

            string line;
            while(getline(ifs,line))
            {
                istringstream iss(line);
                string word;
                while(iss >> word)
                {
                    string newWord = dealWord(word);
                    insert(newWord);
                }
            }
            sort(_dict.begin(),_dict.end());

            ifs.close();
    }

    void store(const string &filename)
    {
        ofstream ofs(filename);
        if(!ofs)
        {
            std::cerr << "open" << filename << "fail" << endl;
            return;
        }

        for(size_t idx = 0; idx != _dict.size(); ++idx)
        {
            ofs << _dict[idx]._word << "  " << _dict[idx]._frequency << endl;
        }

        ofs.close();
    }

    string dealWord(const string &word){
        for(size_t idx = 0; idx != word.size(); ++idx)
        {
            if(!isalpha(word[idx]))
            {
                return string();
            }
        }
        return word;
    }

    void insert(const string &word)
    {
        if(word == string())
        {
            return;
        }
        size_t idx;
        for(idx = 0; idx != _dict.size(); ++idx)
        {
            if(word == _dict[idx]._word)
            {
                ++_dict[idx]._frequency;
                break;
            }
        }

        if(idx == _dict.size())
        {
            _dict.push_back(Record(word,1));
        }
    }

private:
    vector<Record> _dict;
};


int main()
{
    Dictionary dictionary(13000);

    dictionary.read("The_Holy_Bible.txt");
    dictionary.store("dict.data");

    return 0;
}

