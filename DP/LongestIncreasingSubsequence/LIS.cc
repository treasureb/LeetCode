#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    
    /* 贪心+二分,时间复杂度为O(nlogn) */
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

    int lengthOfLIS2(vector<int>& nums){
        vector<int> dp(nums.size(),1);
        int max_res = 1;
        for(int i = 0;i < (int)nums.size();++i){
            for(int j = 0;j < i;++j){   //扫描0-i中符合的边界
                dp[i] = max(dp[i],dp[j]+1);
            }
            max_res = max(dp[i],max_res);
        }

        return max_res;
    }
};
