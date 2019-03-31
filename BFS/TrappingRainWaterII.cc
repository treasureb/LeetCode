#include <vector>
#include <queue>
#include <climits>

using namespace std;

/* 解题思路: */
/*     1. 使用优先级队列保存最外围的一圈,visited数组记录走过的位置 */
/*     2. 取队头的值然后进行BFS，如果该值未被访问且低于最低水平面则可装水 */

class Solution{
    int trapp(vector<vector<int>>& heightMap){
        if(heightMap.empty())
            return 0;
        int m = heightMap.size(),n = heightMap[0].size();
        int res = 0,water_height = INT_MIN;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    q.push({heightMap[i][j],i*n+j});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            auto t = q.top();
            q.pop();
            int h = t.first,r = t.second / n,c = t.second % n;
            water_height = max(water_height,h);
            for(int i = 0;i < (int)dir.size();++i){
                int x = r + dir[i][0],y = c + dir[i][1];
                if(x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                visited[x][y] = true;
                if(heightMap[x][y] < water_height)
                    res += water_height - heightMap[x][y];

                q.push({heightMap[x][y],x*n+y});
            }
        }
        return res;
    }
};
