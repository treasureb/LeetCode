#include"Tree.h"

class Solution{
public:
    Node* GetNext(Node* pRoot){
        if(pRoot == nullptr)
            return nullptr;

        //右节点存在,则下个节点就是右节点的最左节点
        Node* next = nullptr;
        if(pRoot->_right){
            pRoot = pRoot->_right;
            while(pRoot->_left)
                pRoot = pRoot->_left;

            next = pRoot;
        }else if(pRoot->_parent != nullptr){
            Node* cur = pRoot;
            Node* parent = cur->_parent;
            while(parent != nullptr && cur == parent->_right){
                parent = cur;
                parent = parent->_parent;
            }
            next = parent;
        }

        return next;
    }
};
