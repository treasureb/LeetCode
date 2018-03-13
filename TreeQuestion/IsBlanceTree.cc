#include"Tree.h"

int TreeDepth(BinaryTreeNode* Root)
{
    if(Root == nullptr){
        return 0;
    }

    int left = TreeDepth(Root->_left);
    int right = TreeDepth(Root->_right);

    return left > right?(left+1):(right+1);
}

//从上到下判断，节点被重复计算多次
bool IsBlanceTreeC(BinaryTreeNode* Root)
{
    if(Root == nullptr)
        return true;

    int left = TreeDepth(Root->_left);
    int right = TreeDepth(Root->_right);
    if(abs(left-right) > 1){
        return false;
    }

    return IsBlanceTreeC(Root->_left) && IsBlanceTreeC(Root->_right);
}

bool _IsBlanceTree(BinaryTreeNode* Root,int* depth)
{
    if(Root == nullptr){
        depth = 0;
        return true;
    }
    
    int left,right;
    if(_IsBlanceTree(Root->_left,&left) && _IsBlanceTree(Root->_right,&right)){
        if(abs(left-right) < 2){
            *depth = left > right?(left+1):(right+1);
            return true;
        } 
    }

    return false;
}

bool IsBlanceTree(BinaryTreeNode* Root)
{
    int depth = 0;
    return _IsBlanceTree(Root,&depth);
}



