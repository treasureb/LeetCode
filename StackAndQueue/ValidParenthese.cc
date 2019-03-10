#include<iostream>
#include<string>
#include<stack>

/* 解题思路: */
/*     1. 如果字符串为奇数个直接返回false */
/*     2. 如果是左括号直接入栈 */
/*     3. 如果是右括号则判断栈顶是否是相匹配得括号 */


using namespace std;
class Solution{
public:
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
