#include "mai.h"
using namespace std;

map<string,string> buildMap(ifstream &map_file){
    map<string,string> trans_map;
    string key,value;
    while(map_file >> key && getline(map_file,value)){
        if(value.size() > 1){
            trans_map[key] = value.substr(1);
        }else{
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const string & transform(const string &s, map<string,string> &m){
    //auto map_it = m[s];
    auto map_it = m.find(s);
    if(map_it != m.end()){
        return map_it->second;
    }else{
        return s;
    }

}

void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string line;
    while(getline(input,line)){
        istringstream istr(line);
        string word;
        bool firstword = true;
        while(istr >> word){
            if(firstword){
                firstword = false;
            }else{
                cout << " ";
            }
            cout << transform(word,trans_map);
        }
        cout << endl;
    }
}

int main()
{
    ifstream file1("rule_file");
    ifstream file2("input_file");
    word_transform(file1,file2);

    return 0;
}

