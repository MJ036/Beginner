#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

void readConfig(const string & filename){
    ifstream ifs(filename);
    if(!ifs.good()){
        cout << "open file fail!" << endl;
        return;
    }

    string line;
    string key,value;
    while(getline(ifs,line)){
        istringstream iss(line);
        iss >> key >> value;
        cout << key << "----->" << value << endl;
    }
}

void test0(){
    readConfig("myserver.conf");
}

int main()
{
    test0();
    return 0;
}

