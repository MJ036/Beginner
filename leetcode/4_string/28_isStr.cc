#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void getNext(int *next, const string &s){
        int j = 0;
        next[0] = 0;
        for(int i = 0; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j-1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next,needle);
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
class Solution2{
    void getNext(int *next, const string &s){
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++){
            while(j > 0 && s[i] != s[j]){
                j = next[j-1];
            }
            if(s[j] == s[i]){
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack,string needle){
        if(needle.size() == 0){
            return 0;
        }
        int j = 0;
        int next[needle.size()];
        getNext(next,needle);
        for(int i = 0; i < haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j-1];
            }
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - needle.size() + 1);
            }
        }
        return -1;

    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    string s1 = "leetcode";
    string s2 = "leeto";
    Solution slt;
    cout << "答案:" << slt.strStr(s1,s2) << endl;
    return 0;
}

