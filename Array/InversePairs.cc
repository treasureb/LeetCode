#include<iostream>

int InversePairsCore(int* data,int* copy,int start,int end)
{
    if(start == end){
        copy[start] = data[start];
        return 0;
    }

    //采用归并排序
    int length = (end-start)/2;
    int left = InversePairsCore(copy,data,start,start+length);
    int right = InversePairsCore(copy,data,start+length+1,end);

    //i初始化为前半段最后一个数字的下标
    int i = start + length;
    //j初始化为后半段最后一个数字的下标
    int j = end;

    int indexCopy = end;
    int count  = 0;
    while(i >= start && j >= start+length+1){
        //大于另一个数字的最大值，则剩下的都可以构成逆序对
        if(data[i] > data[j]){
            copy[indexCopy] = data[i--];
            count += j - start - length;
        }else{//反之直接将第二个数组中的最大值放去辅助空间
            copy[indexCopy--] = data[j--];
        }
    }

    //第一个数组还没走完，全部直接拷贝 
    for(;i >= start;--i)
        copy[indexCopy--] = data[i];

    for(;j >= start+length+1;++j)
        copy[indexCopy--] = data[j];

    return left+right+count;
}

int ReversePairs(int *data,int length)
{
    if(nullptr == data || length < 0)
        return 0;

    //辅助空间
    int* copy = new int[length];
    for(int i = 0;i < length;++i)
        copy[i] = data[i];

    int count = InversePairsCore(data,copy,0,length-1);
    delete[] copy;

    return count;
}
