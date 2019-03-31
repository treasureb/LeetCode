#include<stdio.h>
#include<string.h>
#include<string>
#include<assert.h>
using namespace std;

class Solution{
    string reverse_str(string str){
        string res = "";
        string tmp = "";

        for(size_t i = 0;i < str.size();++i){
            if(str[i] == ' '){
                res = " " + tmp + res;
                tmp = "";
            }else{
                tmp += str[i];
            }
        }
        if(tmp.size())
            res = tmp + res;
        return res;
    } 
};
