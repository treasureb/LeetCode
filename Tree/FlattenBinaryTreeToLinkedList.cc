#include "Tree.h"

/* 解题思路: */
/*     1.利用递归找到最左节点 */
/*     2.将当前节点的左子树链接到右子树位置 */
/*     3.将原本的右子树链接在之前左子树的最右子树上 */

class Solution{
public:
    void flatten(TreeNode* root){
        if(root == nullptr)
            return;

        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right)
            root = root->right;

        root->right = tmp;
    }
                 
};
