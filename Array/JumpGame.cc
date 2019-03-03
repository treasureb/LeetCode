#include <vector>
using namespace std;

class Solution{

    /* 解题思路: */
    /*     0. 求是否能到达最后一个下标处  */
    /*     1. 求每走一步所能到达的最远距离 */
    /*     2. 采用贪心策略 */

    bool jump_game_1(vector<int> nums){
        int max_reach = 0;
        for(int i = 0;i < (int)nums.size();++i){
            if(i > max_reach || max_reach > (int)nums.size() - 1)
                break;

            max_reach = max(max_reach,i+nums[i]);
        }

        return max_reach >= ((int)nums.size() - 1);
    }


    /* 解题思路: */
    /*     0. 求到达最后一个下标处时所需最小的跳数 */
    /*     1. 定义cur和pre两个变量，来表示当前最远距离和之前最远距离 */

    int jump(vector<int> nums){
        int res = 0,i = 0,cur = 0;
        while(cur < (int)nums.size()-1){
            res++;
            int pre = cur;
            for(;i <= pre;++i)  //当i <= pre时，说明还在上一条的范围内
                cur = max(cur,i+nums[i]);

            if(pre == cur)
                return -1;
        }

        return res;
    }
};
