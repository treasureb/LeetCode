#include<iostream>

using namespace std;

//计算最右边是1的位
unsigned int FindFirstBitIs1(int num)
{
    size_t indexBit = 0;
    while(((num & 1) == 0) && (indexBit < 8 * sizeof(int))){
        num = num >> 1;
        ++indexBit;
    }
    return indexBit;
}

//判断某一位是否为1
bool IsBit1(int num,unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}

void FindNumsAppearOnce(int data[],int length,int* num1,int* num2)
{
    if(nullptr == data || length < 2)
        return;

    int resultExelusiveOR = 0;
    //先将整个数组中的数都进行异或
    for(int i = 0;i < length;++i)
        resultExelusiveOR ^= data[i];
    
    //找到最右边是1的一位
    unsigned int indexOf1 = FindFirstBitIs1(resultExelusiveOR);

    //将相同的数都分到同一组，两个只出现一次的分别在两个组
    *num1 = *num2 = 0;
    for(int j = 0;j < length;++j){
        //两个数组在各自进行异或，最后只剩下两个只出现一次的数
        if(IsBit1(data[j],indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}
