#include "Tree.h"

/* 求解二叉树中的节点个数 */
int NumberOfTreeNode(TreeNode* root){
    if(root == nullptr)
        return 0;

    int left = NumberOfTreeNode(root->left);
    int right = NumberOfTreeNode(root->right);

    return left + right + 1;
}
