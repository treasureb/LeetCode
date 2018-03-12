#include<stdio.h>
#include<iostream>

using namespace std;

typedef struct Node
{
    Node* _next;
    Node* _slibling;
    int _data;
}Node;

//首先复制链表的每个节点
void CloneNode(Node* Head)
{
    Node* node = Head;
    while(nullptr != node){
        Node* cloneNode = new Node();
        cloneNode->_data = node->_data;
        cloneNode->_next = node->_next;
        cloneNode->_slibling =nullptr;

        //将复制的节点挂在后面
        node->_next = cloneNode;
        node = cloneNode->_next;
    }
}

//复制随机指针
void ConnectSliblingNode(Node* Head)
{
    Node* node = Head;
    while(nullptr != node){
        Node* cloneNode = node->_next;

        if(nullptr != node->_slibling){
            cloneNode->_slibling = node->_slibling;
        }

        node = cloneNode->_next;
    }
}

//将原链表和复制链表分开
Node *ReConnectNode(Node* Head)
{
    Node* node = Head;
    Node* cloneHead = nullptr;
    Node* cloneNode = nullptr;

    //先判断链表是否为空
    if(nullptr != node){
        cloneHead = cloneNode = node->_next;
        node->_next = cloneNode->_next;
        node = node->_next;
    }

    while(nullptr != node){
        cloneNode->_next = node->_next;
        cloneNode = cloneNode->_next;
        node->_next = cloneNode->_next;
        node = node->_next;
    }

    return cloneHead;
}

Node* Clone(Node* Head)
{
    CloneNode(Head);
    ConnectSliblingNode(Head);
    return ReConnectNode(Head);
}

int main()
{
    return 0;
}
