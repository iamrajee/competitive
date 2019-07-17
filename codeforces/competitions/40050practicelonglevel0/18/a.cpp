#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,counter;
int a,b,t,q,l,r;

vector <int> v(200001,0);
multiset <pair<int,int> > ms;
int main(){
    cin>>n>>k>>q;
    
    for(i=0;i<n;i++){
        cin>>l>>r;
        for(j=l;j<=r;j++){
            if(v[j]<k){
                v[j]++;
            }
        }
        ms.insert({l,r});
    }
    for(i=0;i<q;i++){
        cin>>a>>b;
        counter=count(v.begin()+a,v.begin()+b+1,k);
        cout<<counter<<endl;
    }
    return 0;
}