#include "mai.h"
#include <climits>
#include <cstdlib>
#include <memory>
#include <openssl/bn.h>
#include <queue>
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


class Solution0 {
private:
    vector<int> tree;
public:
    int getMinimumDifference (TreeNode* root) {
        queue<TreeNode*> que;
        set<int> s;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            auto tmp = que.front();
            que.pop();
            if(tmp -> left) que.push(tmp->left);
            if(tmp -> right) que.push(tmp->right);
            s.insert(tmp->val);
        }
        int abs = *s.end();
        auto beg = s.begin(),end = s.end();
        for(auto after = ++s.begin();after != end; beg++,after++){
           int  val = (*after - *beg) ;
            if(val < abs){
                abs = val;
            }
        }
        return abs;
    }
};

class Solution {
private:
    vector<int> tree;
public:
    //中序遍历，得到有序数组
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        traversal(root->left);
        tree.push_back(root->val);
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        size_t size = tree.size();
        int result = INT_MAX;
        for(int i = 0; i < size-1; ++i){
            result = min(result,tree[i+1]-tree[i]);
        }
        return result;
    }
};
