#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

bool my_next_permutation(int* str,int length)
{
    if(nullptr == str)
        return false;

    int i = 0;
    for(i = length-2;i >= 0;--i){
        if(str[i] < str[i+1])
            break;
    }
    //最小的一个数是最高位，已经没有最下的数
    if(i == 0)
        return false;

    int j = i+1;
    //找到该位置后第一个小于该数的数
    while(str[j] > str[i])
        ++j;
    swap(str[i],str[j-1]);
    sort(str+i+1,str+length);
    return true;

}

int main()
{
    int str[] = {1,2,3,4};
    bool result = my_next_permutation(str,sizeof(str)/sizeof(str[0]));
    for(size_t i = 0;i < sizeof(str)/sizeof(str[0]);++i){
        if(*str != '\0')
            cout<<str[i]<<" ";
    }
    return 0;
}
