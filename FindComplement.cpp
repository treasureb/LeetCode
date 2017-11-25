#include<iostream>
using namespace std;

int FindComplement(int num)
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

int main()
{
    int num1 = 5;
    cout<<FindComplement(num1)<<endl;
    int num2 = 1;
    cout<<FindComplement(num2)<<endl;
    return 0;
}
