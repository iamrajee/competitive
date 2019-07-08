#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int t,l,r;

set <pair<int,int> > ia;
set <pair<int,int> > da;
int main(){
    cin>>n>>m;
    vector <int> v(n,0);
    for(i=0;i<m;i++){
        cin>>t>>l>>r;
        if(t==1){
            ia.insert({l-1,r});
        }else{
            da.insert({l-1,r});
        }
    }
    for(auto it:ia){
        l = it.first;
        r = it.second;
        for(i=l;i<r;i++){
            
        }
    }
    return 0;
}