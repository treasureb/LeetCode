#include"Tree.h"
#include<stack>

//递归求一个树的镜像
void MirrorTree(Node* Root)
{
    if(Root == nullptr)
        return;

    if(Root->_left == nullptr && Root->_right == nullptr)
        return ;

    //走到这里就可以进行交换了。
    
    Node* tmp = Root->_left;
    Root->_left = Root->_right;
    Root->_right = tmp;

    if(Root->_left)
        MirrorTree(Root->_left);
    if(Root->_right)
        MirrorTree(Root->_right);
}

//非递归求树的镜像
void mirror_tree(Node* root)
{
    if(root == nullptr)
        return;

    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* top = s.top();
        s.pop();
        if(top->_left != nullptr || top->_right != nullptr)
            swap(top->_left,top->_right);

        if(top->_left)
            s.push(top->_left);
        if(top->_right)
            s.push(top->_right);
    }
}
