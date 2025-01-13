#include "mai.h"

using namespace std;

int main()
{
    string str;
    vector<string> vec;
    while(cin >> str){
        vec.push_back(str);
    }

    for(auto &s : vec){
        for(auto &c : s){
                c = toupper(c);
        }
        cout << s << "\n";
    }

    return 0;
}

