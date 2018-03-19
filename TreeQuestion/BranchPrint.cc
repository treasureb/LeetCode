#include<iostream>
#include<queue>

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

