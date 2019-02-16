#include "List.h"

ListNode* remove_node(ListNode* head,int n){
    if(nullptr == head->next)
        return nullptr;

    ListNode* pre = head,*cur = head;
    while(n--)
        cur = cur->next;

    if(nullptr == cur)
        return head->next;

    while(cur->next){
        cur = cur->next;
        pre = pre->next;
    }

    pre->next = pre->next->next;

    return head;
}
