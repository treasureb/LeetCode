#include"List.h"

class Solution{
public:
    bool has_cycle(ListNode* head){
        if(head == nullptr)
            return false;

        ListNode* fast = head->_next;
        ListNode* slow = head;

        while(fast && fast->_next){
            if(fast == slow){
                return true;
            }else{
                fast = fast->_next->_next;
                slow = slow->_next;
            }
        }
        return false;
    }
};
