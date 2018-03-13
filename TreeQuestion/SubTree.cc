#include"Tree.h"

/*
 *  题目中在查找与根节点相同的节点上浪费大量时间
 *  
 *  优化:查找时可以采用哈希表
 */



//浮点数存储是一个近似值，故不能直接比较
bool Equal(double num1,double num2)
{
    if((num1 - num2 > -0.00000001) && num1 - num2 < 0.00000001){
        return true;
    }else{
        return false;
    }
}

//递归判断左子树和右子树
bool DoesTree1HaveTree2(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
    if(Root2 == nullptr)
        return true;
    if(Root1 == nullptr)
        return false;

    if(!Equal(Root1->_value,Root2->_value)){
        return false;
    }

    return DoesTree1HaveTree2(Root1->_left,Root2->_left) && DoesTree1HaveTree2(Root1->_right,Root2->_right);
}

// 查找与根节点一样的节点
bool HasSubTree(BinaryTreeNode* Root1,BinaryTreeNode* Root2)
{
    bool result = false;

    if(Root1 != nullptr && Root2 != nullptr){
        if(Equal(Root1->_value,Root2->_value)){
            result = DoesTree1HaveTree2(Root1,Root2); 
        }
        if(!result)
            result = HasSubTree(Root1->_left,Root2);
        if(!result)
            result = HasSubTree(Root1->_left,Root2);
    }
    return result;
}

