#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
    int numIsLands(vector<vector<int>>& grid){
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;

        int res = 0;
        for(int i = 0;i < (int)grid.size();++i){
            for(int j = 0;j < (int)grid[0].size();++j){
                if(grid[i][j] == '1'){
                    ++res;
                    DFS(grid,i,j);
                }
            }
        }
        return res;
    }

private:
    void DFS(vector<vector<int>>& grid,int x,int y){
        if(x > 0 && grid[x][y] == '1')
            DFS(grid,x-1,y);
        if(x < (int)grid.size() - 1 && grid[x+1][y] == '1')
            DFS(grid,x+1,y);
        if(y > 0 && grid[x][y-1] == '1')
            DFS(grid,x,y-1);
        if(y < (int)grid[0].size() && grid[x][y+1])
            DFS(grid,x,y+1);
    }

    void BFS(vector<vector<int>>& grid,int x,int y){
       queue<vector<int>> q;
       q.push({x,y});
       grid[x][y] = '0';

       while(!q.empty()){
           x = q.front()[0];
           y = q.front()[1];
           q.pop();

           if(x > 0 && grid[x-1][y] == '1'){
               q.push({x-1,y});
               grid[x-1][y] = '0';  //将访问过的复原
           }
           if(x < (int)grid.size() - 1 && grid[x+1][y] == '1'){
               q.push({x+1,y});
               grid[x+1][y] = '0';
           }
           if(y > 0 && grid[x][y-1] == '1'){
               q.push({x,y-1});
               grid[x][y-1] = '0';
           }
           if(y < (int)grid.size() - 1 && grid[x][y+1] == '1'){
               q.push({x,y+1});
               grid[x][y+1] = '0';
           }
       }
    }
};
