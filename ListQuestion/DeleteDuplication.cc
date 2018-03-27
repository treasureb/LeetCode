#include"List.h"

void DeleteDuplication(Node** Head)
{
    if(nullptr == Head || nullptr == *Head)
        return;

    Node* pre = Head;
    Node* cur = Head;
    while(cur){
        Node* next = cur->_next;
        bool needDelete = false;
        if(next != nullptr && next->_data == cur->_data)
            needDelete = true;

        if(needDelete){
            pre = cur;
            cur = cur->_next;
        }else{
            int value = cur->_data;
            Node* ToBeDel = cur;
            while(ToBeDel != nullptr && ToBeDel->_data == value){
                next = ToBeDel->_next;

                delete ToBeDel;
                ToBeDel = nullptr;

                ToBeDel = next;
            }
            if(pre == nullptr)
                *Head = next;
            else
                pre->_next = cur;

            cur = next;
        }
    }
}
