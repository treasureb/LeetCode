#ifndef _TREE_
#define _TREE_

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode{
    TreeNode(int value)
     :_left(nullptr)
     ,_right(nullptr)
     ,_parent(nullptr)
      ,_value(value)
    {}
    TreeNode* _left;
    TreeNode* _right;
    TreeNode* _parent;
    int _value;
};

#endif
