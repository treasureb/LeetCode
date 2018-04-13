#include<iostream>
#include<vector>
using namespace std;

//代码耦合度太高
void ReorderOddEven(int* Data,size_t length)
{
    if(nullptr == Data)
        return;

    int* Begin = Data;
    int* End = Data+length+1;

    while(Begin < End){
        //向后移动Begin,直到指向一个偶数
        while(Begin < End && (*Begin & 0x1) != 0)
            Begin++;

        //向前移动End,直到指向一个奇数
        while(Begin < End && (*End & 0x1) == 0)
            End--;

        if(Begin < End){
            int tmp = *Begin;
            *Begin = *End;
            *End = tmp;
        }
    }
}


///////////////////////////
bool (*fun)(int);

void Reorder(int* Data,size_t length,bool(*fun)(int))
{
    if(nullptr == Data)
        return;

    int* Begin = Data;
    int* End = Data + length + 1;

    while(Begin < End){
        while(Begin < End && !fun(*Begin))
            Begin++;
        while(Begin < End && !fun(*End))
            End--;

        if(Begin < End){
            int tmp = *Begin;
            *Begin = *End;
            *End = tmp;
        }
    }
}

bool IsBool(int n)
{
    return (n&1) == 0;
}

void ReorderOddEven2(int* Data,size_t length)
{
    Reorder(Data,length,IsBool);
}



//###########################################################
//重建创建一个数组
//虽然有空间复杂度的开销，但是保证了稳定性
void reorder_array(vector<int>& v)
{
    vector<int> result;
    vector<int>::iterator it = v.begin();
    while(it != v.end()){//将原数组中的所有奇数都先插入到新数组中
        if(((*it) & 0x1) == 1)
            result.push_back(*it);

        ++it;
    }
    it = v.begin();
    while(it != v.end()){
        if(((*it) & 0x1) == 0)
            result.push_back(*it);

        ++it;
    }
    v = result;
}


//##############################
//采用快慢指针法
//会改变原有数据的相对位置
void quick_order(vector<int>& v)
{
    int size = v.size();
    int cur = 0;
    int pre = cur-1;
    while(cur < size){
        while((v[cur] & 0x1) == 1 && ++pre != cur){
           swap(v[cur],v[pre]);
        }
        ++cur;
    }
}


int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    quick_order(v);
    for(auto c:v){
        cout<<c<<" ";
    }
    return 0;
}
