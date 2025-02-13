#include "mai.h"
#include "HaspPtr.h"
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<HasPtr> vec;
    string str{"mai"};
    vec.push_back(str);
    str = "jia";
    vec.push_back(str);
    str = "bao";
    vec.push_back(str);

    for(auto num : vec){
        cout << num.get_str() << " " << endl;
    }
    sort(vec.begin(),vec.end());
    for(auto num : vec){
        cout << num.get_str() << " " << endl;
    }
    return 0;
}

