#include<iostream>
#include<vector>
#include<map>
using namespace std;

/*
 *  数组中和为某一值的两个数
 *
 */
vector<int> TwoSum(vector<int>& nums,int target)
{
    map<int,int> Hash;    
    for(size_t i = 0;i < nums.size();i++)
    {
        Hash[nums[i]] = i;
    }

    vector<int> ans(2);

    for(int i  = 0;i < (int)nums.size();++i)
    {
        if(Hash.find(target-nums[i]) != Hash.end() && Hash[target-nums[i]] != i)
        {
            ans[0] = i;
            ans[1] = Hash[target-nums[i]];
            break;
        }
    }
    return ans;
}

