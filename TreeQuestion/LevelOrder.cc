#include<iostream>
#include<queue>

#include"Tree.h"


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
