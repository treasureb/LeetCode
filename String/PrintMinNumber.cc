#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution{
public:
    string printf_min_number(vector<int> numbers){
        string answer = "";
        //自定义排序规则
        sort(numbers.begin(),numbers.end(),cmp);
        //然后直接进行字符串相加
        for(int i = 0;i < (int)numbers.size();++i){
            answer+=to_string(numbers[i]);
        }
        return answer;
    }
private:
    //这里的比较函数必须定义为static
    //两个数相互组成两个字符串，然后比较
    static bool cmp(int a,int b){
        string A="";
        string B="";
        A += to_string(a);
        A += to_string(b);
        B += to_string(b);
        B += to_string(a);

        return A < B;
    }
};
