#include <vector>
using namespace std;

class Solution{
    vector<int> find_position(vector<int>& nums,int target){
        vector<int> res(2,-1);
        if(nums.empty())
            return res;

        int left = 0,right = nums.size();
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }

        if(nums[left] != target)
            return res;

        res[0] = left;
        right = nums.size();
        while(left < right){
            int mid = (left + right) / 2 + 1;
            if(nums[mid] > target)
                right = mid - 1;
            else
                left = mid;
        }

        res[1] = right;

        return res;
    }
};
