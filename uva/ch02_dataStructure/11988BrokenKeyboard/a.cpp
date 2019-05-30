#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t;
string s;
string fs;
string ts;
int flag=0;
int main(){
    while(cin>>s){
        ts="";
        fs="";
        flag=1;
        // cout<<s<<endl;
        for(i=0;i<s.size();i++){
            if(s[i]=='['){
                flag=-1;
                ts=fs+ts;
                fs="";
            }else if(s[i]==']'){
                flag=1;
                ts=fs+ts;
                fs="";
            }else{
                if(flag==-1){
                    fs=fs+s[i];
                }else{
                    ts=ts+s[i];
                }
            }
        }
        cout<<fs+ts<<endl;
    }
    return 0;
}