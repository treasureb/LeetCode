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
    /*
     * 采用快速幂算法
     * 1.直接对其二进位上的位置进行次方
     *   11 = 1011 即2^3+2^1+2^0
     *   11 = a^1 * a^2 * a^8
     */
    double Pow(double base,int exponent){
        //先直接求其绝对值,最后在判断正负
        long long p = abs((long long)exponent);
        //基数为1
        double res = 1.0;
        while(p){
            //如果是奇数的话,乘上上次的base
            if(p & 1)
                res *= base;
            //在第几位就是base的几次方
            base *= base;
            p >>= 1;
        }
        return exponent < 0?1/res:res;
    }
};

int main()
{
    return 0;
}
