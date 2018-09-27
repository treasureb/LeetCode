#include"List.h"

class Solution{
public:
    ListNode* insert_sort(ListNode* node){
        if(node == nullptr || node->next == nullptr)
            return node;

        ListNode* dummy = new ListNode(-1);     //虚拟的头节点
        ListNode*  cur = node;
        ListNode* pre = dummy;
        while(cur){
            ListNode* next = cur->next;
            pre = dummy;
            while(pre->next && pre->next->val < cur->val){
                pre = pre->next;
            }

            //找到待插入的位置
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};
