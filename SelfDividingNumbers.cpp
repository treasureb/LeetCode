#include<iostream>
#include<vector>
using namespace std;

bool Valid(int value)
{
    int key = value;
    while(value)
    {
        if(value % 10 == 0)
            return false;
        if(key % (value%10))
            return false;

        value /= 10;
    }
    return true;
}

vector<int> SelfDividingNumbres(int left,int right)
{
    if(left < 1 || right > 10000 || left > right)
        cout<<"Enter Error"<<endl;
    
    vector<int> v;
    for(int i = left;i <= right; ++i)
    {
        if(Valid(i))
        v.push_back(i);
    }
    return v;
}


int main()
{
    int left = 1;
    int right = 22;
    vector<int> v;
    v = SelfDividingNumbres(left,right);
    for(int i = 0;i < v.size();++i)
    {
         cout<<v[i]<<" ";
    }
    cout<<endl;
    
    vector<int>::iterator it = v.begin();
    while(it != v.end())
    {
        cout<<(*it)<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}
