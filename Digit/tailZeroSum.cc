#include<iostream>
#include<cstdio>
using namespace std;

/*
 * 求n!末尾0的个数
 * 1. 0只能由2 * 5得到
 * 2. 2的个数大于5的个数,故求5的个数即可
 *
 */
int helper(int n){
    int res = 0;
    while(n >= 5 && n %5 == 0){
        ++res;
        n /=5;
    }
    return 0;
}

int main( void ){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 5;i <= n;i+=5){
        sum += helper(n);
    }
    cout<<sum;
    return 0;
}
