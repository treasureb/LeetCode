#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

/* 解题思路: */
/*     1. 从后往前找到第一个不符合升序的数 */
/*     2. 从后往前找到第一个大于该数的数字并且两者交换 */
/*     3. 将后面的所有数字进行逆序 */

class Solution{
public:
    void NextPermutation(vector<int>& nums){
        int i = nums.size()-2,j = nums.size()-1;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;

        if(i >= 0){
            while(nums[j] <= nums[i])
                --j;
            swap(nums[j],nums[i]);
        }

        reverse(nums.begin()+i+1,nums.end());
    }
};
