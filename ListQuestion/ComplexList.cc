#include<stdio.h>
#include<iostream>

using namespace std;

typedef struct Node
{
    Node* _next;
    Node* _slibling;
    int _data;

    Node(int data)
    :_next(nullptr)
     ,_slibling(nullptr)
     ,_data(data)
    {}
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

class Solution{
public:
    /*
     * 1.复制每个节点,然后链接在当前节点的垢面
     * 2.遍历链表,给新创建的节点链接随机节点
     * 3.将两个链表拆分
     */
    Node* Clone(Node* pHead){
        if(pHead == nullptr)
            return nullptr;

        Node* cur = pHead;
        //1.复制节点
        while(cur){
            Node* node = new Node(cur->_data);
            node->_next = cur->_next;
            cur->_next = node;
            cur = node->_next;
        }

        cur = pHead;
        //2.给新节点赋随机链表指针
        while(cur){
            Node* node = cur->_next;
            if(cur->_slibling){
                node->_slibling = cur->_slibling->_next;
            }
            cur = node->_next;
        }

        //3.拆分两个链表
        Node* pCloneHead = pHead->_next;
        Node* tmp;
        cur = pHead;
        while(cur->_next){
            tmp = cur->_next;
            cur->_next = tmp->_next;
            cur = tmp;
        }
        return pCloneHead;
    }
};
