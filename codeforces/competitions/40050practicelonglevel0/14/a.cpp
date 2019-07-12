#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum;
int a,b,d,p,t;
set <int> st;
int main(){
    cin>>n>>p;
    vector <int> v(n+1,0);
    vector <pair<int,int>> w(n+1,{0,0});
    for(i=0;i<p;i++){
        cin>>a>>b>>d;
        v[a]++;
        v[b]--;
        w[a].first=b;
        w[a].second=d;
    }
    cout<<count(v.begin(),v.end(),1)<<endl;
    for(i=1;i<n+1;i++){
        if(v[i]==1){
            st.clear();
            st.insert(w[i].second);
            b=w[i].first;
            while(v[b]!=-1){
                st.insert(w[b].second);
                b = w[b].first;
            }
            cout<<i<<" "<<b<<" "<<*st.begin()<<endl;
        }
    }
    return 0;
}