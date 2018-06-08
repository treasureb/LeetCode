#include<iostream>
#include<stack>
#include<list>

#include"Tree.h"

/*
 *
 *  假设是一个二叉树，并且是搜索二叉树
 *
 */

Node* CommonAncestorInSearchTree(Node* Root,Node* Root1,Node* Root2)
{
    if(nullptr == Root || nullptr == Root1 || nullptr == Root2)
        return nullptr;

        if(Root->_value < Root1->_value && Root->_value < Root2->_value){
            CommonAncestorInSearchTree(Root->_right,Root1,Root2);
        }else if(Root->_value > Root1->_value && Root->_value > Root2->_value){
            CommonAncestorInSearchTree(Root->_left,Root1,Root2);
        }else{
            return Root;
        }
        
        return nullptr;
}


/*
 *
 *  如果不是搜索树，但是有指向父节点的指针
 *  转化为求两个链表的最近公共祖先
 *
 */


int GetLength(Node* node)
{
    if(nullptr == node)
        return 0;
    int len = 0;
    while(node){
        node = node->_parent;
        len++;
    }
    return  len;
}

Node* CommonAncestorInParent(Node* Root,Node* Root1,Node*Root2)
{
    if(nullptr == Root || nullptr == Root1 || nullptr == Root2)
        return nullptr;

    int len1 = GetLength(Root1);
    int len2 = GetLength(Root2);
    //两个链表的差值
    int gap = abs(len1-len2);

    //标记长链表和短链表
    Node* LongPath = nullptr;
    Node* ShortPath = nullptr;
    if(len1 > len2){
        LongPath = Root1;
        ShortPath = Root2;
    }else{
        LongPath = Root2;
        ShortPath = Root1;
    }

    //长的先走，然后找交点
    for(int i = 0;i < gap; ++i)
        LongPath = LongPath->_parent;

    while(LongPath && ShortPath && LongPath->_value != ShortPath->_value){
        LongPath = LongPath->_parent;
        ShortPath = ShortPath->_parent;
    }

    if(LongPath->_value == ShortPath->_value)
        return LongPath;

    return nullptr;
}


/*
 * 普通二叉树，也没有指向父节点的指针
 * 先保存两个节点的路径，然后去
 *
 */

bool GetNodePath(Node* Root,Node* node,list<Node*>& path)
{
    if(nullptr == Root)
        return false;

    if(Root == node){
        path.push_back(Root);
        return true;
    }

    path.push_back(Root);
    bool found = false;
    if(Root->_left != nullptr)
        found = GetNodePath(Root->_left,node,path);
    if(!found && Root->_left != nullptr)
        found = GetNodePath(Root->_right,node,path);

    if(!found)
        path.pop_back();

    return found;
}

Node* LastCommonNode(list<Node*> s1,list<Node*> s2)
{
    list<Node*>::iterator it1 = s1.begin();
    list<Node*>::iterator it2 = s2.begin();
    Node* target = nullptr;
    while(it1 != s1.end() && it2 != s2.end()){
        if(*it1 == *it2){
            target = *it1;
            it1++;
            it2++;
        }else
            break;
    }
    return target;
}

Node* GetCommonParent(Node* Root,Node* Root1,Node* Root2)
{
    list<Node*> path1;
    list<Node*> path2;
    GetNodePath(Root,Root1,path1);
    GetNodePath(Root,Root2,path2);

    return LastCommonNode(path1,path2);
}
