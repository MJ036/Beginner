#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string dynamicPassword(string password, int target) {
        reverse(password.begin(),password.begin()+target);
        reverse(password.begin()+target,password.end());
        reverse(password.begin(),password.end());
        return password;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

