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

//获取中序遍历的下一个节点
BinaryTreeNode* GetNextNode(BinaryTreeNode* Node)
{
    if(Node == nullptr)
        return NULL;
    
    BinaryTreeNode* Next = nullptr;
    //如果右存在，下一个节点为右节点的最左
    if(Node->_right != nullptr){
        Node = Node->_right;
        while(Node->_left){
            Node = Node->_left;
        }
        
        Next = Node;
        //找到一个节点是它父节点的左节点，则父节点就是下一个节点
    }else if(Node->_parent != nullptr){
        BinaryTreeNode* cur = Node;
        BinaryTreeNode* parent = cur->_parent;
        while(parent != nullptr && cur == parent->_right){
            parent = cur;
            parent = parent->_parent;
        }

        Next = parent;
    } 
        
    return Next;
}

int main()
{
    return 0;
}
