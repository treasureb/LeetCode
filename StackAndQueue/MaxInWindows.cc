#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> MaxInWindows(vector<int> num,size_t size)
{
    vector<int> maxInWindows;//保存滑动窗口中最大的值
    if(num.size() >= size && size >= 1){
        deque<int> index;

        //先往双端队列中插入第一个滑动窗口的最大值
        for(size_t i = 0; i < size;++i){
            while(!index.empty() && num[i] >=num[index.back()])
                index.pop_back();

            index.push_back(i);
        }

        for(size_t i = size;i < num.size();++i){
            maxInWindows.push_back(num[index.front()]);

            //比较下一个进滑动窗口的数是否可能是最大值
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();

            //判断是否滑出滑动窗口
            if(!index.empty() && index.front() <= (int)(i-size))
                index.pop_front();

            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }

    return maxInWindows;
}

int main()
{
    vector<int> v={2,3,4,2,6,2,5,1};
    vector<int> ret;
    ret = MaxInWindows(v,3);
    vector<int>::iterator it = ret.begin();
    while(it != ret.end()){
        cout<<*it<<" ";
        ++it;
    }
    cout<<endl;
    return 0;
}
