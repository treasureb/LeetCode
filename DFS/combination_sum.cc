#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:

    /* 通过递归去求解,内存受限 */
    vector<vector<int>> combination(vector<int>& candidates,int target){
        vector<vector<int>> res;
        DFS(candidates,target,0,{},res);
        return res;
    }

    void DFS(vector<int>& candidates,int target,int start,vector<int> out,vector<vector<int>> res){
        if(target < 0)
            return;
        else if(target == 0){
            res.push_back(out);
            return;
        }

        for(size_t i = start;i < candidates.size();++i){
            out.push_back(candidates[i]);
            DFS(candidates,target,i,out,res);
            out.pop_back();
        }
    }

    vector<vector<int>> combination_DP(vector<int>& candidates,int target){
        vector<vector<vector<int>>> dp;
        sort(dp.begin(),dp.end());
        for(int i = 1;i < target;++i){
            vector<vector<int>> cur;
            for(size_t j = 0;j < candidates.size();++j){
                if(candidates[j] > i)
                    break;
                else if(candidates[j] == i){
                    cur.push_back({candidates[j]});
                    continue;
                }
                for(auto a : dp[i - candidates[j] - 1]){
                    if(candidates[j] > a[0])
                        continue;
                    a.insert(a.begin(),candidates[j]);
                    cur.push_back(a);
                }
            }
            dp.push_back(cur);
        }
        return dp[target-1];
    }
};



int main(){
    Solution s;
    vector<vector<int>> res;
    vector<int> numbers = {2,3,6,7};
    res = s.combination_DP(numbers,7);
    for(size_t i = 0;i < res.size();++i){
        for(size_t j = 0;j < res[i].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
