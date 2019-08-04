#include<bits/stdc++.h>
using namespace std;

int n,m,q,T;
int i,j,k,flag,counter;
int a,b,d,t;
long long int sum;
char c;
string s;

vector <int> v;
set <int> st;
multiset <int> ms;
map <int,int> mp;
int mx;
int main(){
    cin>>n;
    // v.push_back(t);
    mx=0;
    for(i=0;i<n;i++){
        cin>>t;
        // d=t-v[i-1];
        // cout<<mx<<" "<<t<<endl;
        mx=max(mx,t);
        if(mx-t>1){
            cout<<"No"<<endl;
            return 0;
        }
        // if(d<-1){
            // cout<<"No"<<endl;
            // return 0;
        // }
        v.push_back(t);
    }
    cout<<"Yes"<<endl;
    return 0;
}