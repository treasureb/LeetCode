#include<iostream>

using namespace std;

/* 题目描述:不使用+ - * / 计算前n项和 */
/* 1. 采用gcc特性，开辟多维数组，使用sizeof求解 */
/* 2. 利用构造函数，然后定义n的对象的数组 */
/* 3. 利用虚函数 */
/* 4. 利用函数指针 */

/* 1. 采用gcc特性，开辟多维数组，使用sizeof求解 */
int sum_n(int n){

    /* 采用公式n*(n-1)/2求解 */ 
    int a[n][n+1];
    return sizeof(a) >> 1;
}

/* 2. 利用构造函数，然后定义n的对象的数组 */
class Tmp{
public:
    Tmp(){
        ++N;
        Sum += N;
    }

    static void Reset(){
        N = 0;
        Sum = 0;
    }

    static unsigned int GetSum(){
        return Sum;
    }
private:
    static unsigned int N;
    static unsigned int Sum;
};


/* 3. 利用虚函数 */
class A;
A* Array[2];

class A{
public:
    virtual unsigned int Sum(unsigned int n){
        return 0;
    }
};

class B : public A{
public:
    virtual unsigned int Sum(unsigned int n){
        return Array[!!n]->Sum(n-1) + n;
    }
};

int Sum2(int n){
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;

    int value = Array[1]->Sum(n);
    return value;
}



/* 4. 利用函数指针 */
typedef unsigned int (*fun) (unsigned int);

unsigned int Sum3_Teminator(unsigned int n){
    return 0;
}

unsigned int Sum3(unsigned int n){
    static fun f[2] = {Sum3_Teminator,Sum3};
    return n + f[!!n](n-1);
}
