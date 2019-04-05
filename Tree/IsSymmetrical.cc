#include"Tree.h"

/* 特殊：   7
 *         / \
 *        7   7
 *       / \  / \  
 *      7  7 7
 *  
 *   所以判断时应加入nullptr
 *   一个遍历根，左，右
 *   一个遍历根，右，左
 */


 bool _IsSymmetrical(TreeNode* Root1,TreeNode* Root2)
{
    if(Root1 == nullptr && Root2 == nullptr)
        return true;

    if(Root1 == nullptr || Root2 == nullptr)
        return false;

    if(Root1->val != Root2->val)
        return false;

    return _IsSymmetrical(Root1->left,Root2->right) && _IsSymmetrical(Root1->right,Root2->left);
}

bool IsSymmetrical(TreeNode* Root)
{
    return _IsSymmetrical(Root,Root);    
}

