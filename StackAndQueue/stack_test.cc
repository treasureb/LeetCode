#include<stack>
#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF && n != 0){
        stack<int >s;
        for(int i = 0;i < n;++i){
            char c;
            cin>>c;
            if(c == 'A'){
                if(s.empty())
                    cout<<"E"<<endl;
                else
                    cout<<s.top();
            }else if(c == 'P'){
                int number;
                scanf("%d",&number);
                s.push(number);
            }else if(c == 'O'){
                if(s.empty())
                    continue;
                else
                    s.pop();
            }
        }
        cout<<endl;
    }
    return 0;
}
