#include"Tree.h"
#include<vector>
#include<stack>

vector<int> post_order(TreeNode* root){
    vector<int> res;
    if(root)
        return res;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* tmp = s.top();
        s.pop();
        res.push_back(tmp->val);
        if(tmp->left)
            s.push(tmp->left);
        if(tmp->right)
            s.push(tmp->right);
    }
    reverse(res.begin(),res.end());
    return res;
}
