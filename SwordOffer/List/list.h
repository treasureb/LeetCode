#ifndef _LIST_H_
#define _LIST_H_

typedef struct LinkNode
{
    LinkNode(int value)
     :next(nullptr)
     ,_value(value)
    {}

    LinkNode* next;
    int _value;
}Node;


#endif
