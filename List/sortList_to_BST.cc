#include"List.h"
#include"../BinaryTree/Tree.h"

class Solution{
public:

    TreeNode* sortedListToBST(ListNode* head){
        if(head == nullptr)
            return nullptr;

        TreeNode* root = nullptr;
        insertNode(root,head);
        return root;
    }
private:
    void insertNode(TreeNode*& root,ListNode* head){
        if(head == nullptr)
            return;

        ListNode* p1 = head,*p2 = head,*p3,*p;
        while(p2 && p2->_next){
            p3 = p1;
            p1 = p1->_next;
            p2 = p2->_next->_next;
        }

        TreeNode* node = new TreeNode(p1->_data);
        root = node;
        if(p1 != head){
            p3->_next = nullptr;
            insertNode(root->_left,head);
        }
        p = p1->_next;
        insertNode(root->_right,p);
    }
};
