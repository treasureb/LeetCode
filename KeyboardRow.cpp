#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class KeyboardRow
{
    vector<string> FindWords(vector<string>& words)
    {
        str[0] = "qwertyuiop";
        str[1] = "asdfghjkl";
        str[2] = "zxcvbnm";
        for(int i = 0; i < 3;++i)
        {
            for(int j = 0;j < str[i].size();++j)
            {
                hash[i][str[i][j]] = true;
            }
        }

        vector<string> res;
        for(int i = 0;i < words.size();++i)
        {
            if(words[i].size() == 1)
                res.push_back(words[i]);
            else
            {
                int j = 1;
                for(;j < words[i].size();++j)
                {
                    if(find_char(tolower(words[i][j])) != find_char(tolower(words[i][j-1])))
                        break;
                }
                if(j == words[i].size())
                    res.push_back(words[i]);
            }
        }
        return res;
    }

    int find_char(char ch)
    {
        int hash_start_index = 0;
        for(int hash_index = 0;hash_index < 3;++hash_index)
        {
            if(hash[hash_index].find(ch) != hash[hash_index].end())
            {
                hash_start_index = hash_index;
                break;
            }
        }
        return hash_start_index;
    }

    unordered_map<char,bool> hash[3];
    string str[3];
};

int main()
{
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    KeyboardRow k;
    k.FindWords(words);
    return 0;
}
