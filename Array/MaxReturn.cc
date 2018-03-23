#include<iostream>
#include<vector>

using namespace std;

int MaxReturn(vector<int> numbers)
{
    if(numbers.size() < 2)
        return 0;

    int min = numbers[0];
    int MaxReturn = numbers[1] - min;

    for(size_t i = 2;i < numbers.size();++i){
        //更新最小的买进价
        if(numbers[i-1] < min)
            min = numbers[i-1];

        //计算当前的利润，然后比较最大的利润
        int currentReturn = numbers[i] - min;
        if(currentReturn > MaxReturn)
            MaxReturn = currentReturn;
    }

    return MaxReturn;
}
