#include<iostream>
using namespace std

/*
 * 问题描述：给一段绳子，切成M段，要求各段乘积最大
 * 1.采用动态规划，自底向上的思想，防止子问题重复计算
 * 2.采用贪心算法，N>=5,尽可能剪3,为4时，剪成两个2
 *
 */

int maxProductAfterCutting_solution1(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    //用来保存子问题最优解
    int* Products = new int[length+1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    for(int i = 4;i < length;++i){
        max = 0;
        for(int j = 0;j <= i/2;++j){
            int product = products[j] * products[i-j];
            if(max < product)
                max = product;

            products[i] = max;
        }
    }

    max = products[length];
    delete[] products;

    return max;
}



int maxProductAfterCutting_solution2(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    //尽可能多的剪去长度为3的绳子段
    int timesOf3 = length/3;

    //当绳子长度为4时，不能在剪去长度为3的绳子段
    //应剪成两个2，因为2*2 > 3*1
    
    if(length-timesOf3 * 3 == 1)
        timesOf3 -= 1;

    int timesOf2 = (length-timesOf3 * 3)/2;

    return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));
}
