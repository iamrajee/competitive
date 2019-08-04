#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int i,j,k,flag,ctr;
long long int sum,t;
int a,b,c,d;

vector <int> v;
set <int> st;


int main(){
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    j=i/2;
    auto itr=v.begin();
    while(j--){
        itr++;
    }
    j=i/2;
    while(k--){
        v[j]++;
        sort(itr, v.end());
    }
    cout<<v[j]<<endl;
    return 0;
}
