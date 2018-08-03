#include<iostream>

#include"../BinaryTree/Tree.h"
#include"List.h"

using namespace std;

class Solution{
public:
    TreeNode* covert(TreeNode* root){
        if(root == nullptr)
            return nullptr;

        TreeNode* pre = nullptr;
        convert_helper(root,pre);
        TreeNode* res = root;
        while(res->left){
            res = res->left;
        }

        return res;
    }    

private:
    void convert_helper(TreeNode* cur,TreeNode*& pre){
        if(cur == nullptr)
            return;

        convert_helper(cur->left,pre);
        cur->left = pre;
        if(pre){
            pre->right = cur;
        }
        pre = cur;
        convert_helper(cur->right,pre);
    }
};
