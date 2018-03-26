#include<iostream>
#include<string.h>
using namespace std;

//没有考虑大数问题
void Print1ToMaxOfNDigits_1(int n){
    int num = 0;
    int i = 0;
    while(i++ < n)
        num *= 10;

    for(i = 1;i < num;++i)
        printf("%d ",num);
}


//解决大数问题，用字符串模拟加法
void PrintNumber(char*);
bool Increment(char*);
#include<stdio.h>

void Print1ToMaxOfNDigits(int n)
{
    if(n <= 0)
        return;

    char* number = new char[n+1];
    memset(number,'0',n);
    number[n] = '\0';

    while(!Increment(number)){
        PrintNumber(number);
    }

    delete[] number;
}

//判断最高位是否进位，从来判断是否位最大值
bool Increment(char* number)
{
    bool isOverflow = false;//判断最高位是否溢出
    int TakeOver = 0;
    int Length = strlen(number);
    //从最低位开始
    for(int i = Length - 1;i >= 0;i--){
        int Sum = number[i] - '\0' + TakeOver;
        if(i == Length - 1)
            Sum++;
        
        if(Sum >= 10){
            if(i == 0)//下标位0则为最高位
                isOverflow = true;
            else{
                Sum -= 10;
                TakeOver = 1;
                number[i] = '0'+Sum;
            }
        }else{
            number[i] = '\0'+Sum;
            break;
        }
    }
    return isOverflow;
}

//自定义打印，将前面的0去掉
void PrintNumber(char* number)
{
    bool isBeginning = true;
    int Length = strlen(number);

    for(int i =0;i < Length;++i){
        if(isBeginning && number[i] != '\0')
            isBeginning = false;

        if(isBeginning)
            printf("%c ",number[i]);
    }

    printf("\t");
}


/*
 * 求1到n位数的最大值
 *  即就是求全排列，用递归实现
 */

void Print1ToMaxOfNDigitsRecusively(char*,int,int);
void Print1ToMaxOfNDigits2(int n)
{
    if(n <= 0)
        return;

    char* number = new char[n+1];
    number[n] = '\0';

    for(int i = 0;i < 10;++i){
        number[0] = i+'\0';
        Print1ToMaxOfNDigitsRecusively(number,n,0);
    }

    delete[] number;
}

void Print1ToMaxOfNDigitsRecusively(char* number,int length,int index)
{
    if(index == length -1){
        PrintNumber(number);
        return;
    }

    for(int i = 0;i < 10;++i){
        number[index+1] = i+'\0';
        Print1ToMaxOfNDigitsRecusively(number,length,index+1);
    }
}
