#include<iostream>

#include"Tree.h"

bool VerifySquenceOfBST(int sequece[],int length)
{
    if(nullptr == sequece || length <= 0)
        return false;
    
    int root = sequece[length -1];

    //在二叉搜索树中，左子树都小于根
    int i = 0;
    for(; i < length-1;++i){
        if(sequece[i] > root)
            break;
    }

    //判断右子树上的值是否都大于根
    int j = i;
    for(;j < length-1;++j){
        if(sequece[j] < root)
            return false;
    }

    //递归判断左子树
    bool left = true;
    if(i > 0)
        left = VerifySquenceOfBST(sequece,i);

    //递归判断右子树
    bool right = true;
    if(i < length - 1)
        right = VerifySquenceOfBST(sequece,length-i-1);

    return (left && right);
}
