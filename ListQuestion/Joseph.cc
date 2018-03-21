#include<list>
#include<iostream>

using namespace std;

int Joseph(unsigned int n,unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;

    unsigned int i = 0;

    //初始化数据
    list<int> numbers;
    for(i = 0;i < n;++i)
        numbers.push_back(i);

    list<int>::iterator current = numbers.begin();
    while(numbers.size() > 1){
        //每次走m步，如果走到结尾就从头开始
        for(unsigned int i = 1; i < m;++i){
           current++;
           if(current == numbers.end())
               current = numbers.begin();
        }

        //记录下一次开始节点
        list<int>::iterator next = ++current;
        if(next == numbers.end())
            next = numbers.begin();

        --current;
        numbers.erase(current);
        current = next;
    }

    return *(current);
}


/*
 *  采用数学归纳法可以得出递推公式
 *  f(n,m) = [f(n-1,m)+m]%n  n>1
 */

int JosephMath(unsigned int n,unsigned int m)
{
    if(n < 1 ||m < 1)
        return -1;

    int last = 0;
    for(unsigned int i = 2;i <= n;i++)
        last = (last + m)%i;

    return last;
}
