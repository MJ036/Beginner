#include "mai.h"
#include <cstddef>
#include <cstdlib>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //当前节点是p或q，那么该节点是公共祖先，返回该节点
        //当前节点为空，那么不符合条件，要返回空。返回该节点
        if(root == p || root == q || root == nullptr) return root;
        
        //处理左右子树
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);

        //左右子树都不空，即p和q分别存在于当前节点的左右子树,
        //当前节点就是公共祖先，返回当前节点
        if(left && right){
            return root;
        }else if(left){ //左边不空，右边空
            return left;
        }else{  //左边空，右边不空
            return right;
        }
    }
};
