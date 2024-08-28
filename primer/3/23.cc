#include "mai.h"

using namespace std;

int main()
{
    vector<int> vec = {10,20,30,40,50,50,70,80,90,100};
    for(auto it = vec.begin(); it != vec.end(); ++it){
        *it = 2*(*it);
    }
    for(auto num : vec){
        cout << num << " ";
    }
    return 0;
}

