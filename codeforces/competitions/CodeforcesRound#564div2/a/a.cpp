#include<bits/stdc++.h>
using namespace std;

int u,d,o,dp;
int main(){
    cin>>u>>d>>o;
    // cout<<u<<d<<o<<endl;
    if(o==0){
        if(u>d){
            cout<<"+"<<endl;
        }else if(d>u){
            cout<<"-"<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }else{
        dp = abs(u-d);
        if(dp>o){
            if(u>d){
                cout<<"+"<<endl;
            }else if(d>u){
                cout<<"-"<<endl;
            }
        }else{
            cout<<"?"<<endl;
        }
    }
    return 0;
}