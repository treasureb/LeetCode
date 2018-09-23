#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


/* 题目描述: */
/*     1. 抓五张牌,判断是否是顺子 */
/*     2. 0代表王,可以替代任何数 */

bool is_continuous(vector<int> numbers){
    if(numbers.size() != 5)
        return false;

    sort(numbers.begin(),numbers.end());
    int i = 0;
    while(numbers[i] == 0) i++;
    if(numbers[4] - numbers[i] > 4)     //中间相差的个数超过王的数量
        return false;

    for(int j = i;j < 4;++j){           //除王之外的其他数出现两次
        if(numbers[j] == numbers[j+1])
            return false;
    }

    return true;
}
