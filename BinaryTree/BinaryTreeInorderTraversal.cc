#include"Tree.h"
#include<stack>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == nullptr)
            return res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            TreeNode* top = s.top();
            s.pop();
            res.push_back(top->value);
            root = top->right;
        }
        return res;
    }
};
