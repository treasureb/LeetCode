#include<ostream>

using namespace std;

//先暴力判断一个数是不是丑数
bool IsUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;

    return (number == 1)?true:false;
}

//一次判断一个数是不是丑数
int GetUglyNumber(int index)
{
    if(index <= 0)
        return 0;

    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index){
        ++number;

        if(IsUgly(number))
            ++uglyFound;
    }

    return number;
}

/////////////////////////////////////


//上面那种做法大量的时间放在判断那些不是丑数的数身上

/*
 * 思路：当前丑数的下一个丑数必为前面丑数2 3 5而来
 *      1.只需判断大于当前丑数的最小丑数即可
 *
 */
int Min(int,int,int);

int GetUglyNumber2(int index)
{
    if(index <= 0)
        return 0;
    
    //辅助空间保存当前的所有丑数
    int* UglyNumber = new int[index];
    UglyNumber[0] = 1;
    int nextUglyIndex = 1;

    int* Multiply2 = UglyNumber;
    int* Multiply3 = UglyNumber;
    int* Multiply5 = UglyNumber;

    while(nextUglyIndex < index){
        //在三个数各自的丑数中选最小的
        int min = Min(*Multiply2 * 2,*Multiply3 * 3,*Multiply5 * 5);
        UglyNumber[nextUglyIndex] = min;

        //寻找由2产生的大于当前丑数的第一个丑数
        while(*Multiply2 * 2 <= UglyNumber[nextUglyIndex])
            ++Multiply2;
        //寻找由3产生的大于当前丑数的第一个丑数
        while(*Multiply3 * 3 <= UglyNumber[nextUglyIndex])
            ++Multiply3;
        //寻找由5产生的大于当前丑数的第一个丑数
        while(*Multiply5 * 5 <= UglyNumber[nextUglyIndex])
            ++Multiply5;

        ++nextUglyIndex;
    }

    int ugly = UglyNumber[nextUglyIndex - 1];
    delete[] UglyNumber;
    return ugly;
}

int Min(int number1,int number2,int number3)
{
    int min = (number1 < number2)?number1:number2;
    min = (min < number3)?min:number3;

    return min;
}
