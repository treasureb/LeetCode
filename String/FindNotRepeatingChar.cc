#include<iostream>
#include<map>
#include<string>

using namespace std;

char FindNotRepeatingChar(const char* String)
{
    if(nullptr == String)
        return '\0';

    //构建一个哈希表
    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0;i < tableSize;++i)
        hashTable[i] = 0;

    //第一次扫描，统计每个字符出现的次数
    const char* HashKey = String;
    while(*(HashKey) != '\0'){
        hashTable[*(HashKey++)]++;
    }


    //第二次扫描，找只出现一次的
    HashKey = String;
    while(*HashKey != '\0'){
        if(hashTable[(*HashKey)] == 1)
            return *HashKey;

        HashKey++;
    }

    return '\0';
}

//第一个只出现一次的字符位置
class Solution{
public:
    int first_not_repeating_char(string str){
        map<char,int> mp;
        for(int i = 0;i < (int)str.size();++i){
            mp[str[i++]]++;
        }
        for(int i = 0;i < (int)str.size();++i){
            if(mp[str[i]] == 1)
                return i;
        }
        return -1;
    }     
};


int main()
{
    const char* s = "bbccadd";
    char ret = FindNotRepeatingChar(s);
    cout<<ret<<" "<<endl;
    return 0;
}
