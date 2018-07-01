#include<cstring>
#include<stdio.h>
#include<iostream>
#include<unordered_set>
using namespace std;

char x[10010],y[10010];
int main( void ){
    
    int hash[128] = {0};
    unordered_set<char> s;
    gets(x);    //cin或者scanf无法识别回车换行符
    cin>>y;
    int len1 = strlen(x);
    int len2 = strlen(y);
    for(int i = 0;i < len2;i++){
        if(y[i] >= 'A' && y[i] <= 'Z'){
            hash[y[i]] = 1;
            hash[y[i] - 'A' + 'a'] = 1;
        }else if(y[i] == '+'){
            for(int j = 'A';j <= 'Z';j++)
                hash[j] = 1;
        }else{
            hash[y[i]] = 1;
        }
    }

    for(int i = 0;i < len1;++i){
        if(x[i] >= 'A' && x[i] <= 'Z'){
            if(hash[x[i]] == 0 && hash[x[i] - 'A' + 'a'] == 0){
                hash[x[i] - 'A' + 'a'] = 1;
                s.insert(x[i]);
            }
        }else if(x[i] >= 'a' && x[i] <= 'z'){
            if(hash[x[i]] == 0 && hash[x[i]] - 'a' + 'A'){
                hash[x[i] + 'A' - 'a'] = 1;
                s.insert(x[i] - 'a' + 'A');
            }
        }
        
        if(hash[x[i]] == 0)
            s.insert(x[i]);
    }
    for( auto c : s )
        cout<< c;

    return 0;
}
