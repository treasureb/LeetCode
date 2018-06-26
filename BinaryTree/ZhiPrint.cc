#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

#include"Tree.h"

void ZhiPrint(TreeNode* Head)
{
    if(nullptr == Head)
        return;

    stack<TreeNode*> levels[2];
    //标志奇数行和偶数行
    int current = 0;
    int next = 1;
    
    levels[current].push(Head);
    while(!levels[current].empty() && !levels[next].empty()){
        TreeNode* top = levels[current].top();
        levels[current].pop();

        cout<<top->value<<" ";
        
        //偶数行，先入左子树
        if(current == 0){
            if(top->left)
                levels[next].push(top->left);
            if(top->right)
                levels[next].push(top->right);
        }else{//奇数行，先入右子树
            if(top->right)
                levels[next].push(top->right);
            if(top->left)
                levels[next].push(top->left);
        }

        //当前行打印完，要更新奇数行和偶数行
        if(!levels[current].empty()){
            cout<<endl;
            current = 1-current;
            next = 1- next;
        }
    }
}

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
                v.push_back(f->value);
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
