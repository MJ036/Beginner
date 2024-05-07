#include "TextQuery.h"
#include <fstream>
#include <sstream>

using namespace std;

TextQuery::TextQuery()
{
    _file.reserve(100);
}

void TextQuery::readFile(const string &filename){
    ifstream ifs(filename);
    if(!ifs)
    {
        std::cerr << "ifstream open" << filename << "error!" << endl;
        return;
    }

    string line;
    size_t lineNumber = 0;
    while(getline(ifs,line)){
        _file.push_back(line);
        preProcessLine(line);
        istringstream iss(line);
        string word;
        while(iss >> word){
            ++_dict[word];
            _word2line[word].insert(lineNumber);
        }

        ++lineNumber;
    }
    ifs.close();
}

void TextQuery::query(const string &word)
{
    int count = _dict[word];
    cout << word << "occurs " << count << (count > 1 ? " times" : " time.") << endl;

    auto lines = _word2line[word];
    for(auto &number : lines)
    {
        cout << " (line" << number + 1 << ")" << _file[number] << endl;
    }
}

        
void TextQuery::preProcessLine(string &line){
    for(auto &ch : line){
        if(!isalpha(ch)){
            ch = ' ';
        }
        else if(isupper(ch)){
            ch = tolower(ch);
        }
    }
}



