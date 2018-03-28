#include<iostream>
using namespace std;


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
