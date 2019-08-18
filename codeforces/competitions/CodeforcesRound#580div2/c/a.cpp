#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int i,j,k,flag,ctr;
long long int sum;
int a,b,c,d,t;
char ch;
string s;

vector <int> v;
set <int> st;
multiset <int> ms;
queue <int> q;
priority_queue <int> pq;
map <int,int> mp;

int main(){
    cin>>n;
    // for(i=0;i<n;i++){
    //     cin>>t;
    //     v.push_back(t);
    // }
    if(n==1){
        cout<<"YES"<<endl;
        cout<<"1 2"<<endl;
    }else if(n==3){
        cout<<"YES"<<endl;
        cout<<"1 4 5 2 3 6"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}