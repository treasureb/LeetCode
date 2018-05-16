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

class Solution{
public:
    double Pow(double base,int exponent){
        long long p = abs((long long)exponent);
        double r = 1.0;
        while(p){
            if(p & 1)
                r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0?1/r:r;
    }
};

int main()
{
    return 0;
}
