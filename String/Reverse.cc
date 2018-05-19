#include<iostream>
#include<string>

using namespace std;
//整体反转
void Reverse(char* Begin,char* End)
{
    if(nullptr == Begin || nullptr == End)
        return;

    while(Begin < End){
         char tmp = *Begin;
         *Begin = *End;
         *End   = tmp;

         Begin++;
         End--;
    }
}

char* ReverseSentence(char* Data)
{
    if(nullptr == Data)
        return nullptr;

    char* Begin = Data;
    char* End = Data;
    while(*End != '\0')
        End++;
    End--;

    //反转整个句子
    Reverse(Begin,End);

    //反转句子中的每个单词
    Begin = End = Data;
    while(*Begin != '\0'){
        if(*Begin == ' '){
            Begin++;
            End++;
        }else if(*End == ' ' || *End == '\0'){
            Reverse(Begin,End);
            Begin = ++End;
        }else
            End++;
    }

    return Data;
}


char* LeftRotateString(char* Str,int n)
{
    if(Str != nullptr){
        int length = static_cast<int>(strlen(Str));
        if(length > 0 && n > 0 && n < length){
            char* FirstStart = Str;
            char* FirstEnd = Str+n-1;
            char* SecondStart = Str+n;
            char* SecondEnd = Str+length-1;

            Reverse(FirstStart,FirstEnd);

            Reverse(SecondStart,SecondEnd);

            Reverse(FirstStart,SecondEnd);
        }
    }

    return Str;
}

class Solution{
public:
    /*
     *  1.采用多次逆置法
     */

    string LeftRotateString(string str,int n){
        int len = str.size();
        if(len <= 0)
            //string有多种构造函数
            return "";

        //处理循环移动
        n %= len;
        if(n == 0)
            return str;

        reverse_str(str,0,n-1);
        reverse_str(str,n,len-1);
        reverse_str(str,0,len-1);

        return str;
    }

    string LeftRotateString_substr(string str,int n){
        string ret;
        int len = str.size();
        if(len <= 0)
            return "";

        n = n % len;
        ret = str+str.substr(0,n);
        ret = ret.substr(n,str.size());
        return ret;
    }

private:
    void reverse_str(string& str,int left,int right){
        for(int i = left,r = right;i <= left+(right-left)/2;++i){
            swap(str[i],str[r--]);
        }
    }
};
