#include "mai.h"
#include <cstdlib>
#include <openssl/bio.h>
using namespace std;

class TreeNode{
public:
    TreeNode():value(string()),count(new int(1)),left(nullptr),right(nullptr){}
    TreeNode(const TreeNode &rhs):value(rhs.value),count(rhs.count),left(rhs.left),right(rhs.right){}
    TreeNode& operator=(const TreeNode &rhs){
        ++*rhs.count;
        if(--*count == 0){
            if(left){
                delete left;
                left = nullptr;
            }
            if(right){
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
            }
        value = rhs.value;
        left = rhs.left;
        right = rhs.right;
        count = rhs.count;
        return *this;
    }
    ~TreeNode(){
        if(--*count == 0){
            if(left){
                delete left;
                left = nullptr;
            }
            if(right){
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
    }
private:
    string value;
    int* count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree{
public:
    BinStrTree():root(new TreeNode()){}
    BinStrTree(BinStrTree& rhs):root(new TreeNode(*rhs.root)){}
    BinStrTree& operator=(const BinStrTree& rhs){
        TreeNode *new_root = new TreeNode(*rhs.root);
        delete root;
        root = new_root;
        return *this;
    }
    private:
        TreeNode *root;
};

int main()
{

    return 0;
}

