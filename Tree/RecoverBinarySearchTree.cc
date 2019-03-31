#include"Tree.h"

class Solution{
public:
    /*
     * 1.自己找到交换的两个数字
     * 2.然后将两个数字交换回来
     * 3.构建二叉搜索树
     *
     */

#if 0
    void recoverTree(TreeNode* root){
        first = second = prev = nullptr;

        //中序遍历
        dfs(root);
        //进行交换
        if(first != nullptr && second != nullptr){
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
private:
    void dfs(TreeNode* root){
        //左子树
        if(root->left != nullptr)
            dfs(root->left);
        //如果存在逆序
        if(prev != nullptr && prev->val > root->val){
            if(first == nullptr)
                first = prev;

            if(first != nullptr)
                second = root;
        }
        //当前节点变成"上一个"节点
        prev = root;
        if(root->right != nullptr)
            dfs(root->right);
    }
    
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
#endif

};
