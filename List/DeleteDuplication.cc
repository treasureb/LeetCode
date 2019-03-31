#include"List.h"


class Solution{
    /*
     * 1.采用递归思想
     */

    Node* DeleteDuplicationR(Node* pHead){
        if(pHead == nullptr)
            return nullptr;
        if(pHead && pHead->next == nullptr)
            return pHead;

        Node* cur = nullptr;
        if(pHead->next->val == pHead->val){
            cur = pHead->next->next;
            while(cur && cur->val == pHead->val)
                cur = cur->next;

            return DeleteDuplicationR(cur);
        }else{
            cur = pHead->next;
            pHead->next = DeleteDuplicationR(cur);
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
            Node* next = cur->next;
            bool needDel = false;
            //如果有相同的节点，则说明有待删除的节点
            if(next && next->val == cur->val)
                needDel = true;

            //如果没有相同的节点，则向后遍历
            if(!needDel){
                pre = cur;
                cur = cur->next;
            }else{
                int value = cur->val;
                Node* ToBeDel = cur;
                //循环判断下一个节点是否重复
                while(ToBeDel && ToBeDel->val == value){
                    next = ToBeDel->next;
                    ToBeDel = next;
                    //如果头节点重复，则需要更新pHead
                    if(pre == nullptr)
                        pHead = next;
                    else
                        pre->next = next;

                    cur = next;
                }
            }
        }
        return pHead;
    }
};
