#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,counter;
int a,b,t,s;
int T;
multiset <int> mso;
// multiset <int> mse;
int main(){
    cin>>n>>k;
    vector <int> v(k+1,0);    
    sum=ceil((float)n/2);
    counter=0;
    // cout<<"sum:"<<sum<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        v[t]++;
        v.push_back(t);
    }
    for(i=0;i<k+1;i++){
        if(v[i]!=0){
            m=v[i]%2;
            if(m==0){
                sum-=v[i]/2;
                counter+=v[i];
            }else{
                mso.insert(v[i]);
                // cout<<v[i]<<endl;
            }
            
        }
    }
    // cout<<"sum:"<<sum<<endl;
    for(auto it=mso.rbegin();it!=mso.rend() && sum!=0 ;it++){
        counter+=min(*it,sum*2);
        sum-=min((*it+1)/2,sum);
        // cout<<*it<<", v[i]: "<<*it<<", sum: "<<sum<<endl;
    }

    cout<<counter<<endl;
    return 0;
}