#include <string>
#include <climits>
#include <unordered_map>

using  namespace std;


/* 解题思路: */
/*     1. 先将子串全部放入map中,以备后续判断其是否出现 */
/*     2. 当子串中的字母在待查找串中出现则计数器++ */
/*     3. 当计数器的值等于子串长度说明子串中的字母已经全部出现 */
/*     4. 判断是否需要更新窗口的大小 */
/*     5. 窗口滑动是判断是否失去一个子串中出现的字符 */

class Solution{
    string wondow_substr(string s,string t){
        string res;
        int left = 0,cnt = 0,min_len = INT_MAX;
        unordered_map<char,int> u;
        for(auto c : t)
            ++u[c];
        for(int i = 0;i < (int)s.size();++i){
            if(--u[s[i]] >= 0)
                cnt++;
            while(cnt == (int)t.size()){
                if(min_len > i - left + 1){
                    min_len = i - left + 1;
                    res = s.substr(left,min_len);
                }
                if(++u[s[left]] > 0)
                    --cnt;

                ++left;
            }
        }

        return res;
    }
};
