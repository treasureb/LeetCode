#include"List.h"

class Solution{
public:
    Node* rotate_right(Node* head,int k){
        if(head == nullptr)
            return nullptr;

        int len = 0;
        Node* cur = head;
        while(cur){
            ++len;
            cur = cur->_next;
        }

        k %= len;
        Node* fast = head;
        Node* slow = head;
        for(int i = 0;i < k;++i){
           if(fast)
               fast = fast->_next;
        }

        if(fast == nullptr)
            return head;
        while(fast->_next){
            fast = fast->_next;
            slow = slow->_next;
        }
        fast->_next = head;
        
        //相当于新链表的头节点
        fast = slow->_next;
        slow->_next = nullptr;

        return fast;
    }            
};
