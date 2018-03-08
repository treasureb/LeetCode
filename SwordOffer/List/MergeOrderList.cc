#include "list.h"
#include<iostream>

Node* MergeList(Node** l1,Node** l2)
{
    Node* p1 = nullptr;
    Node* p2 = nullptr;
    Node* Head = nullptr;

    if(l1->_value > l2->_v
