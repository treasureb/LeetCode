#include"Tree.h"

class Solution{
public:
    int maxPathSum(TreeNode* root){
        int res = INT_MIN;
        maxPath(root,res);
        return res;
    }

private:
    int maxPath(TreeNode* node,int& res){
        if(!node)
            return 0;
        int left = max(maxPath(node->left,res),0);
        int right = max(maxPath(node->right,res),0);

        res = max(res,left+right+node->value);

        return max(left,right) + node->value;
    }
};
