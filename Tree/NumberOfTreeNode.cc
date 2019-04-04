#include "Tree.h"

/* 求解二叉树中的节点个数 */
int NumberOfTreeNode(TreeNode* root){
    if(root == nullptr)
        return 0;

    int left = NumberOfTreeNode(root->left);
    int right = NumberOfTreeNode(root->right);

    return left + right + 1;
}

/* 求解二叉树中叶子节点的个数 */
int NumberOfTreeLeafNode(TreeNode* root){
    if(root == nullptr)
        return 0;

    if(root->left == nullptr && root->right == nullptr)
        return 1;

    return NumberOfTreeNode(root->left) + NumberOfTreeNode(root->right);
}

/* 求解二叉树中第K层节点的个数 */
int NumberOfTreeKLevelNode(TreeNode* root,int k){
    if(root == nullptr || k < 1)
        return 0;

    if(k == 1)
        return 1;

    int left = NumberOfTreeKLevelNode(root->left,k-1);
    int right = NumberOfTreeKLevelNode(root->right,k-1);

    return left + right;
}

