#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
        :val(x)
     ,next(NULL)
    {}
};

ListNode* AddTwoLink(ListNode* l1,ListNode* l2)
{
    int carry = 0;
    //构造一个头节点，这样不用对第一个节点进行特殊处理
    ListNode* res = new ListNode(0);
    ListNode* Head = res;

    //两个链表同时存在
    while(l1 && l2)
    {
        res->next = new ListNode((l1->val + l2->val + carry)%10);
        carry = (l1->val + l2->val + carry)/10;
        l1 = l1->next;
        l2 = l2->next;
        res = res->next;
    }

    while(l1)
    {
        res->next = new ListNode((l1->val +carry)%10);
        carry = (l1->val + carry)/10;
        l1 = l1->next;
        res = res->next;
    }

    while(l2)
    {
        res->next = new ListNode((l2->val + carry)%10);
        carry = (l2->val + carry)/10;
        l2 = l2->next;
        res = res->next;
    }

    //如果链表的最后一个节点产生进位
    if(carry > 0)
        res->next = new ListNode(carry);
    
    return Head->next; 
}

void PrintList(ListNode* Head)
{
    ListNode* cur = Head;
    while(cur)
    {
        cout<<cur->val<<"->";
        cur = cur->next;
    }
}
int main()
{
    ListNode* p1 = new ListNode(3);
    ListNode* p2 = new ListNode(7);
    //ListNode* p3 = new ListNode(3);
    
    p1->next = p2;
    //p2->next = p3;

    ListNode* p4 = new ListNode(9);
    ListNode* p5 = new ListNode(2);
    //ListNode* p6 = new ListNode(4);

    p4->next = p5;
    //p5->next = p6;

    PrintList(p1);
    cout<<endl;
    PrintList(p4);
    cout<<endl;
    ListNode* Head = AddTwoLink(p1,p4);
    PrintList(Head);
    cout<<endl;
    int x = 10/10;
    cout<<x<<endl;
    return 0;
}
