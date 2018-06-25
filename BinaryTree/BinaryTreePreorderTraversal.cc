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
    vector<int> preorderTraversal1(TreeNode* root){
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


    vector<int> preorderTraversal2(TreeNode* root){
        vector<int> res;
        if(root == nullptr)
            return res;

        stack<TreeNode*> s;
        while(root || !s.empty()){
            //沿途保存左子树
            while(root){
                res.push_back(root->value);
                s.push(root);
                root = root->left;
            }
            //走到最左节点，看是否存在右子树
            TreeNode* top = s.top();
            s.pop();
            root = top->right;
        }
        return res;
    }

    /* 递归求二叉树的前序遍历
     *
     */
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
