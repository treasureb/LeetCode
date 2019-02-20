#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    /*
     * 如果一个数出现了超过一半
     * 则排序后，中间值肯定为这个数
     * 使用了sort函数，所以时间复杂度为O(NlogN)
     */
    int morethan_half_num(vector<int> numbers){
        if(numbers.empty())
            return 0;

        sort(numbers.begin(),numbers.end());
        int middle = numbers[numbers.size()/2];

        int count = 0;
        for(int i = 0;i < (int)numbers.size();++i){
            if(numbers[i] == numbers[middle])
                ++count;
        }

        return (count > (int)numbers.size()/2)?middle:0;
    }    

    /*
     * 思路2:如果数组中有一个数的次数超过一半
     * 则该数字一定有两个相邻的出现
     * 然后采用抵销法
     */

    int morethan_half_num_counteract(vector<int> numbers){
        if(numbers.empty())
            return 0;

        int result = numbers[0];
        int count = 0;

        for(int i = 0;i < (int)numbers.size();++i){
            if(count == 0){
                //更新result的值为当前元素,并置次数为1
                result = numbers[i];
                count = 1;
            }else if(numbers[i] == result){
                //相同则加1
                ++count;
            }else{
                --count;
            }
        }
        //判断result是否符合条件,即出现的次数是否大于数组的一半
        count = 0;
        for(int i = 0;i < (int)numbers.size();++i){
            if(numbers[i] == result)
                ++count;
        }

        return (count > (int)numbers.size()/2)? result : 0;
    }

    /*
     *  采用快排的思想
     *  时间复杂度为O(N)
     */

    int morethan_half_quickSort(vector<int> numbers){
        int len = numbers.size();
        if(len < 0)
            return 0;
        
        int start = 0;
        int end = len - 1;
        int mid = len >> 1;
        int index = Partition(numbers,start,end);
        while(index != mid){
            if(index > mid){
                end = index - 1;
                index = Partition(numbers,start,end);
            }else{
                start = index + 1;
                index = Partition(numbers,start,end);
            }
        }
        int result = numbers[mid];
        if(!check_morethan_half(numbers,len,result))
            return 0;

        return result;
    } 
private:
    int Partition(vector<int> input,int low,int high){
        int key = input[high];
        while(low < high){
            while(low < high && key > input[low])
                ++low;
            input[high] = input[low];
            while(low < high && key < input[high])
                --high;
            input[low] = input[high];
        }
        input[low] = key;

        return low;
    }

    bool check_morethan_half(vector<int> numbers,int length,int result){
        int count = 0;
        for(int i = 0;i < length;++i){
            if(numbers[i] == result)
                count++;
        }
        bool is_morethan_half = true;
        if(count * 2 <= length)
            is_morethan_half = false;

        return is_morethan_half;
    }
};
