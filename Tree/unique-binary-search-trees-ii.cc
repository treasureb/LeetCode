#include"Tree.h"

class Solution{
public:
    vector<TreeNode*> generateTrees(int n ){
        if(n == 0)
            return vector<TreeNode*>();
        return generateTree(1,n);
    }

private:
    vector<TreeNode*> generateTree(int from,int to){
        vector<TreeNode*> res;
        if(from > to)
            res.push_back(nullptr);
        else if(from == to)
            res.push_back(new TreeNode(from));
        else{
            //以i位根节点
            for(int i = from;i <= to;++i){
                vector<TreeNode*> left_subtree = generateTree(from,i-1);
                vector<TreeNode*> right_subtree = generateTree(i+1,to);
                
                //实现左右子树的组合
                for(size_t j = 0;j < left_subtree.size();++j){
                    for(size_t k = 0;k < right_subtree.size();++k){
                        TreeNode* root = new TreeNode(i);
                        root->left = left_subtree[j];
                        root->right = right_subtree[k];
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};
