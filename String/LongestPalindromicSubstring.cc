#include <string>
using namespace std;

class Solution{
    string palindromic_substring(string s){
        if(s.size() < 2)
            return s;
    
        int size = s.size();
        int max_len = 0;
        int start = 0;
    
        for(int i = 0;i < size-1;++i){
            helper(s,i,i,start,max_len);
            helper(s,i,i+1,start,max_len);
        }

        return s.substr(start,max_len);
    }
        
    void helper(string s,int left,int right,int& start,int& max_len){
         while(left >= 0 && right < (int)s.size() && s[left] == s[right]){
            --left;
           ++right;
        }
        
        if(max_len < right - left - 1){
            start = left + 1;
            max_len = right - left - 1;
        }
    }    
};
