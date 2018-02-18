#include<iostream>
#include<vector>
using namespace std;

bool FindNumber(vector<int> v,int rows,int columns,int number)
{
    bool found = false;
    if(v.size() > 0 && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >=0)
        {
            if(v[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if(v[row * columns + column] > number)
                --column;
            else
                ++row;
        }
    }
    return found;
}

int main()
{
    vector<int> v = {1,2,8,9
                    ,2,4,9,12
                    ,4,7,10,13
                    ,6,8,11,15};
    cout<<FindNumber(v,4,4,19)<<endl;
    return 0;
}
