#include "mai.h"

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//层序遍历的递归方法
class Solution {
public:
    void order(TreeNode* cur, vector<vector<int>> &result, size_t depth){
        if(cur == nullptr) return;
        if(result.size() == depth) result.push_back(vector<int>()); //若第一次访问该层，则创建vector
        result[depth].push_back(cur->val);
        order(cur->left,result,depth+1);
        order(cur->right,result,depth+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> result;
        vector<double> vec;
        int depth = 0;
        order(root,result,depth);
        for(int i = 0; i < result.size(); i++){
            double sum = 0;
            double ave = 0;
            for(int j = 0; j < result[i].size(); j++){
                sum += result[i][j];
            }
            ave = sum/result[i].size();
            vec.push_back(ave);
        }
        return vec;
    }
};
