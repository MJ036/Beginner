#include "mai.h"

using namespace std;
using ElemType = int;

typedef struct BiTNode{
    ElemType data;
    BiTNode *lchild;
    BiTNode *rchild;
}TreeNode;

typedef struct{
    TreeNode* root;
}BST;

BST* bst_create();
bool bst_insert(BST* tree,ElemType val);
void bst_delete(BST* tree,ElemType val);
void bst_destory(BST* tree);

void preOrder(TreeNode* node){
    if(!node){
        return;
    }
    cout << node->data << " ";
    if(node->lchild){
        preOrder(node->lchild);
    }
    if(node->rchild){
        preOrder(node->rchild);
    }
}
void inOrder(TreeNode* node){
    if(!node){
        return;
    }
    if(node->lchild){
        inOrder(node->lchild);
    }
    cout << node->data << " ";
    if(node->rchild){
        inOrder(node->rchild);
    }
}
void postOrder(TreeNode* node){
    if(!node){
        return;
    }
    if(node->lchild){
        postOrder(node->lchild);
    }
    if(node->rchild){
        postOrder(node->rchild);
    }
    cout << node->data << " ";
}

void levelOrder(TreeNode* node){
    queue<TreeNode*> que;
    que.push(node);
    while(!que.empty()){
        TreeNode* cur = que.front();
        que.pop();
        cout << cur->data << " ";
        if(cur->lchild){
            que.push(cur->lchild);
        }
        if(cur->rchild){
            que.push(cur->rchild);
        }
    }
}

BST* bst_create(){
    BST* tree =(BST*)calloc(1,sizeof(BST));
    return tree;

}
bool bst_insert(BST* tree,ElemType val){
    TreeNode* p = NULL;
    TreeNode* cur = tree->root;

    TreeNode* node =(TreeNode*)calloc(1,sizeof(TreeNode));
    node->data = val;
    
    if(cur == NULL){
        tree->root = node;
        return true;
    }

    int cmp;
    while(cur){
        cmp = val -  cur->data;
        if(cmp > 0){
            p = cur;
            cur = cur-> rchild;
        }else if(cmp < 0){
            p = cur;
            cur = cur->lchild;
        }else{
            return false;
        }
    }//cur = NULL
    if(cmp > 0){
        p->rchild = node;
    }else{
        p->lchild = node;
    }
    return true;
}
void bst_delete(BST* tree,ElemType val){
    TreeNode* parent = NULL;
    TreeNode* cur = tree->root;
    //find target
    int cmp;
    while(cur){
        cmp = val -  cur->data;
        if(cmp > 0){
            parent = cur;
            cur = cur-> rchild;
        }else if(cmp < 0){
            parent = cur;
            cur = cur->lchild;
        }else{
            break;
        }
    }//cur = NULL or cur->val = val;

     //find min from rchild
    if(cur != NULL){
        //if target has two childs ,process
        if(cur->lchild && cur->rchild){
            TreeNode* p = NULL;
            TreeNode* min = cur->rchild;
            while(min->lchild){
                p = min;
                min = min->lchild;
            }//min->lchild == NULL
            cur->data = min->data;
            parent = p;
            cur = min;
        }//cur has 0 or 1 child

        TreeNode* child = (cur->lchild) ? cur->lchild : cur->rchild;
        if(parent == NULL){
            tree->root = child;
            free(cur);
            return;
        }
        cmp = cur->data - parent->data;
        if(cmp > 0){
            parent->rchild = child;
            free(cur);
        }else if(cmp  < 0){
            parent->lchild = child;
            free(cur);
        }else{
            parent->rchild = child;
            free(cur);
        }
    }

}
void destory(TreeNode* node){
    if(node == NULL){
        return;
    }
    if(node->lchild){
        destory(node->lchild);
    }
    if(node->rchild){
        destory(node->rchild);
    }
    free(node);
}
void bst_destory(BST* tree){
    destory(tree->root);
    free(tree);
}

int  main(){
    BST* bst = bst_create();
    bst_insert(bst,9);
    bst_insert(bst,5);
    bst_insert(bst,42);
    bst_insert(bst,3);
    bst_insert(bst,13);
    bst_insert(bst,57);

    bst_delete(bst,5);
    bst_delete(bst,9);
    bst_delete(bst,3);

    preOrder(bst->root);
    cout << endl;
    inOrder(bst->root);
    cout << endl;
    postOrder(bst->root);
    cout << endl;
    levelOrder(bst->root);
    cout << endl;

    bst_destory(bst);
    return 0;
}





