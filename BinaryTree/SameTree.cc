#include"Tree.h"

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
