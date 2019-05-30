#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t;
string s;
string ts;
int ch;
int flag=0;
int main(){
    while(cin>>s){
        ts="";
        flag=1;
        ch=-1;
        // cout<<s<<endl;
        for(i=0;i<s.size();i++){
            if(s[i]=='['){
                // cout<<"fs:"<<s.substr(ch+1,(i-1)-(ch+1) + 1)<<" , ts: "<<ts;
                if(flag==1){
                    ts=ts + s.substr(ch+1,(i-1)-(ch+1) + 1); //(3,5) => 3,4,5,6,7 => 7-3+1 = 5
                }else{
                    ts=s.substr(ch+1,(i-1)-(ch+1) + 1) + ts;
                }
                flag=-1;
                ch = i;
                // cout<<"  ,  final:"<<ts<<endl;
            }else if(s[i]==']'){
                // cout<<"->fs:"<<flag<<s.substr(ch+1,(i-1)-(ch+1) + 1)<<" , ts: "<<ts;
                if(flag==1){
                    ts=ts + s.substr(ch+1,(i-1)-(ch+1) + 1);
                }else{
                    ts=s.substr(ch+1,(i-1)-(ch+1) + 1) + ts;
                }
                flag=1;
                ch = i;
                // cout<<"  ,  final:"<<ts<<endl;
            }
        }
        // i--;
        if(flag==1){
            ts=ts + s.substr(ch+1,(i-1)-(ch+1) + 1);                    
        }else{
           ts=s.substr(ch+1,(i-1)-(ch+1) + 1) + ts;
        }
        cout<<ts<<endl;
    }
    return 0;
}