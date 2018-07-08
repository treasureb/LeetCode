#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> combine(int n ,int k){
        vector<vector<int>> res;
        if(1 > n || 1 > k)
            return res;

        vector<int> v;
        helper(n,1,k,v,res);
        return res;
    }
private:
    void helper(int n,int start,int k,vector<int>& v,vector<vector<int>>& res){
        if(0 == k){
            res.push_back(v);
            return;
        }

        for(int i = start;i <= n-k+1;++i){
            v.push_back(i);
            helper(n,i+1,k-1,v,res);
            v.pop_back();
        }
    }
};
