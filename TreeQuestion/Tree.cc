#include"Tree.h"

BinaryTreeNode* Construct(int* startProOrder,int* endProOrder,int* startInOrder,int* endInOrder)
{
    //构造根节点
    int rootValue = startProOrder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->_value = rootValue;
    root->_left = nullptr;
    root->_right = nullptr;

    //判断输入额度参数
    if(startProOrder == endProOrder){
        if(startInOrder == endInOrder && *startProOrder == *startInOrder)
            return root;

        cout<<"Invalid Input"<<endl;
    }

    //在中序遍历中找根节点划分子结构
    int* rootInOrder = startInOrder;
    while(rootInOrder <= endInOrder && *rootInOrder != rootValue)
        rootInOrder++;

    if(rootInOrder == endInOrder && *rootInOrder != rootValue)
        cout<<"Invalid Input"<<endl;

    int leftlength = rootInOrder - startInOrder;
    int* leftPreOrderEnd = startProOrder + leftlength;
    if(leftlength > 0){
        //构建左子树
        root->_left = Construct(startProOrder+1,leftPreOrderEnd,startInOrder,rootInOrder-1);
    }
    if(leftlength < endProOrder - startProOrder){
        //构建右子树
        root->_right = Construct(leftPreOrderEnd+1,endProOrder,rootInOrder+1,endInOrder);
    }

    return root;
}

BinaryTreeNode* RebuileTree(int* preOrder,int* inOrder,int length)
{
    if(nullptr == preOrder || nullptr == inOrder || length <= 0)
        return nullptr;

    return Construct(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
}


int main()
{
    return 0;
}
