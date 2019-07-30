#include<bits/stdc++.h>
using namespace std;

int n,m,I;
int i,j,k,flag,sum,counter;
int a,b,t;
vector <int> v;
set <int> st;
int r,K,kmx,Kmx,mn,sum1,sum2,t1,t2;
map <int,int> mp;
int main(){
    cin>>n>>I;
    for(i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
        st.insert(a);
        if(mp.find(a)==mp.end()){
            mp[a]=1;
        }else{
            mp[a]++;
        }
    }
    K=(int)st.size();
    kmx=floor((float)((8*I)/n));
    // Kmx=pow(2,kmx+1)-1;
    Kmx=pow(2,kmx);
    // cout<<K<<kmx<<Kmx<<endl;
    if(K>Kmx){
        // cout<<"hi"<<endl;
        r=K-Kmx;
        mn=n;
        
        for(i=0;i<=r;i++){
            sum1=0;
            sum2=0;
            t1=i;
            auto it1=st.begin();
            while(t1--){
                sum1+=mp[*it1];
                it1++;
            }
            t2=r-i;
            auto it2=st.rbegin();
            while(t2--){
                sum2+=mp[*it2];
                it2++;
            }
            if(sum1+sum2<mn){
                mn=sum1+sum2;
            }
        }
        cout<<mn<<endl;
    }else{
        cout<<"0"<<endl;
    }

    return 0;
}