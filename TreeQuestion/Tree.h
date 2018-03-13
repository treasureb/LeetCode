#ifndef _TREE_
#define _TREE_

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

typedef struct BinaryTreeNode{
    BinaryTreeNode* _left;
    BinaryTreeNode* _right;
    BinaryTreeNode* _parent;
    int _value;
}Node;

#endif
