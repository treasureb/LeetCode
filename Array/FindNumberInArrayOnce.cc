#include<iostream>

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


int main()
{
    int array[] = {1,1,1,3,3,3,5,5,5,6};
    int ret  = FindNumberInArrayOnce(array,sizeof(array)/sizeof(array[0]));
    std::cout<<ret   <<std::endl;
}
