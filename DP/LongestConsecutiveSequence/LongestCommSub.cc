#include<iostream>
#include<vector>
#include<string>
using namespace std;

void LCS(string& str1,string& str2,vector<vector<int> >& c,vector<vector<char> >& b){
    int len1 = str1.size();
    int len2 = str2.size();
    c.resize(len1+1);
    b.resize(len1+1);
    
    for(int i = 0;i < (int)c.size();++i)
        c[i].resize(len2+1);
    for(int i = 0;i < (int)b.size();++i)
        b[i].resize(len2+1);

    for(int i = 1;i <= len1;++i){
        for(int j = 1;j <= len2;++j){
            if(str1[i-1] == str2[i-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'c';
            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'l';
            }
        }
    }
}

    void print_LCS(vector<vector<char> >& b,string str1,int i,int j){
        if(i == 0 || j == 0)
            return;
        if(b[i][j] == 'c'){
            print_LCS(b,str1,i-1,j-1);
            cout<<str1[i-1];
        }else if(b[i][j] == 'u'){
            print_LCS(b,str1,i-1,j);
        }else{
            print_LCS(b,str1,i,j-1);
        }
    }



int main(){
    string str1("ABCBDAB");
    string str2("BDCABA");
    vector<vector<int> > c;
    vector<vector<char> > b;

    LCS(str1,str2,c,b);
    print_LCS(b,str1,str1.size(),str2.size());
    return 0;
}
