#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t;
char c;
string s;
set <int> st;
// set <int>::iterator it;
int main(){
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>t;
        st.insert(t);
    }
    int mn = *st.begin();
    cout<<mn<<"*"<<endl;
    sum=0;
    for(auto it=st.rbegin(); it!=st.rend(); it++){
        if(*it>mn){
            
        }
        cout<<*it<<endl;
    }
    return 0;
}