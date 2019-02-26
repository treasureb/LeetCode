#include<iostream>
#include<vector>
#include<queue>

#include"Tree.h"
using namespace std;

void LevelOrder(TreeNode* Head)
{
    if(nullptr == Head)
        return;

    queue<TreeNode*> s;
    s.push(Head);
    while(!s.empty()){
        TreeNode* Front = s.front();
        s.pop();
        cout<<Front->val<<" ";

        if(Front->left)
            s.push(Front->left);
        if(Front->right)
            s.push(Front->right);
    }
}


class Solution
{
public:
    //只是按序打印出来，并没有按照每层个数分开
    vector<int> level_order(TreeNode* root)
    {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == nullptr)
            return res;

        q.push(root);
        res.push_back(root->val);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->left != nullptr){
                q.push(front->left);
                res.push_back(front->left->val);
            }
            if(front->right != nullptr){
                q.push(front->right);
                res.push_back(front->right->val);
            }
        }
        return res;
    }
    
    /* 解题思路: */
    /*     1. 采用队列来带入左右子树，从而按序输入 */
    /*     2. 在队列中插入nullptr来处理按行输出 */

    vector<vector<int>> Level_Order(TreeNode* root){
        vector<vector<int>> res;
        if(nullptr == root)
            return res;

        queue<TreeNode*> q;
        vector<int> cur;
        q.push(root);
        q.push(nullptr);    //根节点独自一行，用nullptr标志每一行的结束
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(nullptr == f){   //如果遇到nullptr说明一行结束了。
                res.push_back(cur);
                cur.resize(0);
                if(q.size() > 0){
                    q.push(nullptr);    //标志换行
                }
            }else{
                cur.push_back(f->val);
                if(f->left){
                    q.push(f->left);
                }

                if(f->right){
                    q.push(f->right);
                }
            }
        }

        return res;
    }
    
};
