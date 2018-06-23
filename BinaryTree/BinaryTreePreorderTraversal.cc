#include"Tree.h"
#include<vector>
#include<stack>

class Solution{
public:
    /* 非递归前序遍历
     *
     * 1.采用栈来保存沿途的节点
     * 2.先判断右节点是否存在，这样左节点就可以先出栈
     */
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* top = s.top();
            s.pop();
            res.push_back(top->value);
            if(top->right)
                s.push(top->right);
            if(top->left)
                s.push(top->left);
        }
        return res;
    } 

    vector<int> preorderTraversal_R(TreeNode* root){
        vector<int> res;
        preorder_R(root,res);
        return res;
    }
private:
    void preorder_R(TreeNode* root,vector<int>& res){
        if(!root)
            return;

        res.push_back(root->value);
        preorder_R(root->left,res);
        preorder_R(root->right,res);
    }
};
