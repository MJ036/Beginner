#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::unordered_map;
using std::string;
using std::ifstream;
using std::istringstream;

class WordTrans{
public:
    void buildMap(const string &filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "open " << filename << "error" << endl;
            return;
        }
        
        string line;
        while(getline(ifs,line))
        {
            istringstream iss(line);
            string word,translation;
            if(iss >> word && getline(iss,translation)){
                if(!translation.empty()){
                    _um[word] = translation.substr(1);
                }
                else{
                    throw std::runtime_error("no rule for" + word);
                }
            }
        }

        ifs.close();

    }

    void trans(const string &filename){
        ifstream ifs(filename);
        if(!ifs){
            cerr << "open" << filename << " error" << endl;
            return;
        }

        string line;
        while(getline(ifs,line)){
                istringstream iss(line);
                string word;
                bool firstWord = true;
                while(iss >> word){
                    if(!firstWord){
                        cout << " ";
                    }
                    else{
                        firstWord = false;
                    }
                    auto it = _um.find(word);
                    if(it == _um.end()){
                        cout << word;
                    }
                    else{
                        cout << it->second;
                    }
                }
                cout << endl;
        }
        ifs.close();
    }


private:
    unordered_map<string,string> _um;
};

int main()
{
    WordTrans wt;
    wt.buildMap("/home/mai/my_source/map1.txt");
    wt.trans("/home/mai/my_source/file1.txt");
    return 0;
}

