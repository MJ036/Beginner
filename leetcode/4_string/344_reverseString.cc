#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size()-1; i <(int)s.size()/2; j--,i++){
            swap(s[i],s[j]);
        }
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

