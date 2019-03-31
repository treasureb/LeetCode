#include <vector>
#include <string>
using namespace std;

/* 解题思路: */
/*     1. 使用visited数组保存已访问过的位置 */
/*     2. 使用回溯法进行每个位置上的递归访问 */

class Solution{
public:
    bool WordSearch(vector<vector<char>>& board,string word){
        if(board.empty() || board[0].empty())
            return false;

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i = 0;i < m;++i){
            for(int j = 0;j < n;++j){
                if(exist(board,word,0,i,j,visited))
                    return true;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board,string word,int index,int i,int j,vector<vector<bool>>& visited){
        if(index == static_cast<int> (word.size()))
            return true;

        int m = board.size();
        int n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[index])
            return false;

        visited[i][j] = true;
        bool res = exist(board,word,index+1,i-1,j,visited)
                || exist(board,word,index+1,i+1,j,visited)
                || exist(board,word,index+1,i,j-1,visited)
                || exist(board,word,index+1,i,j+1,visited);
        visited[i][j] = false;
        return res;
    }
};
