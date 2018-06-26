#include"Tree.h"


class Solution{
public:
    /*
     * 根据中序遍历和后序遍历的结果构造二叉树
     * 1.根节点是后续的最后一个节点
     * 2.划分左右区间
     * 3.递归求解
     *
     */
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
        TreeNode* root = new TreeNode(0);
        vector<int> left_order;
        vector<int> right_order;

        if(inorder.empty() || postorder.empty())
            return nullptr;

        int root_val = postorder.back();
        postorder.pop_back();
        root->value = root_val;

        size_t i = 0;
        for(;inorder[i] != root_val;++i){
            left_order.push_back(inorder[i]);
        }
        for(i++;i < inorder.size();++i){
            right_order.push_back(inorder[i]);
        }

        root->right = buildTree(right_order,postorder);
        root->right = buildTree(left_order,postorder);

        return root;
    }
};
