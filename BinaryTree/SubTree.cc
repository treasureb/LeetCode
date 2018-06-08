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
bool DoesTree1HaveTree2(Node* Root1,Node* Root2)
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
bool HasSubTree(Node* Root1,Node* Root2)
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


/*
 *  采用牛客网大佬的方式实现
 *
 */

class Solution
{
    bool is_sub_tree(Node* root1,Node* root2)
    {
        if(root2 == nullptr)
            return true;
        if(root1 == nullptr)
            return false;

        if(root1->_value == root2->_value){
            return is_sub_tree(root1->_left,root2->_left) && 
            is_sub_tree(root1->_right,root2->_right);
        }else{
            return false;
        }
    }
public:
    bool HasSubTree(Node* root1,Node* root2)
    {
        if(nullptr == root1 || nullptr == root2)
            return false;

        return is_sub_tree(root1,root2)||
            HasSubTree(root1->_left,root2) || 
            HasSubTree(root2->_right,root2);
    }
};
