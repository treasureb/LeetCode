#include<iostream>
using namespace std;

double myPow(double x,int n)
{
    double ret = 1,tp = x;
    int p = n > 0?n : -n;
    while(p){
        if(p % 2)
            ret *= tp;//if (t[i] = 1)
        tp *= tp;
        p >>= 1;
    }
    return n < 0? 1/ret:ret;
}

int main()
{
    return 0;
}
