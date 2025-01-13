#include "mai.h"

using namespace std;

int main()
{
    vector<string> vec;
    string str;
    while(cin >> str){
        vec.push_back(str);
        cout << "size = " << vec.size() << " capacity = " << vec.capacity();
    }
    return 0;
}

