#include<iostream>

class Solution{
    bool duplicate(int numbers[],int length,int* duplicate){
        if(length <= 0)
            return false;

        for(int i = 0;i < length;++i){
            int index = numbers[i];
            if(index >= length)
                index -= length;
            if(numbers[index] >= length){
                duplicate[0] = index;
                return true;
            }
            numbers[index] = numbers[index] + length;
        }
        return false;
    }
};
