#include "mai.h"
#include <string>
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

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> result;
        traversal2(root,path,result);
        return result;
    }

    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result){
        path.push_back(cur->val);
        if(cur->left == nullptr && cur->right == nullptr){
            string spath;
            for(int i = 0; i < path.size() - 1; ++i){
                spath += to_string(path[i]);
                spath += "->";
            }
            //最后一个元素单独添加，因为最后一个元素后面不用添加 箭头符号
            spath += to_string(path[path.size() - 1]); 
            result.push_back(spath);
            return;
        }

        if(cur->left){
            traversal(cur->left,path,result);
            path.pop_back();
        }
        if(cur->right){
            traversal(cur->right,path,result);
            path.pop_back();
        }
    }

    //这里path不用引用，可以做到回溯效果。
    void traversal2(TreeNode* cur, string path, vector<string>& result){
        path += to_string(cur->val);    
        if(cur->left == nullptr && cur->right == nullptr){
            result.push_back(path);
            return;
        }
        if(cur->left) traversal2(cur->left,path + "->",result);
        if(cur->right) traversal2(cur->right,path + "->",result);

    }
};

void test(TreeNode *cur , string path,vector<string>&result){
    path += to_string(cur->val);
    if(cur->left == nullptr && cur->right == nullptr){
        result.push_back(path);
        return;
    }
    if(cur->left) test(cur->left,path + "->",result);
    if(cur->right) test(cur->right,path + "->",result);

}
