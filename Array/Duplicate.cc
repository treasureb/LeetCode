#include<iostream>

class Solution{
    bool duplicate(int numbers[],int length,int* duplicate){
        if(length <= 0)
            return false;

        for(int i = 0;i < length;++i){
            int index = numbers[i];

            //超过length,说明是该下标的数已经出现一次
            if(index >= length)
                index -= length;

            //说明值为index的数已经出现过一次了
            if(numbers[index] >= length){
                duplicate[0] = index;
                return true;
            }
            numbers[index] = numbers[index] + length;
        }
        return false;
    }
};
