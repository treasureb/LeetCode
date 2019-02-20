#include"Tree.h"



/* 解题思路: */
/* 1. 先追溯到叶子节点， */
/* 2. 和0进行比较，如果为负数就不需要加入 */
/* 3. 比较当前节点的左右路径之和 */

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

        res = max(res,left+right+node->val);

        return max(left,right) + node->val;
    }
};
