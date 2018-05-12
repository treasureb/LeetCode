#include<iostream>
#include<vector>

using namespace std;
int FindNumberInArrayOnce(int numbers[],int length)
{
    if(nullptr == numbers || length <= 0)
       std:: cout<<"Invalid Input"<<std::endl;

    int bitSum[32] = {0};
    for(int i = 0;i < length;++i)
    {
        int bitMask = 1;
        //将一个数的所有位都加到辅助数组中
        for(int j = 31;j >= 0;--j){
            //bit位是否位1
            int bit = numbers[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;
            
            bitMask = bitMask << 1;
        }
    }
    
    //是否可以被3整出，从而判断0/1
    int result = 0;
    for(int i = 0;i < 32;++i){
        result = result << 1;
        result += bitSum[i] % 3;
    }
    return result;
}


class Solution{
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int* num2){
        if(data.size() < 2)
            return;

        int size = (int)data.size();
        //先将所有数都进行异或
        //则结果是单独出现两数的异或
        int temp = data[0];
        for(int i = 1;i < size;i++){
            temp = temp^data[i];
        }
        if(temp == 0)
            return;
        int index = 0;
        //找出最低位为1的位置
        while((temp&1) == 0){
            temp = temp>>1;
            ++index;
        }
        //按照该位是否位1,将原数组分为两部分
        //两个单独出现的数各自在一边
        *num1 = *num2 = 0;
        for(int i = 0;i < size;i++){
            if(is_bit(data[i],index))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }

    bool is_bit(int num,int index){
        num = num>>index;
        return (num&1);
    }
};
