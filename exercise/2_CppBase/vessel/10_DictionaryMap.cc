#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::map;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::sort;

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
                if(string() != newWord){
                    ++_dict[newWord];
                }
            }
        }


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



    void store(const std::string &filename){
        ofstream ofs(filename);
        if(!ofs){
            cerr << "ofstream is not good" << endl;
            return ;
        }
        for(auto it = _dict.begin(); it != _dict.end(); ++it){
            ofs << it->first << " " << it->second << endl;
        }
        ofs.close();
    }

    

private:
    map<string,int> _dict;   
};

int main()
{
    Dictionary dictionary;
    
    dictionary.read("./source/The_Holy_Bible.txt");
    
    dictionary.store("./source/dictMap.dat");

    return 0;
}

