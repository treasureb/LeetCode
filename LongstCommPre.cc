#include<iostream>
#include<string>
#include<vector>
using namespace std;

string LongstCommPre(vector<string>& str)
{
    if(str.size() < 1)
        return "";
    string ret = "";
    for(size_t i = 0;i < str[0].size();++i)
    {
        bool flag = true;
        for(size_t j = 1;j < str.size() && flag;++j)
        {
            if(str[j][i] != str[0][i])
                flag = false;
        }
        if(flag)
            ret += str[0][i];
        else
            return ret;
    }

    return ret;
}

int main()
{
    string s1 = "helloworld";
    string s2 = "hellowor";
    string s3 = "hello";
    vector<string> str;
    str.push_back(s1);
    str.push_back(s2);
    str.push_back(s3);
    string ret = LongstCommPre(str);
    cout<<ret<<endl;
    return 0;
}
