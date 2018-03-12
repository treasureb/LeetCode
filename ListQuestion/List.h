#ifndef _LIST_
#define _LIST_


#include<stack>
#include<iostream>
#include<stdio.h>
#include<assert.h>

using namespace std;

#define HASH
#define TYPE int

typedef struct Node
{
	Node* _next;
	TYPE _data;
}Node;

#endif
