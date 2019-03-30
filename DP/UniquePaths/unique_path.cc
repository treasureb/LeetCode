#include <vector>
using namespace std;

/* 解题思路: */
/*     1. 当前位置的路径数是左边和上边位置的总和 */
/*     2. 利用DP保存前面的结果 */

class Solution{
public:
    int UniquePaths(int m,int n){
        if(m < 1 || n < 1)
            return 0;

        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i = 1;i < m;++i){
            for(int j = 1;j < i;++j){
                dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
            }
        }

        return dp[m-1][n-1];
    }
};
