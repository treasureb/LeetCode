#include<iostream>
#include<vector>
using namespace std;

bool Duplicate(vector<int> v)
{
    if(v.size() < 1)
        return false;
   
    //判断输入合法性
    for(size_t i = 0;i < v.size();i++)
    {
        if(v[i] < 0 || v[i] > (int)v.size())
            return false;
    }

    for(size_t i = 0;i < v.size();i++)
    {
        while(v[i] != (int)i)
        {
            if(v[i] == v[v[i]])
                return true;

            swap(v[i],v[v[i]]);
        }
    }
    
    return false;
}

int CountRange(vector<int> v,size_t start,size_t end)
{
    int count = 0;
    for(size_t i = 0;i < v.size();i++)
    {
        if(v[i] > (int)start && v[i] < (int)end)
            ++count;
    }
    return count;
}

int GetDuplication(vector<int> v)
{
    if(v.size() < 1)
        return -1;

    size_t start = 0;
    size_t end = v.size();
    while(start < end)
    {
        size_t mid = ((end - start) >> 1)+start;
        int count = CountRange(v,start,end);
        if(end == start)
        {
            if(count > 1)
                return start;
            else
                break;
        }

        if(count > (int)(mid - start + 1))
            end = mid;
        else
            start = mid + 1;
    }
    return -1;
}


void Test()
{
    vector<int> v = {3,0,1,2,2};
    cout<<Duplicate(v)<<endl;
}

int main()
{
    Test();
    return 0;
}
