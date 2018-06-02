#include<iostream>
#include<string>
#include<stack>

using namespace std;
class Solution{
public:
    /*
     * 括号的匹配
     *
     */
    bool isValid(std::string s){
        size_t length = s.size();
        if(length % 2 == 1)
            return false;

        stack<char> st;
        for(size_t i = 0;i < length;++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                char top = st.top();
                switch(s[i]){
                case ')':
                    if(top != '(')
                        return false;
                    break;
                case ']':
                    if(top != '[')
                        return false;
                    break;
                case '}':
                    if(top != '{')
                        return false;
                    break;
                default:
                    break;
                }
                st.pop();
            }

        }
        return st.empty();
    }
};
