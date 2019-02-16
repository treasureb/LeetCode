#include <vector>
#include <math.h>

using namespace std;

int Most_Container(vector<int> v){
    int ret = 0;
    int i = 0,j = (int)v.size()-1;
    while(i < j){
        ret = max(ret,min(v[i],v[j]) * (j - i));

        v[i] < v[j] ? ++i:--j;
    }

    return ret;
}
