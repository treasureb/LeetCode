#include<iostream>


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
