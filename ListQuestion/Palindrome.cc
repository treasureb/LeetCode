#include"List.h"
#include<iostream>
#include<stack>

//判断单链表是否为回文
//采用栈来实现
using namespace std;

class Solution{
public:
    bool is_palindrome(Node* pHead){
        if(nullptr == pHead)
            return false;

        stack<int> s;
        Node* cur = pHead;
        while(cur){
            s.push(cur->_data);

            cur = cur->_next;
        }
        
        cur = pHead;
        while(!s.empty()){
            int top = s.top();
            if(top != cur->_data){
                return false;
            }else{
                s.pop();
                cur = cur->_next;
            }
        }
        return true;
    }
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(2);
    Node* node4 = new Node(3);

    node1->_next = node2;
    node2->_next = node3;
    node3->_next = node4;

    Solution s;
    bool result = s.is_palindrome(node1);
    cout<<result<<endl;
}
