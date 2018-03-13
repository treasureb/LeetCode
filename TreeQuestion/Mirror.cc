#include"Tree.h"

void MirrorTree(BinaryTreeNode* Root)
{
    if(Root == nullptr)
        return;

    if(Root->_left == nullptr && Root->_right == nullptr)
        return ;

    //走到这里就可以进行交换了。
    
    BinaryTreeNode* tmp = Root->_left;
    Root->_left = Root->_right;
    Root->_right = tmp;

    if(Root->_left)
        MirrorTree(Root->_left);
    if(Root->_right)
        MirrorTree(Root->_right);
}
