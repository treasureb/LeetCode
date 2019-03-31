#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    /*
     * 采用全排列的方法 
     * O(NlogN)
     */

    vector<int> GetLeastNumbers_Sort(vector<int> numbers,size_t k){
        vector<int> res;
        if(numbers.empty() || k > numbers.size())
            return res;

        sort(numbers.begin(),numbers.end());

        for(int i = 0;i < (int)k;i++){
            res.push_back(numbers[i]);
        }
        return res;
    }

    /*
     * 采用堆的方式来求解TopK问题
     * O(NlogN),适合海量数据运算，因为不用一次性加载进内存
     */

    vector<int> GetLeastNumbers_Heap(vector<int> input,int k){
        int len = input.size();
        if(len <= 0 || k > len)
            return vector<int>();

        //建堆
        vector<int> res(input.begin(),input.begin()+k);
        make_heap(res.begin(),res.end());

        for(int i = k;i < len;++i){
            if(input[i] < res[0]){
                //这里一定要注意次数
                pop_heap(res.begin(),res.end());
                res.pop_back();

                res.push_back(input[i]);
                push_heap(res.begin(),res.end());
            }
        }

        //使其从小到大输出
        sort_heap(res.begin(),res.end());

        return res;
    }

    /*
     * 采用快排的思想
     * 以
     *
     */
    vector<int> GetLeastNumbers_QuickSort(vector<int> input,int k){
        int len = input.size();
        if(len <= 0 || k > len)
            return vector<int>();
        if(len == k)
            return input;

        int start = 0;
        int end = len-1;
        int index = Partition(input,start,end);
        while(index != (k-1)){
            if(index > (k-1)){
                end = index-1;
                index = Partition(input,start,end);
            }else{
                start = index+1;
                index = Partition(input,start,end);
            }
        }

        vector<int> res(input.begin(),input.begin()+k);

        return res;
    }
  
private:
    //挖坑法
    int Partition(vector<int>& input,int begin,int end){
        int low = begin;
        int high = end;

        int key = input[low];
        while(low < high){
            while(low < high && key <= input[high])
                high--;
            input[low] = input[high];
            while(low < high && key >= input[low])
                low++;
            input[high] = input[low];
        }
        input[low] = key;
        return low;
    }

};


int main(){
    vector<int> v = {4,2,7,1,8,3,9,5,6};
    Solution s;
    vector<int> res = s.GetLeastNumbers_Heap(v,5);
    for(int i = 0;i < (int)res.size();++i){
        cout<<res[i]<<" "<<endl;
    }
    return 0;
}
