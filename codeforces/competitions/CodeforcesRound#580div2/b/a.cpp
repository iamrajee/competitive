#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int i,j,k,flag,ctr;
long long int sum,t;
int a,b,c,d;
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
    sum=0;
    flag=1;
    ctr=0;
    for(i=0;i<n;i++){
        cin>>t;
        // v.push_back(t);
        if(t>0){
            sum+=(t-1);
        }else if(t<0){
            sum+=(-1-t);
            flag=-flag;
        }else{
            sum++;
            ctr++;
        }
    }
    if(flag>0){
        cout<<sum<<endl;
    }else{
        if(ctr>0){
            cout<<sum<<endl;
        }else{
            cout<<sum+(long long int)2<<endl;
        }
    }
    return 0;
}