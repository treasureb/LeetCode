#include<iostream>
#include<queue>
#include<vector>

#include"Tree.h"


/*
 *  分行从上到下打印一棵树
 *  
 *  需要记录两个值
 *  1. 当前需要打印的个数
 *  2. 下一行需要打印的个数
 */
void branchPrint(Node* Head)
{
    if(nullptr == Head)
        return;

    queue<Node*> q;
    int nextLevel = 0;
    int toBePrint = 1;
    while(!q.empty()){
        Node* front = q.front();
        cout<<front->_value<<" ";
        q.pop();

        if(front->_left){
            q.push(front->_left);
            nextLevel++;
        }
        if(front->_right){
            q.push(front->_right);
            nextLevel++;
        }

        --toBePrint;

        //如果当前行打印结束
        if(toBePrint == 0){
            cout<<endl;
            //更新当前行和下一行
            toBePrint = nextLevel;
            nextLevel = 0;
        }
    }
}

class Solution{
public:
    vector<vector<int>> Print(Node* pRoot){
        vector<vector<int>> res;
        if(pRoot == nullptr)
            return res;

        queue<Node*> q;
        q.push(pRoot);
        while(!q.empty()){
            int i = 0;
            int level_number = q.size();
            vector<int> v;
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
            res.push_back(v);
        }
        return res;
    }
};
