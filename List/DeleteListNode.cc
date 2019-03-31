#include"List.h"

 void DeleteListNode(Node** Head,Node* ToBeDelete)
{
    if(nullptr == Head || nullptr == ToBeDelete)
        return;

    //如果待删除的节点不是尾节点，则采用替换法删除
    if(ToBeDelete->_next != nullptr){
        Node* Next = ToBeDelete->_next;
        ToBeDelete->_data = Next->_data;
        ToBeDelete->_next = Next->_next;

        delete Next;
        Next = nullptr;
    }else if(*Head == ToBeDelete){//要删除的是头节点
        delete ToBeDelete;
        ToBeDelete = nullptr;
        *Head = nullptr;
    }else{//待删除的节点是尾节点
        Node* cur = *Head;
        while(cur->_next != ToBeDelete){
            cur = cur->_next;
        }

        cur->_next = nullptr;
        delete ToBeDelete;
        ToBeDelete = nullptr;
    }

}
