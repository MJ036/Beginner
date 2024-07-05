#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseStr(string s,int k){
        for(int i = 0; i < s.size();i += 2*k){
            if(i+k < s.size()){
                reverse(s.begin()+i,s.begin()+i+k);
            }else{
                reverse(s.begin(),s.end());
            }

        }
        return s;
    }













    string reverseStr1(string s, int k) {
        for(int i = 0; i < s.size(); i+= 2*k){
            if(i+k <= s.size()){
                reverse(s.begin()+i, s.begin()+i+k);
            }else{
                reverse(s.begin()+i,s.end());
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

