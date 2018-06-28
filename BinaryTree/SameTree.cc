#include"Tree.h"

/*
 * 判断两个二叉树是否相等
 * 1.如果都不为空，则判断当前节点的数值和其左右子树
 * 2.如果一个为空，一个不为空直接返回flase
 * 3.否则返回true
 */
class Solution{
public:
    bool isSameTree(TreeNode* p,TreeNode* q){
        if(p != nullptr && q != nullptr)
            return (p->value == q->value) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        else if((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr))
            return false;
        else 
            return true;
    }
};
