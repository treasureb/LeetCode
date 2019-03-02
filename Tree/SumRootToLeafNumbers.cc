#include "Tree.h"

class Solution{
public:
    int sum_numbers(TreeNode* root){
        return helper(root,0);
    }

private:
    int helper(TreeNode* root,int sum){
        if(root == nullptr)
            return 0;

        if(root->left == nullptr && root->right == nullptr)
            return sum * 10 + root->val;

        return helper(root->left,sum*10+root->val) + helper(root->right,sum*10+root->val);
    }
};
