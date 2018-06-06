#include"List.h"


class Solution{
    /*
     * 1.采用递归思想
     */

    Node* DeleteDuplication_R(Node* pHead){
        if(pHead == nullptr)
            return nullptr;
        if(pHead && pHead->_next == nullptr)
            return pHead;

        Node* cur = nullptr;
        if(pHead->_next->_data == pHead->_data){
            cur = pHead->_next->_next;
            while(cur && cur->_data == pHead->_data)
                cur = cur->_next;

            return DeleteDuplication_R(cur);
        }else{
            cur = pHead->_next;
            pHead->_next = DeleteDuplication_R(cur);
            return pHead;
        }
    }


    /*
     * 2.非递归
     *
     */

    Node* DeleteDuplication(Node* pHead){
        if(pHead == nullptr)
            return nullptr;

        Node* pre = nullptr;
        Node* cur = pHead;
        while(cur){
            Node* next = cur->_next;
            bool needDel = false;
            //如果有相同的节点，则说明有待删除的节点
            if(next && next->_data == cur->_data)
                needDel = true;

            //如果没有相同的节点，则向后遍历
            if(!needDel){
                pre = cur;
                cur = cur->_next;
            }else{
                int value = cur->_data;
                Node* ToBeDel = cur;
                //循环判断下一个节点是否重复
                while(ToBeDel && ToBeDel->_data == value){
                    next = ToBeDel->_next;
                    ToBeDel = next;
                    //如果头节点重复，则需要更新pHead
                    if(pre == nullptr)
                        pHead = next;
                    else
                        pre->_next = next;

                    cur = next;
                }
            }
        }
        return pHead;
    }
};
