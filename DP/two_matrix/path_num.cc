#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

int unique_path_r(int m,int n){
    if(m == 1){
        return 1;
    }
    if(n == 1){
        return 1;
    }

    return unique_path_r(m,n-1) + unique_path_r(m-1,n);
}

int unique_path(int m,int n){
    vector<vector<int> > v(m,vector<int>(n));
    v[0][0] = 0;
    for(int i = 1;i < m;i++)
        v[i][0] = 1;
    for(int j = 1;j < n;j++)
        v[0][j] = 1;
    for( int i = 1;i < m;i++)
        for(int j = 1;j < n;j++)
            v[i][j] = v[i][j-1] + v[i-1][j];

    return v[m-1][n-1];
}
int main(){
    clock_t begin,end;
    double total_time;
    begin = clock();
    cout<<unique_path_r(17,17)<<endl;
    end = clock();
    total_time = (double)(end - begin)/CLOCKS_PER_SEC;
    cout<<"递归程序运行时间 : "<<total_time<<endl;

    begin = clock();
    cout<<unique_path(17,17)<<endl;
    end  = clock();
    total_time = (double)(end-begin)/CLOCKS_PER_SEC;
    cout<<"动态规划运行时间 : "<<total_time<<endl;
}
