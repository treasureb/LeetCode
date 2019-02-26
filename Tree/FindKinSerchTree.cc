#include<iostream>

#include"Tree.h"


/* 解题思路: */
/*     1. 采用递归思想，先找到其最左节点 */
/*     2. 然后判断是否为所找节点，否则依次-1 */
/*     3. 如果当前节点不是所找节点且其右子树存在，则递归其右子树 */

TreeNode* KthTreeNodeCore(TreeNode* Root,size_t k)
{
    TreeNode* target = nullptr;
    if(Root->left != nullptr)
        target = KthTreeNodeCore(Root->left,k);


    if(target == nullptr){
        if(k == 1)
            target = Root;

        k--;
    }

    if(target == nullptr && Root->right != nullptr)
        target = KthTreeNodeCore(Root->right,k);

    return target;
}


TreeNode* KthTreeNode(TreeNode* Root,size_t k)
{
    if(nullptr == Root || k == 0)
        return nullptr;

    return KthTreeNodeCore(Root,k);
}
