#include "Tree.h"
#include <vector>

/* 解题思路: */
/*     1. 本题符合卡特兰式表达式,采用DP的思想 */
/*     2. f(n) = f(i)*f(n-i) */
/*     3. 类似的题目还有n个数的出栈顺序 */

class Solution{
    int numTrees(int n){
        std::vector<int> dp(n+1,0);
        dp[0] = 1;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= i;++j)
                dp[i] = dp[i] + dp[j-1] * dp[i-j];
        }

        return dp[n];
    }
};
