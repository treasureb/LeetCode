#include<iostream>
#include<string.h>
using namespace std;

/*
 * 判断在一个二位矩阵中时候存在一条路径
 * 典型的回溯法求解问题
 *
 */

bool HasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLength,bool* visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool haspath = false;
    if(row >= 0 && row < rows && col >= 0 && col < cols &&matrix[row*cols+col] == str[pathLength] && !visited[row * cols+col]){
        ++pathLength;
        visited[row * cols+col] = true;

        haspath = HasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited)
            ||HasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
            ||HasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
            ||HasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);

        if(!haspath){
            --pathLength;
            visited[row * cols+col] = false;
        }
    }
    return haspath;
}

bool HasPath(char* matrix,int rows,int cols,char* str)
{
    if(nullptr == matrix || nullptr == str || rows < 1 || cols < 1)
        return false;

    //开辟一个相同的二维数组保存该位置是否已经被访问
    bool* visited = new bool[rows * cols]; 
    memset(visited,0,rows*cols);

    int pathLength = 0;
    for(int row = 0;row < rows;++row){
        for(int col = 0;col < cols;++col){
            if(HasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
                return true;
        }
    }

    delete[] visited;

    return false;
}
