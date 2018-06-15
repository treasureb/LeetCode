#include<vector>
using namespace std;

class Solution{
public:
    vector<int> twoStacksSort(vector<int> numbers){
        vector<int> tmp;
        while(!numbers.empty()){
            int cur = numbers.back();//保持栈的特性
            numbers.pop_back();
            while(!tmp.empty() && cur < tmp.back()){
                numbers.push_back(tmp.back());
                tmp.pop_back();
            }
            tmp.push_back(cur);
        }
        numbers.clear();
        while(!tmp.empty()){
            numbers.push_back(tmp.back());
            tmp.pop_back();
        }
        return numbers;
    }
};
