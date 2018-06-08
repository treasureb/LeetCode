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
     :_next(nullptr)
      ,_data(data)
    {}
	Node* _next;
	TYPE _data;
}Node;

void Print(Node* Head)
{
    if(nullptr == Head)
        return;
    Node* cur = Head;
    while(cur){
        cout<<cur->_data<<"->";
        cur = cur->_next;
    }
    cout<<endl;
}

#endif
