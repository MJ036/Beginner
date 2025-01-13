#include "mai.h"

using namespace std;

int main()
{
    vector<string> text{"mai,jia","","Bao"};
    for(auto it = text.begin(); it != text.end() && !it->empty(); ++it){
        for(auto &c : *it){
            c = toupper(c);
        }
    }

    for(auto it = text.begin(); it != text.end(); ++it){
        cout << *it << endl;
    }
    return 0;
}

