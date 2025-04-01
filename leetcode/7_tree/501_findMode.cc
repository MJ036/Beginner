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

//递归法-需要额外空间
class Solution {
    void traversal(TreeNode* root,map<int,int>& map_arry){
        if(root == nullptr){
            return;
        }
        map_arry[root->val]++;
        traversal(root->left,map_arry);
        traversal(root->right,map_arry);
    }

    //static的作用是消除this指针
    static bool compare(pair<int,int> lhs, pair<int,int> rhs){
        return lhs.second > rhs.second;
    }

public:
    vector<int> findMode(TreeNode* root) {
        //存储树的所有节点
        map<int,int> map_arry;
        //存储符合结果的众数
        vector<int> result;

        traversal(root,map_arry);
        //用于排序的vector
        vector<pair<int,int>> vec(map_arry.begin(),map_arry.end());
        sort(vec.begin(),vec.end(),compare);

        result.push_back(vec[0].first);
        for(int i = 1; i < vec.size(); i++){
            if(vec[i].second == vec[0].second){
                result.push_back(vec[i].first);
            }
        }
        return result;
    }
};

//递归法-不需要额外空间
class Solution_noExtraSpace {
private:
    size_t count;
    size_t maxCount;
    TreeNode* pre;
    vector<int> result;
    //中序遍历，如果是二叉搜索树可以保证有序
    void traversal(TreeNode *root){
        if(root == nullptr){
            return;
        }
        traversal(root->left);
        //处理逻辑：如果root和pre相等，则count++；否则设为1
        if(pre == nullptr){
            count = 1;
        }else if(pre->val == root->val){
            count++;
        }else{
            count = 1;
        }
        //更新pre
        pre = root;

        //count改变后，根据count和maxCount，更新result
        if(count == maxCount){
            result.push_back(root->val);
        }
        if(count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(root->val);
        }

        traversal(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        result.clear();
        pre = nullptr;
        traversal(root);
        return result;
    }
};
