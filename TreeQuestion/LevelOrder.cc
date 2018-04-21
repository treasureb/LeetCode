#include<iostream>
#include<vector>
#include<queue>

#include"Tree.h"
using namespace std;

void LevelOrder(Node* Head)
{
    if(nullptr == Head)
        return;

    queue<Node*> s;
    s.push(Head);
    while(!s.empty()){
        Node* Front = s.front();
        s.pop();
        cout<<Front->_value<<" ";

        if(Front->_left)
            s.push(Front->_left);
        if(Front->_right)
            s.push(Front->_right);
    }
}


class Solution
{
public:
    vector<int> level_order(Node* root)
    {
        vector<int> res;
        queue<Node*> q;
        if(root == nullptr)
            return res;

        q.push(root);
        res.push_back(root->_value);
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->_left != nullptr){
                q.push(front->_left);
                res.push_back(front->_left->_value);
            }
            if(front->_right != nullptr){
                q.push(front->_right);
                res.push_back(front->_right->_value);
            }
        }
        return res;
    }
    
};
