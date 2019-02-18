#include"Tree.h"
#include<stack>

//递归求一个树的镜像
void MirrorTree(TreeNode* Root)
{
    if(Root == nullptr)
        return;

    if(Root->left == nullptr && Root->right == nullptr)
        return;

    swap(Root->left,Root->right);
    if(Root->left)
        MirrorTree(Root->left);
    if(Root->right)
        MirrorTree(Root->right);
}

//非递归求树的镜像
void mirror_tree(TreeNode* root)
{
    if(root == nullptr)
        return;

    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* top = s.top();
        s.pop();
        if(top->left != nullptr || top->right != nullptr)
            swap(top->left,top->right);

        if(top->left)
            s.push(top->left);
        if(top->right)
            s.push(top->right);
    }
}
