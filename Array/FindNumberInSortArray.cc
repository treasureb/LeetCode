#include<iostream>
#include<vector>
using namespace std;

/*
 *  采用二分求出该数，但是两边还有可能是
 *  该数，如果采用从中间向两边遍历，时间
 *  复杂度还是O(N)
 *
 */


int GetFirstK(int* Data,int length,int k,int left,int right)
{
    if(left > right)
        return -1;

    int mid = (left + right)/2;
    int midData = Data[mid];
    if(midData == k){
        //判断是否为第一个K
        if((mid > 0 && Data[mid - 1] != k) || mid == 0)
            return mid;
        else
            right = mid - 1;
    }else if(midData > k){
        right = mid - 1;
    }else
        left = mid + 1;


    return GetFirstK(Data,length,k,left,right);    
}

int GetLastK(int* Data,int length,int k,int left,int right)
{
    if(left > right)
        return -1;

    int mid = (left + right)/2;
    int midData = Data[mid];

    if(midData == k){
        if((mid < length-1 && Data[mid+1] != k) || mid == length-1)
            return mid;
        else
            left = mid + 1;
    }else if(midData < k){
        left = mid + 1;
    }else
        right = mid - 1;

    return GetLastK(Data,length,k,left,right);
}

int GetNumberOfK(int* Data,int length,int k)
{
    int number = 0;
    if(nullptr != Data && length > 0){
        int first = GetFirstK(Data,length,k,0,length-1);
        int last = GetLastK(Data,length,k,0,length-1);

        if(first > -1 && last > -1)
            number = last-first+1;
    }

    return number;
}

class Solution{
public:
    int GetNumberOfK(vector<int> data,int k){
        int lower = get_lower(data,k);
        int upper = get_upper(data,k);

        return upper - lower + 1;
    }

    int get_lower(vector<int> data,int k){
        int start = 0;
        int end = data.size()-1;
        int mid = (start+end)/2;

        while(start <= end){
            if(data[mid] < k){
                start = mid+1;
            }else{
                end = mid-1;
            }
            mid = (start+end)/2;
        }
        return start;
    }

    int get_upper(vector<int> data,int k){
        int start = 0;
        int end = data.size()-1;
        int mid = (start+end)/2;

        while(start <= end){
            if(data[mid] <= k){
                start = mid+1;
            }else{
                end = mid-1;
            }
            mid = (start+end)/2;
        }
        return end;
    }
};

int main()
{
    Solution s;
    vector<int> v = {1,2,3,4,4,4};
    int ret = s.GetNumberOfK(v,4);
    cout<<ret<<endl;
    return 0;
}
