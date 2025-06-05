#include "mai.h"
#include <string>
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> results;
    bool isPalindromic(const string& str, int begin, int end){
        for(int b = begin,e = end; b < e; b++,e--){
            if(str[b] != str[e]){
                return false;
            }
        }
        return true;
    }

    void backtracing(string str,int startIndex){
        if(startIndex >= str.size()){
            results.push_back(path);
            return;
        }
        for(int i = startIndex; i < str.size(); ++i){
            if(isPalindromic(str,startIndex,i)){
                auto s = str.substr(startIndex,i - startIndex + 1);
                path.push_back(s);
            }else{
                continue;
            }
            backtracing(str,i+1);
            path.pop_back();
        }



    }
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        results.clear();
        backtracing(s,0);
        return results;
        
    }
};
