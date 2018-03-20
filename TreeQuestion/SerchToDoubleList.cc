#include<iostream>

#include"Tree.h"

/*
 * 1.将二叉树分为三部分，先链表化左子树
 * 2.保存左子树链表化后的最后一个节点
 * 3.链表化右子树
 */

void ConvertNode(Node* Root,Node** LastOfList)
{
   if(nullptr == Root)
       return;

   Node* Current = Root;

   //左不为空，就递归的先链表化左子树
   if(Current->_left != nullptr)
       ConvertNode(Current->_left,LastOfList);

   Current->_left = *LastOfList;
   if(*LastOfList != nullptr)
       (*LastOfList)->_right = Current;

   //更新链表中的最后一个节点
   *LastOfList = Current;

   if(Current->_right != nullptr)
       ConvertNode(Current->_right,LastOfList);
}


Node* Convert(Node* Root)
{
    Node* LastNodeInList = nullptr;
    ConvertNode(Root,&LastNodeInList);

    //LastNodeInList指向的是双向链表的尾节点
    //需要返回的是头节点
    Node* HeadOfList = LastNodeInList;
    while(HeadOfList != nullptr && LastNodeInList->_left)
            HeadOfList = HeadOfList->_left;

    return HeadOfList;
}
