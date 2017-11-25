#include<iostream>
#include<string>
using namespace std;

bool JudgeRouteCircle(string moves)
{
    if(moves.length() == 0)
        return true;
    if(moves.length() % 2 == 1)
        return false;

    int up_Or_down = 0;
    int left_Or_right = 0;
    for(int i = 0;i < moves.length();++i)
    {
        if(moves[i] == 'U')
            up_Or_down++;
        else if(moves[i] == 'D')
            up_Or_down--;
        else if(moves[i] == 'L')
            left_Or_right++;
        else if(moves[i] == 'R')
            left_Or_right--;
        else
            cout<<"Print Error!"<<endl;
    }
    if(up_Or_down == 0 && left_Or_right == 0)
        return true;
        
        return false;
}

int main()
{
    string s1("UD");
    string s2("UDLR");
    string s3("UDDDD");
    string s4("UDRLUDR");
    string s5("UDSAW");
    cout<<JudgeRouteCircle(s1)<<" ";
    cout<<JudgeRouteCircle(s2)<<" ";
    cout<<JudgeRouteCircle(s3)<<" ";
    cout<<JudgeRouteCircle(s4)<<" ";
    cout<<JudgeRouteCircle(s5)<<" ";
    cout<<endl;
    return 0;
}
