#include<unordered_set>
#include<vector>

using namespace std;

class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        int max_res = 0;
        unordered_set<int> us(nums.begin(),nums.end());
        for(int i = 0;i < (int)nums.size();i++){
            if(!us.count(nums[i]))
                continue;

            us.erase(nums[i]);
            int pre = nums[i]-1,next = nums[i]+1;
            while(us.count(pre))
                us.erase(pre--);
            while(us.count(next))
                us.erase(next++);

            max_res = max(max_res,next-pre-1);
        }
        return max_res;
    }
};
