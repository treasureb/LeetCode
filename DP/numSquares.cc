#include<iostream>
#include<stdint.h>
#include<vector>

using namespace std;

/* 解题思路: */
/*     1. 开辟一个辅助数组,保存前面每个数最少可有几个数的平方组成 */
/*     2. 当前数字是有它前一个数字加1组成的 */
/*     3. 一次迭代当前减去j*j */

int numSquares(int n){
    if(n == 0) return 0;

    vector<int> vec(n+1,INT32_MAX);
    vec[0] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j*j <= i;j++)
            vec[i] = min(vec[i],vec[i-j*j] + 1);
    }
    return vec[n];
}

int main(){
    int num;
    cin>>num;
    int res = numSquares(num);
    cout<<res<<endl;
    return 0;
}
