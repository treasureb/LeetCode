#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>

#include"Tree.h"

void ZhiPrint(Node* Head)
{
    if(nullptr == Head)
        return;

    stack<Node*> levels[2];
    //标志奇数行和偶数行
    int current = 0;
    int next = 1;
    
    levels[current].push(Head);
    while(!levels[current].empty() && !levels[next].empty()){
        Node* top = levels[current].top();
        levels[current].pop();

        cout<<top->_value<<" ";
        
        //偶数行，先入左子树
        if(current == 0){
            if(top->_left)
                levels[next].push(top->_left);
            if(top->_right)
                levels[next].push(top->_right);
        }else{//奇数行，先入右子树
            if(top->_right)
                levels[next].push(top->_right);
            if(top->_left)
                levels[next].push(top->_left);
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
    vector<vector<int>> Print(Node* pRoot){
        vector<vector<int>> res;
        if(nullptr == pRoot)
            return res;

        queue<Node*> q;
        q.push(pRoot);
        bool even = false;
        while(!q.empty()){
            vector<int> v;
            int level_number = q.size();
            int i = 0;
            while(i < level_number){
                Node* f = q.front();
                q.pop();
                v.push_back(f->_value);
                if(f->_left)
                    q.push(f->_left);
                if(f->_right)
                    q.push(f->_right);

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