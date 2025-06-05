#include "mai.h"
#include <memory>
using namespace std;

class Solution {
private:
    //存结果
    vector<string> results;
    //存当前路径。符合条件时加入结果
    string path;

    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    void backtracing(string digits, int startIndex){
        if(startIndex == digits.size()){
            results.push_back(path);
            return;
        }
        string letters = letterMap[ digits[startIndex] - '0'];
        for(int i = 0; i < letters.size(); i++){
            path.push_back(letters[i]);
            backtracing(digits,startIndex + 1);
            path.pop_back();
        }
    }   
public:
    vector<string> letterCombinations(string digits) {
        path.clear();
        results.clear();
        if(digits.size() == 0){
            return results;
        }
        backtracing(digits,0);
        return results;
    }
};
