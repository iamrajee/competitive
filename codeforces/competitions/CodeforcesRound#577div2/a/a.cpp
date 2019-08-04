#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int i,j,k,flag,ctr;
long long int sum;
int a,b,c,d,e,t;
char ch;
string s;

vector <string> v;
set <int> st;
multiset <int> ms;
queue <int> q;
priority_queue <int> pq;
map <int,int> mp;

int main(){
    cin>>n>>m;
    v.resize(m,"");
    for(i=0;i<n;i++){
        cin>>s;
        for(j=0;j<m;j++){
            v[j]+=s[j];
        }
    }
    sum=0;
    for(j=0;j<m;j++){
        cin>>t;
        a=count(v[j].begin(),v[j].end(),'A');
        b=count(v[j].begin(),v[j].end(),'B');
        c=count(v[j].begin(),v[j].end(),'C');
        d=count(v[j].begin(),v[j].end(),'D');
        e=count(v[j].begin(),v[j].end(),'E');
        // cout<<a<<b<<c<<d<<e<<endl;
        sum+=(t*max(a,max(b,max(c,max(d,e)))));
    }
    cout<<sum<<endl;
    return 0;
}