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


    /*
     * 2. 采用计算每一位上1的个数
     *
     */
    int NumberOf1Between1AndN2(int n){
        int exp = 1;
        int ans = 0;
        while(n / exp){
            ans += n / (exp * 10) * exp;
            if(n % (exp * 10) / exp > 1)
                ans += exp;
            else if(n % (exp * 10) / exp == 1)
                ans += (n % exp + 1);

            exp *= 10;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    int res = s.NumberOf1Between1AndN(100);
    cout<<res<<endl;
}
