#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string pathEncryption(string path) {
       for(int i = path.size()-1, j = path.size()-1; i >= 0 ; i--,j--){
           if(path[i] == '.'){
               path[j] = ' ';
           }else{
               path[j] = path[i];
           }
       }
       return path;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

