#include"Tree.h"


/*
 *  采用递归的思想
 *
 */

class Solution
{
    bool is_sub_tree(TreeNode* root1,TreeNode* root2)
    {
        if(root2 == nullptr)
            return true;
        if(root1 == nullptr)
            return false;

        if(root1->val == root2->val){
            return is_sub_tree(root1->left,root2->left) && 
            is_sub_tree(root1->right,root2->right);
        }else{
            return false;
        }
    }
public:
    bool HasSubTree(TreeNode* root1,TreeNode* root2)
    {
        if(nullptr == root1 || nullptr == root2)
            return false;

        return is_sub_tree(root1,root2)||
            HasSubTree(root1->left,root2) || 
            HasSubTree(root1->right,root2);
    }
};
