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

    for(size_t i  = 0;i < nums.size();++i)
    {
        if(Hash.find(target-nums[i]) != Hash.end() && Hash[target-nums[i]] != i)
        {
            ans[0] = i+1;
            ans[1] = Hash[target-nums[i]] +1;
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {2,4,6,8,3,14};
    vector<int> ret = TwoSum(v,17);
    vector<int>::iterator it = ret.begin();
    while(it != ret.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}
