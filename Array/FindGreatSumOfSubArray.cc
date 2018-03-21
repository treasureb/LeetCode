#include<iostream>

int FindGreatSumOfSubArray(int* Data,int length)
{
    if(nullptr == Data || length <= 0)
        return -1;

    int CurSum = 0;
    int GreatestSum = 0x80000000;
    for(int i = 0;i < length;i++){
        //如果当前和小于0，就丢弃前面的值
        if(CurSum < 0)
            CurSum = Data[i];
        else
            //前面的和大于0，则加上当前的值
            CurSum += Data[i];

        //更新最大的子数组和
        if(CurSum > GreatestSum)
            GreatestSum = CurSum;
    }

    return GreatestSum;
}
