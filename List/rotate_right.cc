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

        //k的值可能超过链表的长度，所以要取余
        k %= len;
        Node* fast = head;
        Node* slow = head;
        for(int i = 0;i < k;++i){
           if(fast)
               fast = fast->_next;
        }

        //如果快指针等于空，说明链表长度刚好为K
        if(fast == nullptr)
            return head;
        //利用快慢指针找到需要旋转的节点
        while(fast->_next){
            fast = fast->_next;
            slow = slow->_next;
        }
        //将链表尾部链接到头部
        fast->_next = head;
        
        //相当于新链表的头节点
        fast = slow->_next;
        //将原链表处断开
        slow->_next = nullptr;

        return fast;
    }            
};
