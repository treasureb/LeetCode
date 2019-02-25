#include <vector>
#include <deque>

using namespace std;


/* 解题思路: */
/*     1. 采用deque存放可能成为窗口中最大值的下标 */
/*     2. 如果deque不空且当前队列中的最早一个数小于待插入的数，则该数不可能成为窗口中最大的 */
/*     3. 将队头元素划出窗口 */

vector<int> max_in_window(vector<int> nums,int size){
    vector<int> res;
    if(nums.empty() || size < 1)
        return res;

    deque<int> index;
    for(int i = 0;i < size;++i){
        while(!index.empty() && index.front() <= nums[i]){
            index.pop_back();
        }

        index.push_back(nums[i]);
    }

    for(size_t i = size;i < nums.size();++i){
        res.push_back(index.front());
        while(index.empty() && index.front() <= nums[i])
            index.pop_back();

        if(!index.empty() && index.front() <= (int)(i-size))
            index.pop_back();

        index.push_back(nums[i]);
    }

    res.push_back(nums[index.front()]);
    return res;
}
