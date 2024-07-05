#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void removeExtraSpace(string & s){ 
        int slow = 0;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] != ' '){
                if(slow != 0) s[slow++] = ' ';
                while(i < s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s.begin(),s.end());
        for(int i = 0,start = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                reverse(s.begin()+start,s.begin()+i);
                start = i+1 ;
            }
        }
        return s;
        
    }
};

    int main()
    {
        std::cout << "Hello world" << std::endl;
        return 0;
    }

