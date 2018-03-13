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


 bool _IsSymmetrical(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
    if(Root1 == nullptr && Root2 == nullptr)
        return true;

    if(Root1 == nullptr || Root2 == nullptr)
        return false;

    if(Root1->_value != Root2->_value)
        return false;

    return _IsSymmetrical(Root1->_left,Root2->_right) && _IsSymmetrical(Root1->_right,Root2->_left);
}

bool IsSymmetrical(BinaryTreeNode* Root)
{
    return _IsSymmetrical(Root,Root);    
}

