#include <vector>
using namespace std;

/* 解题思路: */
/* 1. 数组阶段有序，所以采用二分的思想 */
/* 2. 处理特殊情况，数组只有两个数和771777等 */

class Solution{
    int min_number_rotate_array(vector<int> numbers){
        int size = numbers.size();
        if(size <= 0)
            return 0;

        int start = 0,mid = 0;
        int end = size - 1;
        while(numbers[start] >= numbers[end]){
            if(1 == mid - start){   //序列中只有两个数的场景
                mid = end;
                break;
            }

            mid = start + ((end - start) >> 1);
            if(numbers[start] == numbers[mid] == numbers[end]){
                //如果三个位置上的数都相等,即771777这种特殊情况,则需要顺序查找
                return helper(numbers,start,end);
            }

            if(numbers[mid] >= numbers[start])
                start = mid;
            if(numbers[mid] <= numbers[end])
                end = mid;
        }

        return numbers[mid];
    }

    int helper(vector<int> numbers,int start,int end){
        int res = numbers[start];
        for(int i = start + 1;i < end;++i){
            if(numbers[i] < res)
                res = numbers[i];
        }

        return res;
    }


};
