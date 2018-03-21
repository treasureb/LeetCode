#include<iostream>

using namespace std;

/*
 * 1.两个数相加不计进位->相当于异或^
 * 2.计算进位，只有都是1才会进位左移一位->进行&操作然后左移
 * 3.循环相加即可
 *
 */



int Add(int num1,int num2)
{
    int sum,carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2)<<1;
        num1 = sum;
        num2 = carry;
    }while(num2 != 0);

    return num1;
}


/*
 *  不使用新的变量交换两个值
 *
 */

void Swap1(int a,int b)
{
    a = a + b;//两数之和
    b = a - b;//a,b之和减去b,即为a
    a = a - b;//a,b之和减去a,即为b
}

void Swap2(int a,int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
