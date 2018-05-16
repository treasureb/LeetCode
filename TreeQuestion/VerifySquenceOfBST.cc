#include<iostream>
#include<vector>

using namespace std;
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


class Solution
{
public:
    //递归
    bool verify_squene(vector<int> squence)
    {
        int len = squence.size();
        if(len < 0)
            return false;

        return judge(squence,0,len-1);
    }

    //非递归
    bool verify_squence_of_bst(vector<int> sequence)
    {
        int size = sequence.size();
        if( 0 == size)
            return false;

        int i = 0;
        while(--size){
            while(sequence[i++] < sequence[size]);
            while(sequence[i++] > sequence[size]);

            if(i < size)
                return false;
            i = 0;
        }
        return true;
    }
private:
    bool judge(vector<int> squence,int left,int right)
    {
        if(left >= right)
            return true;

        //判断右子树
        int i = right;
        while(i > left && squence[i-1] > squence[right])
            --i;
        
        //判断左子树
        for(int j = i-1;j >= 1;--j){
            if(squence[j] > squence[right])
                return false;
        }
        return judge(squence,left,i-1)&&(judge(squence,i,right-1));
    }
};
