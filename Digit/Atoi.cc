#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

int My_atoi(string str)
{
     int length = str.size();
        long long ret_64 = 0;
        int op = 1;
        int p = 0;
        while (str[p] == ' ') 
            ++p;
        if (str[p] == '+' || str[p] == '-') 
        {
            if (str[p] == '-') op = -1;
            p++;
        }

        for (int i = p; i < length; ++i)
        {
            if ('0' <= str[i] && str[i] <= '9') 
            {
                ret_64 = ret_64 * 10 + (str[i] - '0');
                if ((op == -1 && ret_64 > 2147483648LL)) 
                    return -2147483648;
                if ((op == 1 && ret_64 > 2147483647LL)) 
                    return 2147483647;
            }   
            else 
                break;
        }
        return (int)ret_64 * op;
}

int main()
{
    string s = "1314";
    int ret = My_atoi(s);
    cout<<ret<<endl;
    return 0;
}
