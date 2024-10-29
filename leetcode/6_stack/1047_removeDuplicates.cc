#include "mai.h"

using namespace std;

int main()
{
    return 0;
}

class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(auto ch : s){
            if(result.empty() || result.back()!= ch){
                result.push_back(ch);
            }else{
                result.pop_back();
            }
        }
        return result;
    }
};

class solution2{
public:
string removeDuplicates(string s){
    string result;
    for(char c : s){
        if(result.empty() || c != result.back()){
            result.push_back(c);
        }
        else{
            result.pop_back();
        }
    }
    return result;
}
};