#include <vector>

using namespace std;

/* 解题思路: */
/*     1. 采用双指针 */

class Solution{
public:
    int trap(vector<int>& height){
        int left = 0,right = height.size(),water = 0,minHeight = 0;
        while(left < right){
            while(left < right && height[left] <= minHeight)
                water += minHeight - height[left++];
            while(left < right && height[right] <= minHeight)
                water += minHeight - height[right--];
            minHeight = min(height[left],height[right]);
        }
        return water;
    }
};
