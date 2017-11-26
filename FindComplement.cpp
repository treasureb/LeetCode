#include<iostream>
#include<limits>
using namespace std;

int FindComplement1(int num)
{
    bool start = false;
    for(int i = 31;i >= 0;--i)
    {
        if(num & (1 << i))
            start = true;
        if(start)
        num ^= (1 << i);
    }
    return num;
}

int FindComplement2(int num)
{
    int mask = INT32_MAX;
    while(mask & num)
    {
        mask <<= 1;
    }
    return ~mask & ~num;
}

int FindComplement3(int num)
{
    return (1 - num%2)+2*(num <= 1?0:FindComplement3(num/2));
}

int main()
{
    int num1 = 512;
    cout<<FindComplement1(num1)<<endl;
    int num2 = 1;
    cout<<FindComplement1(num2)<<endl;

    cout<<FindComplement2(num1)<<endl;
    cout<<FindComplement2(num2)<<endl;

    cout<<FindComplement3(num1)<<endl;
    cout<<FindComplement3(num2)<<endl;

    cout<<INT32_MAX<<endl;
    return 0;
}
