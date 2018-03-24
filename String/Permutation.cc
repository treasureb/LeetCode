#include<iostream>
#include<stdio.h>


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

int main()
{
    char s[4] = "abc";
    Permutation(s);
}
