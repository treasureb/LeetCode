#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


/* 解题思路: */
/*     1. dp数组记录区间[0,j)是否可以分割成为单词 */
/*     2. 后半段为s.substr(j,i-j) */

class Solution{
public:
    bool WordBreak(string& s,vector<string>& dict){
        unordered_set<string> wordset(dict.begin(),dict.end());
        vector<bool> dp(s.size()+1);
        dp[0] = true;

        for(size_t i = 0;i < dp.size();++i){
            for(size_t j = 0;j < i;++j){
                if(dp[j] && wordset.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp.back();
    }
};
