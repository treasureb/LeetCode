#include<iostream>
#include<vector>

using namespace std;

class Solution{
    int FindGreatSumOfSubArray(vector<int> array){
        if(array.empty())
            return 0;

        int max_sum = array[0];
        int cur_sum = array[0];
        for(int i = 1;i < (int)array.size();++i){
            //如果当前最大和为负数，则将当前最大值更新为当前值
            cur_sum = (array[i] < 0) ? array[i] : cur_sum + array[i];
            //如果当前最大值大于最大值，则更新最大值
            max_sum = (cur_sum > max_sum)? cur_sum : max_sum;
        }

        return max_sum;
    }    
};
