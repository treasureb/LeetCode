#include<iostream>
#include<vector>

#include"Tree.h"

/*
 *  1. 为什么不用stack，而使用vector？
 *
 *  因为打印路径时，需要得到路径上的所有值，
 *  而stack只能得到栈顶，故不是最好的选择
 */

void FindPath(TreeNode* Head,int expectedSum,vector<int>& path,int currentSum)
{
    currentSum += Head->val;
    path.push_back(Head->val);

    //如果是叶子节点，并且路径上节点之和等于输入的值，则打印路径
    
    bool IsLeaf = Head->left == nullptr && Head->right == nullptr;
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
    if(Head->left != nullptr)
        FindPath(Head->left,expectedSum,path,currentSum);
    if(Head->right != nullptr)
        FindPath(Head->right,expectedSum,path,currentSum);

    //在返回父节点之前，删除当前节点的路径
    path.pop_back();
}


void FindPath(TreeNode* Head,int expectedSum)
{
    if(nullptr == Head)
        return;

    vector<int> path;
    int currentSum = 0;
    FindPath(Head,expectedSum,path,currentSum);
}



/* 采用DFS解题 */
class Solution{
    void dfs(TreeNode* root,int sum,vector<vector<int>>& ret,vector<int>& tmp){
        tmp.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == root->val){
                ret.push_back(tmp);
            }
        }
        if(root->left)
            dfs(root->left,sum-root->val,ret,tmp);
        if(root->right)
           dfs(root->right,sum-root->val,ret,tmp);

        tmp.pop_back();
    }
public:
    vector<vector<int>> FindPath(TreeNode* root,int expectedSum){
        vector<vector<int>> ret;
        vector<int> tmp;
        if(root){
            dfs(root,expectedSum,ret,tmp);
        }
        return ret;
    }
};
