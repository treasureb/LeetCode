#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

/*
 *  基于指针这样的全排列,没有考虑去重问题
 *
 */
//Str指向整个字符串的第一个字符，Begin指向当前正在处理的字符串的第一个
void Permutation(char* Str,char* Begin)
{
    if(*Begin == '\0')
        printf("%s\n",Str);
    else{

        for(char* Ch = Begin;(*Ch)!= '\0';++Ch){
            char tmp = *Ch;
            *Ch = *Begin;
            *Begin = tmp;

            Permutation(Str,Begin+1);

            //将前面交换的换回去
            tmp = *Ch;
            *Ch = *Begin;
            *Begin = tmp;
        }
    }
}

void Permutation(char* Str)
{
    if(nullptr == Str)
        return;

    //递归进行全排列
    Permutation(Str,Str);
}

class Solution{
    void permutation(vector<string> &ans,int k,string str){
        if(k == (int)str.size() -1)
            ans.push_back(str);
        unordered_set<char> us;//记录出现过的字符
        sort(str.begin()+k,str.end());//保证按字典序输出
        for(int i = k;i < (int)str.size();i++){
            if(us.find(str[i]) == us.end()){//只和没交换过的换
                us.insert(str[i]);
                swap(str[i],str[k]);
                permutation(ans,k+1,str);
                swap(str[i],str[k]);//复位
            };

        }
    } 
public:
    vector<string> Permutation(string str){
        vector<string> ans;
        permutation(ans,0,str);
        return ans;
    }
};

int main()
{
    char s[] = "aabb";
    Permutation(s);
}
