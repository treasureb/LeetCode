#include <stdio.h>

//将一个字符串进行逆置
void Reverse(char* Begin,char* End)
 {
     if(NULL == Begin || NULL == End)
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
     if(NULL == Data)
         return NULL;
 
     char* Begin = Data;
     char* End = Data;
     while(*End != '\0')
         End++;
     End--;
 
     //反转整个句子
     Reverse(Begin,End);
     printf("%s\n",Data);
 
     //反转句子中的每个单词
     Begin = End = Data;
     while(*Begin != '\0'){
         if(*Begin == ' '){
             Begin++;
             End++;
         }else if(*End == ' ' || *End == '\0'){
             Reverse(Begin,End-1);
             printf("%s\n",Data);
             Begin = ++End;
         }else
             End++;
     }
 
     return Data;
 }

int main(){
    char str[20] = "You And I";
    ReverseSentence(str);
    printf("%s\n",str);
    return 0;
}
