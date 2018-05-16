#include"Tree.h"

int TreeDepth(Node* Root)
{
    if(Root == nullptr){
        return 0;
    }

    int left = TreeDepth(Root->_left);
    int right = TreeDepth(Root->_right);

    return left > right?(left+1):(right+1);
}

//从上到下判断，节点被重复计算多次
bool IsBlanceTreeC(Node* Root)
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

bool _IsBlanceTree(Node* Root,int* depth)
{
    if(Root == nullptr){
        depth = 0;
        return true;
    }
    
    int left,right;
    //判断当前节点前先去分别判断它的左右子树是否为平衡树结构
    if(_IsBlanceTree(Root->_left,&left) && _IsBlanceTree(Root->_right,&right)){
        if(abs(left-right) < 2){
            *depth = left > right?(left+1):(right+1);
            return true;
        } 
    }

    return false;
}

bool IsBlanceTree(Node* Root)
{
    int depth = 0;
    return _IsBlanceTree(Root,&depth);
}



