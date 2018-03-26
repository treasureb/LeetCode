#include<ostream>

using namespace std;

class CharStatistics
{
public:
    //初始化哈希表
    CharStatistics()
    :index(0)
    {
        for(int i = 0;i < 256;++i)
            occurrence[i] = -1;
    }


    void Insert(char ch)
    {
        //如果第一次进，则记录下标
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        //如果是大于一次，当设置为-2
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;

        index++;
    }

    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i = 0;i < 256;++i){
            if(occurrence[i] >= 0 && occurrence[i] < minIndex){
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }

        return ch;
    }
private:
    int occurrence[256];
    int index;

};
