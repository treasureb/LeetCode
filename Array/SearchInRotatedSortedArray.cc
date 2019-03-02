#include <vector>
using  namespace std;

/* 解题思路: */
/*     1. 有序的序列进行了一次旋转，故采用二分法求目标数 */

class Solution{
public:
    int search(vector<int>& nums,int target){
        int left = 0,right = nums.size();
        while(left <= right){
            int mid = (left+right) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] < nums[right]){    //有序序列在右边
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }else{
                if(nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }

        return -1;
    }        
};

