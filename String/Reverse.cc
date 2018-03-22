#include<iostream>
#include<string.h>

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
