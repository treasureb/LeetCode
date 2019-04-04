#include"Tree.h"

/*
 *   1、求根的高度，就是求左右子树中较大的+1
 *   2、求其左右子树的高度的方法与求根相同
 */


/* 求二叉树中的最大深度 */
int TreeDepth(TreeNode* Root)
{
    if(Root == nullptr)
        return 0;

    //分别求其左右子树的高度
    int left = TreeDepth(Root->left);
    int right = TreeDepth(Root->right);

    //上层的高度为其左右子树较大的+1
    return left > right?(left+1):(right+1);
}

/* 求二叉树中的最小深度 */
int TreeMinDeoth(TreeNode* root){
    if(root == nullptr)
        return 0;

    if(root->left && root->right)
        return 1;

    return min(TreeMinDeoth(root->left),TreeMinDeoth(root->right)) + 1;
}
