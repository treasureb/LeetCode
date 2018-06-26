#include"Tree.h"
#include<iostream>
#include<algorithm>

class Solution{
public:
    /*
     * 求二叉树的最短高度
     */
    int minDepth(TreeNode* root){
        if(!root)
            return 0;

        if(!root->left)
            return 1 + minDepth(root->right);
        if(!root->right)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
};
