#include<string>
#include<iostream>

using namespace std;
string add(string s1,string s2);
string sub(string s1,string s2);
int main( void ){
    string s1,s2;
    while(cin >> s1 >> s2){
        if(isdigit(s1[0]) && isdigit(s2[0]))
            cout<<add(s1,s2)<<endl;
        else if(!isdigit(s1[0]) && isdigit(s2[0])){
            s1 = s1.substr(1);
            s2 = s2.substr(1);
            cout<<'-' + add(s1,s2) <<endl;
        }else if(isdigit(s1[0]) && !isdigit(s2[0])){
            s2 = s2.substr(1);
            if(s1.size() > s2.size())
                s2 = string(s1.size() - s2.size(),'0')+s2;
            else
                s1 = string(s2.size() - s1.size(),'0')+s1;

            if(s1 >s2)
                cout<<sub(s1,s2)<<endl;
            else
                cout<<'-'+sub(s2,s1)<<endl;
        }else{
            s1 = s1.substr(1);
            if(s1.size() > s2.size())
                s2 = string(s1.size()-s2.size(),'0')+s2;
            else
                s1 = string(s2.size()-s1.size(),'0')+s1;
            if(s1 > s2)
                cout<<'-'+sub(s1,s2)<<endl;
            else
                cout<<sub(s2,s1)<<endl;
        }
    }
}

    string add(string s1,string s2){
        string res = "";
        if(s1.size() > s2.size())
            s2 = string(s1.size() - s2.size(),'0')+s2;
        else
            s1 = string(s2.size() - s1.size(),'0')+s1;
        int carry = 0;
        for(int i = s1.size()-1;i >=0;i--){
            char temp = (s1[i]-'0' + s2[i]-'0'+carry)%10+'0';
            res = temp+res;
            carry = (s1[i]-'0' + s2[i]-'0' + carry)/10;
        }
        if(carry)
            res = '1' + res;
        return res;
    }

    string sub(string s1,string s2){
        string res = "";
        int borrow = 0;
        int i = s1.size()-1;
        for(;i >= 0;i--){
            int op1 = (s1[i]-borrow >= s2[i])?(s1[i]-borrow-'0'):(10+s1[i]-borrow-'0');
            int op2 = s2[i] - '0';
            char temp = op1-op2+'0';
            res = temp + res;
            borrow = s1[i] - borrow<s2[i];
        }
        while(res[++i] == '0');
        res = res.substr(i);
        return res;
    }

