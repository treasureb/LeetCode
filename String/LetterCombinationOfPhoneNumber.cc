#include <vector>
#include <string>
using namespace std;

class Solution{
    vector<string> letter_combination(string digits){
        if(digits.empty())
            return {};

        vector<string> res;
        string dict[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        helper(digits,dict,0,"",res);

        return res;
    }

    void helper(string digits,string dict[],int level,string out,vector<string>& res){
        if(level == (int)digits.size()){
            res.push_back(out);
            return;
        }
        string str = dict[digits[level] - '0']; //这里定义为string保存字符是后面方便直接拼接
        for(int i = 0;i < (int)str.size();++i){
            helper(digits,dict,level+1,out+string(1,str[i]),res);
        }
    }
};
