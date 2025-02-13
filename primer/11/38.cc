#include "mai.h"
using namespace std;

//单词计数程序
void count_word(){
    unordered_map<string,size_t> word_count;
    string word;
    while(cin >> word){
        word.erase(remove_if(word.begin(), word.end(),[](unsigned char c){return ispunct(c);}), word.end());
		for_each(word.begin(), word.end(), [](char &c){ c=std::tolower(c); });
		++word_count[word];
    }
    for(auto &w : word_count){
        cout << w.first << " occur " << w.second << (w.second > 1 ? " times" : " time") << endl;
    }
    cout << endl;
}

//单词转换程序
unordered_map<string,string> buildMap(ifstream &map_file){
    unordered_map<string,string> trans_map;
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

const string & transform(const string &s, unordered_map<string,string> &m){
    //auto unordered_map_it = m[s];
    auto unordered_map_it = m.find(s);
    if(unordered_map_it != m.end()){
        return unordered_map_it->second;
    }else{
        return s;
    }

}

void word_transform(ifstream &map_file, ifstream &input){
    auto trans_unordered_map = buildMap(map_file);
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
            cout << transform(word,trans_unordered_map);
        }
        cout << endl;
    }
}

int main()
{
   // count_word();
    ifstream file1("rule_file");
    ifstream file2("input_file");
    word_transform(file1,file2);

    return 0;
}

