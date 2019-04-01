#include<iostream>
#include<vector>


/* 解题思路: */
/*     1. 采用s标记value出现的位置 */
/*     2. 然后继续往后走,将正确的值与该位置的数字交换 */
    
class Solution
{
    int removeElement(std::vector<int>& v,int value)
    {
        if(v.empty())
            return 0;

        int s = 0;
        for(size_t i = 0;i < v.size();++i){
            if(v[i] != value)
                //左边是新数组中的数
                v[s++] = v[i];
        }
        return s;
    }
};
