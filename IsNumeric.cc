#include<iostream>
#include<string.h>
using namespace std;


class Solution{
public:
    bool isNumber(char* str){
        //设置三个标记
        bool sign = false;      //符号
        bool decimal = false;   //小数点
        bool hasE = false;      //e

        for(size_t i = 0;i < strlen(str);++i){
            if(str[i] == 'e' || str[i] == 'E'){
                if(i == strlen(str)-1)      //e后面一定要接数字
                    return false;
                if(hasE)                    //不能出现两个e
                    return false;
                hasE = true;
            }else if(str[i] == '+' || str[i] == '-'){
                //第二次出现+ -号只能出现在e后面一个位置
                if(sign && str[i-1] != 'e' && str[i-1] != 'E')
                    return false;
                //第一次出现+ -号,并且不是在开头,则也必须跟在e后
                if(!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E')
                    return false;

                sign = true;
            }else if(str[i] == '.'){
                //e后面不能出现.,并且.不能出现两次
                if(hasE || decimal)
                    return false;
            }else if(str[i] < '0' || str[i] > '9')
                return false;
        }
        return false;
    }
};


bool scanUnsignedInteger(const char**);
bool scanInteger(const char**);

bool IsNumeric(const char* str)
{
    if(nullptr == str)
        return false;

    bool numeric = scanInteger(&str);
    //如果出现了.则接下来是小数部分
    if(*str == '.'){
        ++str;

        
        numeric = scanUnsignedInteger(&str)||numeric;
    }

    if(*str == 'e' || *str == 'E'){
        ++str;

        numeric = numeric && scanInteger(&str);
    }

    return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;
    while(**str != '\0' && **str >= '\0' && **str <= '9')
        ++(*str);

        return *str>before; 
}

bool scanInteger(const char** str)
{
    if(**str == '+' || **str == '-')
        ++(*str);

    return scanUnsignedInteger(str);
}
