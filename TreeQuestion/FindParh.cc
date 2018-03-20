#include<iostream>
#include<vector>

#include"Tree.h"

void FindPath(Node* Head,int expectedSum,vector<int>& path,int currentSum)
{
    currentSum += Head->_value;
    path.push_back(Head->_value);

    //如果是叶子节点，并且路径上节点之和等于输入的值，则打印路径
    
    bool IsLeaf = Head->_left == nullptr && Head->_right == nullptr;
    if(currentSum == expectedSum && IsLeaf){
        cout<<"The Path is Foud:";
        vector<int>::iterator it = path.begin();
        while(it != path.end()){
            cout<<*it<<" ";
            ++it;
        }
        cout<<endl;
    }

    //走到这里说明不是叶子节点，则遍历子节点
    if(Head->_left != nullptr)
        FindPath(Head->_left,expectedSum,path,currentSum);
    if(Head->_right != nullptr)
        FindPath(Head->_right,expectedSum,path,currentSum);

    //在返回父节点之前，删除当前节点的路径
    path.pop_back();
}


void FindPath(Node* Head,int expectedSum)
{
    if(nullptr == Head)
        return;

    vector<int> path;
    int currentSum = 0;
    FindPath(Head,expectedSum,path,currentSum);
}
