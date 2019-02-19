#include<iostream>
#include<vector>

using namespace std;

/* 解题思路: */
/* 1. 控制四个顶点 */
/* 2. 最后从下到上注意循环次数 */

class Solution
{
public:
    vector<int> print_Matrix(vector<vector<int>> matrix)
    {
        vector<int> result;
        int cols = matrix[0].size();
        int rows = matrix.size();

        if(cols == 0 || rows == 0)
            return result;

        int left = 0,top = 0,right = cols-1,bottom = rows-1;
        while(left <= right && top <= bottom){
            //left to right
            for(int i = left;i <= right;++i)
                result.push_back(matrix[top][i]);

            //top to bottom
            for(int i = top+1;i <= bottom;++i)
                result.push_back(matrix[i][right]);

            //right to left
            if(top != bottom)
            for(int i = right-1;i >= left;--i)
                result.push_back(matrix[bottom][i]);

            //bottom to top
            if(left != right)
            for(int i = bottom - 1;i > top;--i)
                result.push_back(matrix[i][left]);

            left++,top++,right--,bottom--;
        }
        
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}};
    vector<int> p;
    p = s.print_Matrix(v);
    int count = v[0].size()-1;
    for(auto c : p){
        cout<<c<<" ";
        while(!(count--)){
            count = v[0].size();
            cout<<endl;

        }
    }
    cout<<endl;

    return 0;
}
