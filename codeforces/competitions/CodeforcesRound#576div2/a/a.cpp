#include<bits/stdc++.h>
using namespace std;

int n,m,x,y;
int i,j,k,flag,sum,count;
int a,b,t;
vector <int> v;
int  mn,mni;
int main(){
    cin>>n>>x>>y;
    mn=100001;
    /*
    for(i=0;i<min(x+y+1,n);i++){
        v.push_back(a);
        if(a<mn){
            mn=a;
            mni=i;
        }
    }
    if(n>=x+y+1){
        if(mn==v[x]){
            cout<<x+1<<endl;
            return;
        }
    }else if(n>x){
        if(mn==v[x]){
            cout<<x+1<<endl;
            return;
        }else{

        }
    }else{

    }
    */
    for(i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    int j1,j2;
    for(i=0;i<n;i++){
        j1=max(0,i-x);
        j2=min(i+y+1,n);
        flag=0;
        // cout<<j1<<","<<j2<<endl;
        for(j=j1;j<j2;j++){
            if(v[j]<v[i]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            // cout<<i+1<<" "<<v[i]<<endl;
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}