#include"Tree.h"

/*
 *   1、求根的高度，就是求左右子树中较大的+1
 *   2、求其左右子树的高度的方法与求根相同
 */


int TreeDepth(TreeNode* Root)
{
    if(Root == nullptr)
        return 0;

    //分别求其左右子树的高度
    int left = TreeDepth(Root->_left);
    int right = TreeDepth(Root->_right);

    //上层的高度为其左右子树较大的+1
    return left > right?(left+1):(right+1);
}
