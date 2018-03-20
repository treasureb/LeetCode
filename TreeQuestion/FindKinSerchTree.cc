#include<iostream>

#include"Tree.h"

Node* KthNodeCore(Node* Root,size_t k)
{
    Node* target = nullptr;
    if(Root->_left != nullptr)
        target = KthNodeCore(Root->_left,k);


    if(target == nullptr){
        if(k == 1)
            target = Root;

        k--;
    }

    if(target == nullptr && Root->_right != nullptr)
        target = KthNodeCore(Root->_right,k);

    return target;
}


Node* KthNode(Node* Root,size_t k)
{
    if(nullptr == Root || k == 0)
        return nullptr;

    return KthNodeCore(Root,k);
}
