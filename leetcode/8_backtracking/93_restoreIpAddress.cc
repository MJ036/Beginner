#include "mai.h"
#include <cctype>
#include <ctime>
#include <iterator>
#include <memory>
#include <type_traits>
using namespace std;

class Solution {
    vector<string> results;

    bool isValid(const string &s ,int startIndex, int endIndex){
        if(startIndex > endIndex){
            return false;
        }
        //0开头的不行
        if(s[startIndex] == '0' && startIndex != endIndex){
            return false;       //0开头的多位数字不行
        }
        int sum = 0;
        for(int i = startIndex; i <= endIndex; ++i){
            if(!isdigit(s[i])){
                return false;   //不是数字不行
            }
            sum = sum * 10 + (s[i] - '0');
            if(sum > 255){  //超过255不行
                return false;
            }
        }
        return true;

    }

    void backtracing( string& s, int startIndex, int pointNum){
        if(pointNum  == 3){
            if(isValid(s,startIndex,s.size()-1)){
                results.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); ++i){
            if(isValid(s,startIndex,i)){
                s.insert(s.begin() + i + 1,'.');
                ++pointNum;
                backtracing(s,i+2,pointNum);
                s.erase(s.begin() + i + 1);
                --pointNum;
            }else{
                break;
            }
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        results.clear();
        if(s.size() < 4 || s.size() > 12) return results;
        backtracing(s,0,0);
        return results;
    }
};
