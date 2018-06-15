#include<stack>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> setOfStacks(vector<vector<int>> ope,int size){
        size_t s = ope.size();
        vector<vector<int>> res;
        vector<int> tmp;
        for(size_t i = 0;i < s;i++){
            if(ope[i][0] == 1){
                if((int)tmp.size() == size){
                    res.push_back(tmp);
                    tmp.clear();
                    tmp.push_back(ope[i][1]);
                }else{
                    tmp.push_back(ope[i][1]);
                }    
            }else{
                if(tmp.size() == 0){
                    tmp = res[res.size()-1];
                    tmp.pop_back();
                    res.pop_back();
                }else{
                    tmp.pop_back();
                }
            }
        }
        if(tmp.size() != 0)
            res.push_back(tmp);
        return res;
    }
};
