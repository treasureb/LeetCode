#include<unordered_set>
#include<vector>

using namespace std;

class Solution{
public:
    
    /* 解题思路: */
    /*         1.使用set保存原有数组的所有节点 */
    /*         2.依次便利原有数组,然后找其左边和右边的数字 */
    /*         3.在set中查找与其相邻的数字然后删除,当前最长序列+1 */
    /*         4.最后得出整个序列中最长的子序列 */

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
