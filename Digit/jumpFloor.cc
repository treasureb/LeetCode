#include<iostream>
using namespace std;

class Solution{
public:
    //因为采用了递归，所以时间复杂度会高
    //一次跳一阶或者两阶
    int jumpFloor(int num)
    {
        if(num == 0)
            return -1;
        else if(num == 1)
            return 1;
        else if(num == 2)
            return 2;
        else 
            return jumpFloor(num-1)+jumpFloor(num-2);
    }


    //采用保存前面值的思想，避免重复计算
    int jumpFloor2(int num)
    {
        if(num == 0)
            return 0;
        else if(num == 1)
            return 1;
        else if(num == 2)
            return 2;
        else{
            int a = 0;
            int b = 1;
            int c = 0;
            for(int i = 1;i < num;++i){
                c = b;
                b = a+b;
                a = c;
            }
            return b;
        }
    }

    //一次跳1，2.....n
    int jumpFloor3(int number)
    {
        if(number < 0)
            return -1;
        else if(number == 1)
            return 1;
        else if(number == 2)
            return 2;
        else
            return 2*jumpFloor3(number-1);
    }
};

int main()
{
    Solution s;
    cout<<s.jumpFloor(10)<<endl;
    cout<<s.jumpFloor2(10);
    return 0;
}
