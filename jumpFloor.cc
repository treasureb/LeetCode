#include<iostream>
using namespace std;

class Solution{
public:
    //因为采用了递归，所以时间复杂度会高
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
};

int main()
{
    Solution s;
    cout<<s.jumpFloor(10)<<endl;
    cout<<s.jumpFloor2(10);
    return 0;
}
