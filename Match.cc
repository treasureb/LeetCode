#include<iostream>
bool MatchCore(char*,char*);
bool Match(char* str,char* pattern)
{
    if(nullptr == str || nullptr == pattern)
        return false;

    return MatchCore(str,pattern);
}

bool MatchCore(char* str,char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern + 1) == '*'){
        if(*pattern == *str || (*pattern == '.' && (*str) != '\0'))
            //move on the next state
            return MatchCore(str+1,pattern+2)
            //stay on the current state
            ||MatchCore(str+1,pattern)
            //ignore a'*'
            ||MatchCore(str,pattern+2);
        else
            //ignore a'*'
            return MatchCore(str,pattern+2);
    }

    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return MatchCore(str+1,pattern+1);

    return false;
}

