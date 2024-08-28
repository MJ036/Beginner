#include "mai.h"

using namespace std;

int main()
{
    vector<string> vec{10,"mai"};
    vector<string> vec1(10,"mai");
    for(auto num : vec1){
        cout << num << " " ;
    }
    return 0;
}

