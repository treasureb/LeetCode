#include<iostream>
#include"Tree.h"
#include<vector>

using namespace std;

class Solution
{
public:
   TreeNode* reconstruct_binarytree(vector<int> pre,vector<int> in)
   {
       int in_size = in.size();
       if(in_size == 0)
           return nullptr;

       vector<int> pre_left,pre_right,in_left,in_right;
       int root = pre[0];//前序的第一个是根节点
       TreeNode* node = new TreeNode(root);
       int p = 0;
       for(;p < in_size;++p){//在中序中找到根节点
           if(in[p] == root)
               break;
       }

       for(int i = 0;i < in_size;++i){//划分子区间
           if(i < p){
               in_left.push_back(in[i]);
               pre_left.push_back(pre[i+1]);
           }else if(i > p){
               in_right.push_back(in[i]);
               pre_right.push_back(pre[i]);
              }
       }

       node->left = reconstruct_binarytree(pre_left,in_left);
       node->left = reconstruct_binarytree(pre_right,in_right);

       return node;
   }
};
int main()
{
    return 0;
}
