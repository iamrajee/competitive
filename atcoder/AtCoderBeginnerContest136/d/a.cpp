#include<bits/stdc++.h>
using namespace std;

int n,m,q,T;
int i,j,k,flag,counter;
int a,b,t;
long long int sum;
char c;
string s;

vector <int> v;
vector <int> v2;
set <int> st;
multiset <int> ms;
map <int,int> mp;
int main(){
    cin>>s;
    n=(int)s.size();
    v.resize(n,1);
    v2.resize(n,1);
    bool notyet=1;
    while(notyet==1){
        notyet=0;
        for(i=0;i<n;i++){
            if(s[i]=='R'){
                v[i+1]+=min(1,v[i]);
            }else{
                v[i-1]+=min(1,v[i]);
            }
            v[i]=max(0,v[i]-1);
            if(i>0){
                if(v[i-1]!=v2[i-1]){
                    notyet=1;
                    v2[i-1]=v[i-1];
                }
            }else{
                if(v[0]!=v2[0]){
                    notyet=1;
                    v2[0]=v[0];
                }
            }
            
        }
        if(v[n-1]!=v2[n-1]){
            notyet=1;
            v2[n-1]=v[n-1];
        }
    }
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}