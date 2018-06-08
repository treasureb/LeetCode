#include<iostream>
#include"List.h"
using namespace std;

class Solution{
public:
    /*
     * 将链表划分为左右两半，然后重新交叉组装
     * 时间复杂度O(N)
     * 空间复杂度O(1)
     */

    void relocate_list(Node* head){
        if(head == nullptr)
            return;

        Node* cur = head;
        int len = 0;
        while(cur){
            len++;
            cur = cur->_next;
        }

        cur = head;
        Node* mid_node = nullptr;
        for(int i = 0;i < len/2;i++){
            cur = cur->_next;
        }

        mid_node = cur;

        cur = head;
        for(int i = 0;i < len/2;i++){
            
        }
    }
};
