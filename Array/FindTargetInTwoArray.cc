#include<iostream>
#include<vector>
using namespace std;

bool FindTarget(vector<vector<int>> numbers,int target)
{
    if(numbers.size() < 1)
        return false;

    int row = numbers.size();
    int col = numbers[0].size();

    int i = 0;
    int j = col - 1;
    for(; i < row && j >=0;){
        if(target == numbers[i][j])
            return true;

        if(target < numbers[i][j]){
            ++i;
            continue;
        }
        if(target > numbers[i][j]){
            --j;
            continue;
        }
    }
    return false;
}

bool FindTarget2(vector<vector<int>>& numbers,int target)
{
    if(numbers.size() < 1)
        return false;

    for(size_t i = 0;i < numbers.size();++i){
        int left = 0;
        int right = numbers[i].size();
        while(left < right){
            int mid = left + ((right-left)>>1);
            if(numbers[i][mid] == target)
                return true;
            if(numbers[i][mid] < target){
                left = mid + 1;
                continue;
            }
            if(numbers[i][mid] > target){
                right = mid - 1;
                continue;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> v = {{1,2,8,9},
                            {2,4,9,12},
                            {4,7,10,13},
                            {6,8,11,15}};

    bool result = FindTarget(v,11);
    cout<<result<<endl;
    return 0;
}
