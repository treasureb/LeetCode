#include"List.h"

class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head,int n){
        if(!head->_next)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        for(int i = 0;i < n;++i){
            if(fast)
                fast = fast->_next;
        }
        if(fast ==nullptr)
            return head->_next;

        while(fast && fast->_next){
            fast = fast->_next;
            slow = slow->_next;
        }

        ListNode* del = slow->_next;
        slow->_next = del->_next;
        return head;
    }

};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->_next = node2;
    node2->_next = node3;
    node3->_next = node4;
    node4->_next = node5;

    Print(node1);
    Solution s;
    s.removeNthFromEnd(node1,2);
    Print(node1);

    return 0;
}
