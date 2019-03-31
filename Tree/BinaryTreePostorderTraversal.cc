#include"Tree.h"
#include<stack>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == nullptr)
            return res;

        stack<TreeNode*> s;
        s.push(root);
        TreeNode* cur = nullptr;
        while(!s.empty()){
            cur = s.top();
            if(cur->left == nullptr && cur->right == nullptr){
                res.push_back(cur->value);
                s.pop();
            }else{
                if(cur->right){
                    s.push(cur->right);
                    cur->right = nullptr;
                }
                if(cur->left){
                    s.push(cur->left);
                    cur->left = nullptr;
                }
            }
        }
        return res;
    }
};
