#include<iostream>

using namespace std;


/*
 * 第一种思路，利用构造函数进行运算
 * 然后调用N次构造函数即可。
 */

class Temp
{
public:
    Temp()
    {
        ++N;
        Sum += N;
    }

    static void Reset()
    {
        N = 0;
        Sum = 0;
    }

    static unsigned GetSum()
    {
        return Sum;
    }
    
    //使用static成员变量，所有该类的对象共用一份
    static unsigned int N;
    static unsigned int Sum;
};

unsigned int Sum_Solution1(unsigned int n)
{
    Temp::Reset();
    Temp* a = new Temp[n];
    delete[] a;
    a = nullptr;

    return Temp::GetSum();
}

/*
 * 既然不能通过if判断递归的出口，
 * 则使用虚函数和(!！n)配合
 * 1.当n不为0一直调用子类，一直求和
 * 2.当n为0，则调用父类，函数返回。
 *
 */


//使用数组保存子类和父类的指针，从而通过控制n来控制父类和子类的调用
class A;
A* Array[2];

class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};

class B:public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        //只要n不为0，一直调用子类函数，当n=0,调用父类然后返回
        return Array[!!n]->Sum(n-1)+n;
    }
};

int Sum_Solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);

    return value;
}


/*
 *  既然虚函数可以解决
 *  那么可以使用函数指针
 */

typedef unsigned int(*fun)(unsigned int);

unsigned int Solution3_Teminator(unsigned int n)
{
    return 0;
}

unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] ={Solution3_Teminator,Sum_Solution3}; 
    return n+f[!!n](n-1);
}



/*
 * 利用函数模板类型求解
 *
 */

template <unsigned int n>
struct Sum_Solution4
{
    enum Value
    {
        N = Sum_Solution4<n-1>::N+n
    };
};

template<>
struct Sum_Solution4<1>
{
    enum Value
    {
        N = 1
    };
};
