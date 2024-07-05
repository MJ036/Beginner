#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin());
        t.erase(t.end()-1);
        if(t.find(s) != -1) return true;
        return false;
    }
};

 bool repeatedSubstringPattern(string s) {
     string t = s+s;
     t.erase(t.begin());t.erase(t.end()-1);
     if(t.find(s) != std::string::npos){
         return true;
     }else{
         return false;
     }
 }

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

