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
            Node* next = cur->next;
            if(cur->next == nullptr)
                new_head = cur;

            cur->next = pre;
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
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    Solution s;
    Node* result = s.reverse_list(node1);
    while(result){
        cout<<result->_data<<"->";
        result = result->next;
    }

    return 0;
}
