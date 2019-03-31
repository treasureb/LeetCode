#ifndef _TREE_
#define _TREE_

#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

struct TreeNode{
    TreeNode(int value)
     :left(nullptr)
     ,right(nullptr)
     ,parent(nullptr)
      ,val(value)
    {}
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    int val;
};

#endif
