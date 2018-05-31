#include<iostream>
#include<vector>

using namespace std;

void PrintContinuousSequence(int small,int big)
{
    for(int i = small;i <= big;++i){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;

    int small = 1;
    int big = 2;
    int middle = (1 + sum)/2;
    int curSum = small + big;

    //当small等于总和的一半时，不可能再有连续的几数之和等于总和
    while(small < middle){
        if(curSum == sum)
            PrintContinuousSequence(small,big);

        while(curSum > sum && small <  middle){
            //小技巧，直接在前一次的结果上进行计算
            curSum -= small;
            small++;

            if(curSum == sum)
                PrintContinuousSequence(small,big);
        }

        big++;
        curSum += big;
    }
}

/*
 *  采用双指针的思想
 *  1.当总和小于sum,high++
 *  2.当总和大于sum,low++
 *  3.当总和等于sum,然后low++,继续寻找下一组
 *
 */
class Solution{
public:
    vector<vector<int>> FindContinuousSequence(int sum){
        vector<vector<int>> allRes;
        int high = 2;
        int low = 1;
        while(high > low){
            //求和公式
            int cur = (high+low)*(high-low + 1)/2;
            if(cur < sum)
                high++;
            if(cur == sum){
                vector<int> res;
                for(int i = low;i <= high;++i)
                    res.push_back(i);

                allRes.push_back(res);
                low++;
            }
            if(cur > sum)
                low++;
        }
        return allRes;
    }
};
