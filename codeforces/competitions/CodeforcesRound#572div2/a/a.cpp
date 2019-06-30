#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t,s;
int T;
int main(){
    cin>>T;
    for(i=0;i<T;i++){
        cin>>n>>s>>t;
        cout<<n-min(s,t)+1<<endl;
    }

    return 0;
}