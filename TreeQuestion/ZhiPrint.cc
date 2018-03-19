#include<iostream>
#include<stack>

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
