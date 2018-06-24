#include<vector>
using namespace std;

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        if(matrix.empty())
            return;

        size_t s = matrix[0].size();
        vector<vector<int>> tmp(s,vector<int>(s,0));
        for(size_t i = 0;i < s;++i){
            for(size_t j = 0;j < s;++j)
                tmp[j][s-1-i] = matrix[i][j];
        }
        matrix = tmp;
    }
};
