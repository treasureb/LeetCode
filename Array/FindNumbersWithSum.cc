#include<iostream>
#include<vector>

using namespace std;

bool FindNumbersWithSum(int data[],int length,int sum,int* num1,int* num2)
{
    bool found = false;
    if(length < 1 || num1 == nullptr || num2 == nullptr)
        return found;

    int ahead = length-1;
    int behind = 0;

    while(ahead > behind){
        long long curSum = data[ahead] + data[behind];
        //找到直接返回
        if(curSum == sum){
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
            //如果大于，则将后面较大的数向前挪动
        }else if(curSum > sum)
            ahead--;
        else
            behind++;
    }

    return found;
}

class Solution{
public:
    vector<int> FindNumbersWithSum(vector<int> numbers,int target){
        int len = numbers.size();
        int start = 0;
        int end = len - 1;
        
        vector<int> res;
        while(start <= end){
            if((numbers[start]+numbers[end]) == target){
                res.push_back(numbers[start]);
                res.push_back(numbers[end]);
                return res;
            }else if((numbers[start]+numbers[end]) < target){
                ++start;
            }else{
                --end;
            }
        }

        return res;
    } 
};
