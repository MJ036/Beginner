#include "mai.h"
#include <cstring>
using namespace std;

int main()
{
    string str;
    cin >> str;
    char* p = new char[str.size()];
    for(int i = 0; i < str.size(); i++){
        *(p+i) = str[i];
    }
    for(int i = 0; i < strlen(p); i++){
        cout << *(p+i);
    }


    return 0;
}

