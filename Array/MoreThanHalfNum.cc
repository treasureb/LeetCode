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
            if(numbers[i] == middle)
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
        int count = 1;

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
};
