#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


/* 解题思路: */
/*     1. 先对非法输入之类进行剪枝 */
/*     2. 三个正数不可能和为0,所以当某数为负数时，在剩余的区间内求其相反数 */
/*     3. 注意去除重复的值 */

class Solution{
    vector<vector<int>> three_sum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());

        //先进行剪枝
        if(nums.size() < 3 || nums.back() < 0 || nums.front() > 0)
            return res;

        for(size_t k = 0;k < nums.size();++k){
            if(nums[k] > 0) //如果该数为正数，则后面不能再有三个数之和为0
                break;

            /* 去掉重复的结果 */
            if(k > 0 && nums[k] == nums[k-1])
                continue;

            
            int target = 0 - nums[k];
            int i = k+1,j = nums.size()-1;
            while(i < j){
                if(nums[i] + nums[j] == target){
                    res.push_back({nums[k],nums[i],nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j; //避免重复值
                    ++i,--j;
                }else if(nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};

