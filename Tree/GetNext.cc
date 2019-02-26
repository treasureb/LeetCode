#include"Tree.h"


/* 解题思路: */
/*     1. 如果右子树存在，则为左子树中的最左节点 */
/*     2. 如果父节点存在，则找第一个为父节点左子树的节点 */

class Solution{
public:
    TreeNode* GetNext(TreeNode* pRoot){
        if(pRoot == nullptr)
            return nullptr;

        //右节点存在,则下个节点就是右节点的最左节点
        TreeNode* next = nullptr;
        if(pRoot->right){
            pRoot = pRoot->right;
            while(pRoot->left)
                pRoot = pRoot->left;

            next = pRoot;
        }else if(pRoot->parent != nullptr){
            TreeNode* cur = pRoot;
            TreeNode* parent = cur->parent;
            while(parent != nullptr && cur == parent->right){
                parent = cur;
                parent = parent->parent;
            }
            next = parent;
        }

        return next;
    }
};
