#include<iostream>


/*
 *   没有处理一种特殊情况
 *   10111         11101
 *
 */

int RotateArrayMin(int* numbers,int length)
{
    if(nullptr == numbers || length <= 0)
        return -1;

    int left = 0;
    int right = length-1;
    int mid = left;
    while(numbers[left] >= numbers[right]){
        if(right - left == 1){
            mid = right;
            break;
        }
        mid = (left + right)/2;
        if(numbers[mid] >= numbers[left])
            left = mid;
        else if(numbers[mid] <= numbers[right])
            right = mid;
    }

    return numbers[mid];
}

/*
 *  如果当left mid right三个相同
 *  则需要顺序查找
 */


int MinInOrder(int* numbers,int left,int right)
{
    int result = numbers[left];
    for(int i = left +1;i <= right;++i){
        if(numbers[i] < result)
            result = numbers[i];
    }
    return result;
}

int RotateArrayMini(int* numbers,int length)
{
    if(nullptr == numbers || length <= 0)
        return -1;
    int left = 0;
    int right = length-1;
    int mid = left;
    while(numbers[left] >= numbers[right]){
        if(right - left == 1){
            mid = right;
            break;
        }

        mid = (left + right)/2;

        //处理特殊情况
        if(numbers[left] == numbers[right] && numbers[mid] == numbers[left])
            return MinInOrder(numbers,left,right);

        if(numbers[mid] >= numbers[left])
            left = mid;
        if(numbers[mid] <= numbers[right])
            right = mid;
    }
        return numbers[mid];
}
