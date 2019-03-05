#include <string>
#include <climits>
#include <unordered_map>

using  namespace std;

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
