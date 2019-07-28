#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sumb,suma,counter;
int a,b,t;
// char c;
// string s;
set <int> st;
int main(){
    cin>>n;
    cin>>a;
    sumb=0;
    for(i=1;i<n-1;i++){
        cin>>t;
        sumb+=t;
        st.insert(t);
    }
    cin>>b;
    counter=n-2;
    suma=0;
    for(auto it:st){
        suma+=(counter*it);
        counter--;
    }
    
    cout<<a+suma+b+sumb<<endl;
    return 0;
}