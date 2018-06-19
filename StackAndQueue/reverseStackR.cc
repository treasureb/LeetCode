#include<vector>
using namespace std;

/*
 * 题目描述:利用递归和栈操作逆序一个栈
 */

class Solution{
public:
    vector<int> reverse_stack_R(vector<int> stack,int top){
        if(top == 1)
            return stack;

        int tmp = stack.back();              //最上面的数出栈
        stack.pop_back();
        stack = reverse_stack_R(stack,top-1);//递归调用
        stack = insertToBottom(stack,tmp);   //用一个函数实现将一个数插入到最底层
        return stack;
    }
private:
    vector<int> insertToBottom(vector<int> stack,int num){
        if(stack.size() == 0){               //当栈为空的时候,将该数放入栈底
            stack.push_back(num);
            return stack;
        }

        int top = stack.back();             
        stack.pop_back();                   //将最上面的数出栈保存 
        stack = insertToBottom(stack,num);  //把数插入到最底层
        stack.push_back(top);               //再把原先的最上面的数入栈

        return stack;
    }
};
