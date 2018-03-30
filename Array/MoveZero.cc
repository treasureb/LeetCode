#include<iostream>
#include<vector>
using namespace std;

//将数组中的0移到末尾
void MoveZero(vector<int>& v)
{
    int len = v.size();
    int count = 0;
    
    for(int i = 0;i < len;++i){
    	if(v[i] != 0)
            v[count++] = v[i];
    }
    
    for(int i = count;i < len;++i){
    	v[i] = 0;
    }
}

int main()
{
    vector<int> v;
    int nums = 0;
    cin>>nums;
    int num = 0;
    for(int i = 0;i < nums;++i){
    	cin>>num;
        v.push_back(num);
    }
    MoveZero(v);
    vector<int>::iterator it = v.begin();
    while(it != v.end()){
    	cout<<*it<<endl;
        ++it;
    }
	return 0;
}

