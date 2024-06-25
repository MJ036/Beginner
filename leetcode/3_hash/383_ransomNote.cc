#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int result[26] = {0};
        if(ransomNote.size() > magazine.size()){
            return false;
        }
        for(int i = 0; i < (int)magazine.size(); i++){
            result[magazine[i] - 'a']++;
        }
        for(int i = 0; i < (int)ransomNote.size(); i++){
            result[ransomNote[i] - 'a']--;
            if(result[ransomNote[i] - 'a'] < 0){
                return false;
            }
        }
        return true;
    }
};
 

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

