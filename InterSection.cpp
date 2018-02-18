#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//利用set的天然去重功能
vector<int> InterSection(vector<int>& nums1,vector<int>& nums2)
{
    set<int> s(nums1.begin(),nums1.end()),res;//将nums1放入set中
    for(auto a : nums2)//
    {
        if(s.count(a))//遍历vector nums2，如果该数在set中出现，就插入到保存结果的set中           
            res.insert(a);
    }
    return vector<int>(res.begin(),res.end());//将结果保存回一个vector中
};

//对两组记录排序，然后依次合并
vector<int> InterSection2(vector<int>& nums1,vector<int>& nums2)
{
    vector<int> res;
    int i = 0;
    int j = 0;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    while(i < nums1.size() && j < nums2.size())
    {
        if(nums1[i] > nums2[j])
            j++;
        else if(nums1[i] < nums2[i])
            ++i;
        else
        {
            if(res.empty() || res.back() != nums1[i])//对相同的数只保存一个
            res.push_back(nums1[i]);

            ++i;
            ++j;
        }
    }
    return res;
}


bool binarySearch(vector<int>& nums,int target)
{
    int left = 0;
    int right = nums.size();
    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] == target)
            return true;
        else if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return false;
}

//采用二分法
vector<int> InterSection3(vector<int>& nums1,vector<int>& nums2)
{
    set<int> res;
    sort(nums2.begin(),nums2.end());
    for(auto a : nums1)
    {
        if(binarySearch(nums2,a));
        res.insert(a);
    }
    return vector<int>(res.begin(),res.end());
}


int main()
{
    vector<int> num1 = {1,2,3,1};
    vector<int> num2 = {2,2};

    vector<int> ret;
    ret = InterSection3(num1,num2);
    vector<int>::iterator it = ret.begin();
    while(it != ret.end())
    {
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}
