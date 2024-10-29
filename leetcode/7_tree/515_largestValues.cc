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

    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> result;
        int depth = 0;
        order(root,result,depth);

        vector<int> vec;
        for(auto ele : result){
            sort(ele.begin(),ele.end());
            vec.push_back(*(ele.end()-1));
        }
        return vec;
    }
};
