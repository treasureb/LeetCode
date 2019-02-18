#include <stack>
using namespace std;

/* 解题思路 */
/* 1.插入操作直接在s1进行 */
/* 2.如果s2不为空直接删除s2的栈顶，否则就先把s1中的数据倒入s2 */

class Solution{
public:
    void push(int x){
        s1.push(x);        
    }

    int pop(){  //STL中stack和queue的pop接口都是返回void
        if(s2.empty()){
            while(!s1.empty()){
                int top = s1.top();
                s2.push(top);
                s1.pop();
            }
        }
        int top = s2.top();
        s2.pop();
        return top;
    }
private:
    stack<int> s1;
    stack<int> s2;
};
