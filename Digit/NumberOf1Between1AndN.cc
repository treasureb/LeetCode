#include<iostream>
using namespace std;

class Solution{
public:
    /*
     * 1. 暴力求解
     */

    int NumberOf1Between1AndN(int n){
        int count = 0;
        for(int i = 0;i <= n;i++){
            int tmp = i;

            //如果tmp的任意位为1，则count++
            while(tmp){
                if(tmp % 10 == 1){
                    count++;
                }
                tmp /= 10;
            }
        }
        return count;
    }
};

int main()
{
    Solution s;
    int res = s.NumberOf1Between1AndN(100);
    cout<<res<<endl;
}
