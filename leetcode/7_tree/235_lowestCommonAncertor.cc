#include "mai.h"
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
    TreeNode* traversal(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return root;

        if(root->val > p->val && root->val > q->val){
            return traversal(root->left,p,q);
        }else if(root->val < p->val && root->val < q->val){
            return traversal(root->right,p,q);
        }else{
            return root;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root,p,q);
    }
};
