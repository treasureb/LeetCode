#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int> multiply(const vector<int>& A){
        vector<int> res;
        int size = A.size();
        if(size == 0)
            return res;

        res.push_back(1);

        /* 第一个循环
         * 1. b[0] = 1;
         * 2. b[1] = b[0] * a[0] = a[0];
         * 3. b[2] = b[1] * a[1] = a[0] * a[1]
         * 4. b[3] = b[2] * a[2] = a[0] * a[1] * a[2]
         * 5. b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3]
         */

        for(int i = 0;i < size-1;++i){
            res.push_back(res.back() * A[i]);
        }

        /* 第二个循环
         * 1. temp *= a[4] = a[4]
         *    b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4]
         * 2. temp *= a[3] = a[4] * a[3]
         *    b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3]
         * 3. temp *= a[2] = a[4] * a[3] * a[2]
         *    b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2]
         * 4. temp *= a[1] = a[4] * a[3] * a[2] * a[1]
         *    b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1]
         *
         */
        
        int tmp = 1;
        for(int i = size-1;i >= 0;--i){
            res[i] = res[i] * tmp;
            tmp = tmp * A[i];
        }

        return res;
    }
};
