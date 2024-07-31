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
