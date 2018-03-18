#include<iostream>
#include<vector>

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
