#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

#include"Tree.h"


/* 解题思路: */
/*     1. 设立标志位来判断奇偶行 */
/*     2. 每次取队列的大小就是该行的节点个数 */

class Solution{
public:
    vector<vector<int>> Print(TreeNode* pRoot){
        vector<vector<int>> res;
        if(nullptr == pRoot)
            return res;

        queue<TreeNode*> q;
        q.push(pRoot);
        bool even = false;
        while(!q.empty()){
            vector<int> v;
            int level_number = q.size();
            int i = 0;
            while(i < level_number){
                TreeNode* f = q.front();
                q.pop();
                v.push_back(f->val);
                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);

                ++i;
            }
            //如果是偶数就逆置
            if(even)
                reverse(v.begin(),v.end());

            res.push_back(v);
            even  = !even;
        }
        return res;
    }
};
