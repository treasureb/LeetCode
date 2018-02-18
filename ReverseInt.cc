#include<iostream>
#include<limits.h>
using namespace std;

int ReverseInteger(int x)
{
    bool flag = false;
    if(x < 0)
        flag = true;
    
    if(flag)
        x = 0 - x;

    long y = 0;
    while(x > 0)
    {
        y = y*10 + x%10;
        x /= 10;
    }

    if(y > INT_MAX)
        return 0;
    
    if(flag)
        y = 0 - y;
    
    return y;
}

void Test()
{
    cout<<"-1    "<<ReverseInteger(-1)<<endl;
    cout<<"-422342334       "<<ReverseInteger(-422342334)<<endl;
    cout<<"100     "<<ReverseInteger(100)<<endl;
    cout<<"123     "<<ReverseInteger(123)<<endl;
    cout<<"1534236469     "<<ReverseInteger(1534236469)<<endl;
    cout<<INT_MAX<<endl;
}
int main()
{
    Test();
    return 0;
}
