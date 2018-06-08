#include"List.h"

void QuickSortList(Node* Head,Node* Tail)
{
    if(Head == nullptr || Head->_next == Tail || Head == Tail)
        return;

    Node* cur = Head->_next;
    Node* pre = Head;
    int key = Head->_data;//链表第一个节点作为基准值
    while(cur != Tail){
        if(cur->_data < key){
            pre = pre->_next;
            if(pre != cur){
                swap(cur->_data,pre->_data);
            }
        } 
        cur = cur->_next;
    }

    swap(Head->_data,pre->_data);
    QuickSortList(Head,pre);
    QuickSortList(pre->_next,Tail);
}

void BubbleSortList(Node* Head)
{
    if(Head == nullptr || Head->_next == nullptr)
        return;

    Node* cur = nullptr;
    Node* next = nullptr;
    Node* tail = nullptr;
    while(Head != tail){
        cur = Head;
        next = cur->_next;
        bool flag = false;
        while(next != tail){
            if(cur->_data > next->_data){
                swap(cur->_data,next->_data);
                flag = true;
            }
            cur = next;
            next = next->_next;
        }
        if(flag == 0)
            break;

        tail = cur;
    }
}


/*
 *
 *
 *   由于快速排序每次选取的Key值不一定都是
 *   合理的，故时间复杂度不是准确的O(nlgn)
 *   故采用归并排序
 */

//获取链表的中间节点
Node* GetMidNode(Node* Head)
{
    if(Head == nullptr)
        return nullptr;
    if(Head->_next == nullptr)
        return Head;

    Node* Fast = Head->_next;
    Node* Slow = Head;
    while(Fast && Fast->_next){
        Fast = Fast->_next->_next;
        Slow = Slow->_next;
    }

    return Slow;
}

Node* MergeTwoList(Node* Head1,Node* Head2)
{
    if(Head1 == nullptr)
        return Head2;
    if(Head2 == nullptr)
        return Head1;

    Node* newHead = nullptr;
    if(Head1->_data < Head2->_data){
        newHead = Head1;
        Head1 = Head1->_next;
    }else{
        newHead = Head2;
        Head2 = Head2->_next;
    }

    Node* cur = newHead;
    while(Head1 && Head2){
        if(Head1->_data < Head2->_data){
            cur->_next = Head1;
            cur = cur->_next;
            Head1 = Head1->_next;
        }else{
            cur->_next = Head2;
            cur = cur->_next;
            Head2 = Head2->_next;
        }
    }

    if(Head1)
        cur->_next = Head1;

    if(Head2)
        cur->_next = Head2;
    
    return newHead;
}

Node* MergeSortList(Node* Head)
{
    if(Head == nullptr)
        return nullptr;
    if(Head->_next == nullptr)
        return Head;

    Node* mid = GetMidNode(Head);
    Node* nextPart = nullptr;
    if(mid){
        nextPart = mid->_next;
        mid->_next = nullptr;
    }

    return MergeTwoList(MergeSortList(Head),MergeSortList(nextPart));
}

int main()
{
    Node* node1 = new Node(2);
    Node* node2 = new Node(5);
    Node* node3 = new Node(1);
    Node* node4 = new Node(3);

    node1->_next = node2;
    node2->_next = node3;
    node3->_next = node4;

    Print(node1);
    //Node* tail = nullptr;
    //QuickSortList(node1,tail);
    //BubbleSortList(node1);
    Node* ret = MergeSortList(node1);
    Print(ret);
    return 0;
}
