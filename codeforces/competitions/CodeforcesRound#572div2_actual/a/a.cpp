#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum;
int a,b,t;
int T;
string s;
int main(){
    cin>>n;
    cin>>s;
    t=count(s.begin(),s.end(),'0');
    if(n-t != t){
        cout<<"1"<<endl;
        cout<<s<<endl;
    }else{
        cout<<"2"<<endl;
        cout<<s[0]<<" "<<s.substr(1)<<endl;
    }
    return 0;
}