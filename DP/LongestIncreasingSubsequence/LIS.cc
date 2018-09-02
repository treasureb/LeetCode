#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        if(nums.empty())
            return 0;

        vector<int> dp(nums.size(),INT_MAX);
        dp[0] = nums[0];
        int pos = 0;    //记录dp数组中最后一个数的下标
        for(int i = 0;i < (int)nums.size();++i){
            if(nums[i] > dp[pos]){
                dp[pos++] = nums[i];
            }else{
                //lower_bound返回值为迭代器
                dp[lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin()] = nums[i];
            }
        }
        return pos+1;
    }
};
