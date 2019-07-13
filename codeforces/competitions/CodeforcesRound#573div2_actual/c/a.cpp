#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,cnt;
int a,b,t,p;
vector <int> v;
set <int> st;
int main(){
    cin>>n>>m>>k;
    // vector <int> ()
    for(i=0;i<m;i++){
        cin>>p;
        v.push_back(p);
    }
    int pg1,pg2;
    int cnt=0;
    int dlt=0;
    for(auto it:v){
        pg1 = ceil((float)(it)/k);
        pg2 = ceil((float)(it-dlt)/k);
        dlt++;
        if(st.find(pg1)!=st.end()){
            // cnt++;
        }else{
            st.insert(pg1);
            cnt++;
        }
        if(pg2<pg1){
            cnt++;
        }
    }
    cout<<cnt<<endl;


    return 0;
}