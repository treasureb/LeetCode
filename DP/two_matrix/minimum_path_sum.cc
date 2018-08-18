#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int>>& a){
        int m = a.size();
        if(m == 0)
            return 0;
        int n = a[0].size();

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int left = (j == 0)? INT_MAX : a[i][j-1];
                int up   = (i == 0)? INT_MAX : a[i-1][j];
                if(i == 0 && j == 0)
                    continue;
                a[i][j] += min(left,up);
            }
        }
        return a[m-1][n-1];
    }
};
