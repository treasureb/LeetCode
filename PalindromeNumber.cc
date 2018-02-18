#include<iostream>
using namespace std;

bool IsParlindrome(int x)
{
    if(x < 0)
        return false;

    long y = 0,z = x;
    while(x > 0)
    {
        y = y*10 + x%10;
        x = x/10;
    }
    return y == z;
}

void Test()
{
    cout<<IsParlindrome(-123124)<<" ";
    cout<<IsParlindrome(1)<<" ";
    cout<<IsParlindrome(123)<<" ";
    cout<<IsParlindrome(101)<<" ";

}
int main()
{
    Test();
    return 0;
}
