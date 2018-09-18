#include<iostream>

using namespace std;

/*
题目描述:
    有n封信，需要放在n个邮筒里，假如要全部放错，共有多少种放法

解题思路:
    1. 放第一封信共有(n-1)种放法
    2. 如果第一封放在key位置，且key位置的也放在第一封的位置，则剩下f(n-2)
    3. 若key位置没有放在第一封的位置，则剩下f(n-1)
*/

long envelope(int n){
    if(n == 1) return 0;
    if(n == 2) return 1;

    return (n-1)*(envelope(n-1) + envelope(n-2));
}

int main(){
    int number;
    cin>>number;
    long res = envelope(number);
    cout<<res<<endl;
    return 0;
}
