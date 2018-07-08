#include<iostream>
using namespace std;

class Solution{
public:
    int sqrt(int n){
        if(n == 0)
            return 0;

        int left = 1,right = n,res = left;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(mid <= n/mid){
                left = mid + 1;
                res = mid;
            }else{
                right = mid - 1;
            }
        }
        return res;
    }
};
