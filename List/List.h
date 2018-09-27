#ifndef _LIST_
#define _LIST_


#include<stack>
#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<cstddef>

using namespace std;

#define HASH
#define TYPE int

typedef struct Node
{
    Node(TYPE data)
     :next(nullptr)
      ,val(data)
    {}
	Node* next;
	TYPE val;
}ListNode;

void Print(Node* Head)
{
    if(nullptr == Head)
        return;
    Node* cur = Head;
    while(cur){
        cout<<cur->val<<"->";
        cur = cur->next;
    }
    cout<<endl;
}

#endif
