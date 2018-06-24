#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    /*
     * 求字母的组成相同，但是顺序不同的所有字符串
     * 1.思路
     *   a)组成相同的字符串，经过排序之后是相同的
     *   b)然后以排序后的字符串作为key值
     *
     */

    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>>  res;
        if(strs.empty())
            return res;
        
        unordered_map<string,vector<string>> up;
        for(string str:strs){
            string tmp = str;
            //组成相同的字符串排序后的key值相同
            sort(tmp.begin(),tmp.end());
            //根据key值,插入对应的value
            up[tmp].push_back(str);
        }

        //哈希表的Value中存储着每一个vector
        //每一个veator中存储着对应的所有字符串
        for(auto c:up){
            res.push_back(c.second);
        }

        return res;
    }
};
