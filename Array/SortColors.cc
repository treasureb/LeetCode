#include <vector>
#include <algorithm>

using namespace std;

/* 解题思路: */
/*     1. 将数组中所有的0，1，2按照顺序排列，只允许一次遍历 */
/*     2. 设立两个哨位，一个标记0的位置，一个标记2的位置 */
/*     3. 如果遇到2就和后面的哨位交换 */
/*     4. 如果遇到0就和前面的哨位交换 */

class Solution{
public:
     void sort_colors(vector<int>& nums){
        int red = 0,blue = nums.size()-1;
        for(int i = 0;i < (int)nums.size();++i){
            while(nums[i] == 2 && i < blue)
                swap(nums[i],nums[blue--]);
            while(nums[i] == 0 && i > red)
                swap(nums[i],nums[red++]);
        }
    }
};
