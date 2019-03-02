#include "List.h"
#include <vector>
#include <map>

using namespace std;

class Solution{
public:

    /* 思路一: */
    /*     1. 采用map保存所有数字和出现的次数，然后重新链起来 */

    ListNode* merge_list(vector<ListNode*>& lists){
        map<int,int> m;
        ListNode* root = new ListNode(0);
        ListNode* merge = root;
        for(auto &list : lists){
            while(list){
                ++m[list->val];
                list = list->next;
            }
        }

        for(auto &element : m)
            for(int i = 0;i < element.second;++i)   //second保存同一个数字出现的次数
                merge = merge->next = new ListNode(element.first);

        return root->next;
    }

    /* 思路二: */
    /*     1.采用分治思想，两两合并 */

    ListNode* merge_list_divide(vector<ListNode*>& lists){
        if(lists.empty())
            return nullptr;

        int n = lists.size();
        while(n > 1){
           int k =(n+1)/2;  //加1是当为奇数时，从后半段开始 
           for(int i = 0;i < n/2;++i){
               lists[i] = helper(lists[i],lists[i+k]);
           }
           n = k;
        }
        return lists[0];
    }

    ListNode* helper(ListNode* l1,ListNode* l2){
        ListNode* new_head = new ListNode(-1);
        ListNode* cur = new_head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if(l1)
            cur->next = l1;
        if(l2)
            cur->next = l2;

        return new_head->next;
    }
};
