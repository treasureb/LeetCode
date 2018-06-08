#include<iostream>
#include"List.h"

class Solution
{
public:
    Node* reverse_list(Node* head)
    {
        if(head == nullptr)
            return nullptr;

        Node* new_head = nullptr;
        Node* cur = head;
        Node* pre = nullptr;

        while(cur){
            Node* next = cur->_next;
            if(cur->_next == nullptr)
                new_head = cur;

            cur->_next = pre;
            pre = cur;
            cur = next;
        }

        return new_head;
    }
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->_next = node2;
    node2->_next = node3;
    node3->_next = node4;
    Solution s;
    Node* result = s.reverse_list(node1);
    while(result){
        cout<<result->_data<<"->";
        result = result->_next;
    }

    return 0;
}
