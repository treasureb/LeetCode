#include<stack>
#include<vector>

using namespace std;

class Solution
{
public:
    bool is_pop_order(vector<int> pushV,vector<int> popV)
    {
        if(pushV.empty() || popV.empty()||pushV.size() != popV.size())
            return false;

        stack<int> s;

        int j = 0;
        for(size_t i = 0;i < pushV.size();++i){
            s.push(pushV[i]);
            while(!s.empty() && s.top() == popV[j]){
                s.pop();
                ++j;
            }
        }
        if(s.empty())
            return true;

        return false;
    }
};

int main()
{
    return 0;
}
