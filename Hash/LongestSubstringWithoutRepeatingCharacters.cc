#include <string>
#include <unordered_map>
using namespace std;

int LongestrSubstring(string s){
    if(s.empty())
        return 0;
    
    unordered_map<char,int> m;
    int max_len = 0;
    int left = -1;  //维护滑动窗口的左边界

    for(int i = 0;i < (int)s.size();++i){
        if(m.count(s[i]) && m[s[i]] > left)
            left = m[s[i]]; //出现重复，则更新滑动窗口左边界

        m[s[i]] = i;
        max_len = max(max_len,i-left);
    }

    return max_len;
}
