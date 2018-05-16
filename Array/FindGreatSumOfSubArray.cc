#include<iostream>
#include<vector>

using namespace std;

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

class Solution{
    int FindGreatSumOfSubArray(vector<int> array){
        if(array.empty())
            return 0;

        int sum = array[0];
        int tmpsum = array[0];
        for(int i = 1;i < (int)array.size();++i){
            //如果当前最大和为负数，则将当前最大值更新为当前值
            tmpsum = (tmpsum < 0) ? array[i] : tmpsum + array[i];
            //如果当前最大值大于最大值，则更新最大值
            sum = (tmpsum > sum)? tmpsum : sum;
        }

        return sum;
    }    
};
