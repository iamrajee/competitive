#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int i,j,k,flag,sum,count;
int x,y;
bool l,u,r,d;
int xmn,ymn,xmx,ymx;
int main(){
    cin>>q;
    for(i=0;i<q;i++){
        cin>>n;
        xmn=-100000;
        ymn=-100000;
        ymx=100000;
        xmx=100000;
        for(j=0;j<n;j++){
            cin>>x>>y>>l>>u>>r>>d;
            if(!l){
                xmn=max(xmn,x);
            }
            if(!r){
                xmx=min(xmx,x); 
            }
            if(!u){
                ymx=min(ymx,y);
            }
            if(!d){
                ymn=max(ymn,y);
            }
        }
        if(xmn>xmx || ymn>ymx){
            cout<<"0"<<endl;
        }else{
            cout<<"1 "<<xmn<<" "<<ymn<<endl;
        }
    }
    return 0;
}