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
set <int> st2;
multiset <int> ms;
queue <int> q;
priority_queue <int> pq;
map <int,int> mp;

int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
        // v.push_back(t);
        st.insert(t);
    }

    cin>>m;
    for(i=0;i<m;i++){
        cin>>t;
        // v.push_back(t);
        st2.insert(t);
    }

    cout<<*(--st.end())<<" "<<*(--st2.end())<<endl;
    return 0;
}