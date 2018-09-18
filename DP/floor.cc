#include<iostream>
#include<vector>

using namespace std;

int floor(int n){
    vector<int> dp(n+1,0);
    for(int i = 2;i <= n;++i){
        dp[i] = i;
        for(int j = 1;j < i;++j){
            dp[i] = min(max(j,1 + dp[i-j]),dp[i]);
        }
    }
    return dp[n];
}

int main(){
    int num;
    cin>>num;
    int res = floor(num);
    cout<<res<<endl;
}
