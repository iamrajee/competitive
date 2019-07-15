#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,counter;
int a,b,t,q,l,r;

vector <int> v(200001,0);

int main(){
    cin>>n>>k>>q;
    
    for(i=0;i<n;i++){
        cin>>l>>r;
        for(j=l;j<=r;j++){
            v[j]++;
        }
    }
    for(i=0;i<q;i++){
        cin>>a>>b;
        counter=0;
        for(j=l;j<=r;j++){
            v[j]++;
        }
    }
    return 0;
}