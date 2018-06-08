#ifndef _TREE_
#define _TREE_

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node{
    Node(int value)
     :_left(nullptr)
     ,_right(nullptr)
     ,_parent(nullptr)
      ,_value(value)
    {}
    Node* _left;
    Node* _right;
    Node* _parent;
    int _value;
};

#endif
