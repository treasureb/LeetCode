#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

bool g_InvalidInput = false;

double PowerWithUnsignedExponent(double,int);
double Power(double base,int exponent)
{
    g_InvalidInput = false;

    //注意浮点数不能直接比较
    if(equal(base,0.0) && exponent < 0){
        g_InvalidInput = true;
        return 0.0;
    }

    //如果指数为负，则先取绝对值，然后求倒数
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent  = (unsigned int)(-exponent);

    double result = PowerWithUnsignedExponent(base,absExponent);
    if(exponent < 0)
        result = 1.0/result;
   
    return result;
}

//循环次数过多
double PowerWithUnsignedExponent(double base,int exponent)
{
    double result = 1.0;
    for(int i = 0;i < exponent;++i)
        result *= base;

    return result;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double result = PowerWithUnsignedExponent(base,exponent>>1);
    result *= result;
    //判断最低位是0还是1
    if((exponent & 0x1) == 1)
        result *= base;

    return result;
}

