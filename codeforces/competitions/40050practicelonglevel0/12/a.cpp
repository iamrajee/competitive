#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t;
char c;
string s;
vector <int> v;
set <int> st;
int mx,mxi;
int main(){
    cin>>n;
    vector <int> r(n+1,0);
    for(i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
        st.insert(t);
        vector <int> cl(n+1,0);
        mx=0;
        for(j=i;j>-1;j--){
            cl[v[j]]++;
            if(cl[v[j]]>mx || (cl[v[j]]==mx && v[j]<mxi)){
                mx=cl[v[j]];
                mxi=v[j];
            }
            r[mxi]++;
            // cout<<i<<","<<j<<"=>"<<max_element(cl.begin()+1,cl.end())-cl.begin()<<endl;
            // mx=0;    
            // for(auto it:st){
            //     if(cl[it]>mx){
            //         mx=cl[it];
            //         mxi=it;
            //     }
            // }
            // r[max_element(cl.begin(),cl.end())-cl.begin()]++;
        }
    }
    // for(i=0;i<n;i++){
    //     vector <int> cl(n+1,0);
    //     for(j=i;j<n;j++){
    //         cl[v[j]]++;
    //         // cout<<i<<","<<j<<"=>"<<max_element(cl.begin(),cl.end())-cl.begin()<<endl;
    //         r[max_element(cl.begin(),cl.end())-cl.begin()]++;
    //     }
    // }
    cout<<r[1];
    for(i=2;i<n+1;i++){
        cout<<" "<<r[i];
    }
    cout<<endl;
    return 0;
}