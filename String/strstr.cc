#include<iostream>
#include<string>

class Solution
{
public:
    int strstr(std::string haystack,std::string needle)
    {
        size_t m = haystack.size();
        size_t n = needle.size();
        
        for(size_t i = 0; i < m-n+1;++i){
            bool flag = true;
            for(size_t j = 0;j < n;++j){
                if(haystack[i+j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
               return i;
        }
        return -1;
    }
};
