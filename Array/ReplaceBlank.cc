#include<iostream> 
#include<string>
using namespace std;

string ReplaceBlank(string str)
{
    if(str.size() < 1)
    return "";

    int BlankNumber = 0;
    string::iterator it = str.begin();
    while(it != str.end())
    {
        if(*(it) == ' ')
            ++BlankNumber;
    } 

    int indexOriginal = str.size();
    str.resize(str.size()+BlankNumber*2);
    int indexNew = str.size();
    while(indexOriginal >= 0 && indexNew > indexOriginal)
    {
        if(str[indexOriginal] == ' ')
        {
            str[indexNew--] = '0'; 
            str[indexNew--] = '2'; 
            str[indexNew--] = '%'; 
        }
        else
        {
            str[indexNew--] = str[indexOriginal];
        }
        --indexOriginal;
    }

    return str;
}

int main()
{
    string s = "We are happy";
    string ret = ReplaceBlank(s);
    cout<<ret<<endl;
    return 0;
}
