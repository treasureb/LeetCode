#include<stdio.h>
#include<string.h>
#include<string>
#include<assert.h>
using namespace std;

void reverse_str(char* left,char* right)
{
    assert(left);
    assert(right);
    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

char* Reverse(char* str)
{
    assert(str);
    int len = strlen(str);
    char* start = str;
    char* end = NULL;
    char* ret = str;
    //runreverse_str(str,str+len-1);
    while(*str)
    {
        start = str;
        while((*str != ' ') && (*str != '\0'))
        {
            str++;
        }
        end = str -1;
        reverse_str(start,end);
        if(*str == ' ')
            str++;
    }
    return ret;
}

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
