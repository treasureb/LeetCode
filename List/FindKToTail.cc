#include"List.h"

Node* find_k_to_tail(Node* Head,unsigned int k)
{
    if(Head == nullptr || k == 0)//不存在倒数第0个
        return nullptr;

    Node* Fast = Head;
    Node* Slow = Head;
    for(unsigned int i = 0;i < k -1;++i){
        if(Fast->_next != nullptr)
             Fast = Fast->_next;
        else
            return nullptr;
    }
    while(Fast->_next != nullptr){
        Fast = Fast->_next;
        Slow = Slow->_next;
    }
    return Slow;
}

int main()
{
    return 0;
}
