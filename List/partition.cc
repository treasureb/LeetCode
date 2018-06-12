#include"List.h"

class Solution{
public:
    ListNode* partition(ListNode* head,int x){
        if(head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->_next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast != nullptr && fast->_next != nullptr){
            if(fast->_next->_data >= x)
                fast = fast->_next;
            else{
                if(fast == slow){
                    fast = fast->_next;
                    slow = slow->_next;
                }else{
                    ListNode* tmp = fast->_next;
                    fast->_next = tmp->_next;
                    tmp->_next = slow->_next;
                    slow->_next = tmp;
                    slow = slow->_next;
                }
            }
        }
        return dummy->_next;
    }
};
