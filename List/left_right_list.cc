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

        Node* mid_node = head;
        for(int i = 0;i < len/2;i++){
            mid_node = mid_node->_next;
        }

        Node* pre = head;
        Node* after = mid_node;
        while(pre->_next != mid_node){
            Node* pre_next = pre->_next;
            Node* after_next = after->_next;

            pre->_next = after;
            after->_next = pre_next;
            pre = pre_next;
            after = after_next;
        }            
        pre->_next = after;
    }
};

void printf_list(Node* head){
    if(head == nullptr)
        return;

    while(head){
        cout<<head->_data<<"->";
        head = head->_next;
    }
}
int main(){
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->_next = node2;
    node2->_next = node3;
    node3->_next = node4;

    printf_list(node1);
    Solution s;
    s.relocate_list(node1);
    printf_list(node1);
    
    return 0;
}
