#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
    int start;
    int end;

    Interval()
    :start(0)
     ,end(0)
    {}

    Interval(int s,int e)
    :start(s)
    ,end(e)
    {}
};

class Solution{

    /* 解题思路: */
    /*     1. 先将整个序列进行排序，利用lamdba表达式自定义排序 */
    /*     2. 如果前一个序列的end小于当前的start说明没有重叠 */
    /*     3. 否则比较前一个序列的end和当前序列end的大小 */
        
    vector<Interval> merge_interval(vector<Interval>& intervals){
        if(intervals.empty())
            return {};

        sort(intervals.begin(),intervals.end(),[](Interval& a,Interval& b){return a.start < b.start;});
        vector<Interval> res{intervals[0]};
        for(int i = 1;i < (int)intervals.size();++i){
            if(res.back().end < intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end,intervals[i].end);
        }
        return res;
    }
};
