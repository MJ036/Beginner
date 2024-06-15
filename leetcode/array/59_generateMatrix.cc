#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        int starx = 0, stary = 0;
        int loop = n / 2;
        int count = 1;
        int offset = 1;
        int i,j;
        while(loop--){
            for(i = starx,j = stary; j < n - offset; j++){
                res[i][j] = count++;
            }
            for(;i < n - offset ; i++){
                res[i][j] = count++;
            }
            for(;j > stary ; j--){
                res[i][j] = count++;
            }
            for(;i > starx ; i--){
                res[i][j] = count++;
            }
            starx++;
            stary++;
            offset += 1;
        }
        if(n%2 == 1){
            res[starx][stary] = count;
        }
        return res;
    }

};

int main()
{
    
}

