#include <vector>
#include <string>
using namespace std;

/* 解题思路: */
/*     1. left和right表示左右括号的个数 */
/*     2. 递归进行处理 */

class Solution{
    vector<string> GenerateParenthese(int n){
        vector<string> res;
        helper(n,n,"",res);
        return res;
    }

    void helper(int left,int right,string out,vector<string>& res){
        if(left > right)    //出现右括号比左括号多 
            return;
        if(left == 0 && right == 0)
            res.push_back(out);
        else{
            if(left > 0)  helper(left-1,right,out+'(',res);
            if(right > 0) helper(left,right-1,out+')',res);
        }
    }
};
