#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int StrToInt(string str){
        long long ret = 0;
        int size = str.size();
        bool flag = false;
        for(int i = 0;i < size;++i){
            if(str[i] >= '0' && str[i] <= '9'){
                //一个字符减去'0',是将其转化为数字
                ret = ret * 10 + (str[i] - '0');
                //'-'号只能出现在第一位。
            }else if(str[i] == '-' && i == 0){
                flag = true;
                //非法输入
            }else if((str[i] <'0' || str[i] > '9') && i!=0)
                return 0;
        }
        if(flag)
            ret = -ret;
        return ret;
    }
};
