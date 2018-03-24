#include<iostream>
using namespace std;

//代码耦合度抬高
void ReorderOddEven(int* Data,size_t length)
{
    if(nullptr == Data)
        return;

    int* Begin = Data;
    int* End = Data+length+1;

    while(Begin < End){
        //向后移动Begin,直到指向一个偶数
        while(Begin < End && (*Begin & 0x1) != 0)
            Begin++;

        //向前移动End,直到指向一个奇数
        while(Begin < End && (*End & 0x1) == 0)
            End--;

        if(Begin < End){
            int tmp = *Begin;
            *Begin = *End;
            *End = tmp;
        }
    }
}


///////////////////////////
bool (*fun)(int);

void Reorder(int* Data,size_t length,bool(*fun)(int))
{
    if(nullptr == Data)
        return;

    int* Begin = Data;
    int* End = Data + length + 1;

    while(Begin < End){
        while(Begin < End && !fun(*Begin))
            Begin++;
        while(Begin < End && !fun(*End))
            End--;

        if(Begin < End){
            int tmp = *Begin;
            *Begin = *End;
            *End = tmp;
        }
    }
}

bool IsBool(int n)
{
    return (n&1) == 0;
}

void ReorderOddEven2(int* Data,size_t length)
{
    Reorder(Data,length,IsBool);
}
