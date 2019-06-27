#include<bits/stdc++.h>
using namespace std;

int n,q;
int i,j,k;
int a;
set <int> s;
int mn,mx;
int main(){
    cin>>q;
    for(i=0;i<q;i++){
        cin>>n>>k;
        s.clear();
        for(j=0;j<n;j++){
            cin>>a;
            s.insert(a);
        }
        mn=*s.begin();
        mx=*s.rbegin();
        if(mn+k-mx<=k && -k<=mn+k-mx){
            cout<<mn+k<<endl;
        }else{
            cout<<"-1"<<endl;
        }

    }
    return 0;
}