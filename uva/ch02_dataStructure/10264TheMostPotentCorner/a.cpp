#include<bits/stdc++.h>
using namespace std;

int n,i,i2,i3,j,j2,k,t,t2;
map <int,int> m;
int sum,maxsum;
vector <pair<int,int> > v;

bool softfn(const pair<int,int>& a, const pair<int, int>& b){
    return (a.second > b.second);
}

int main()
{  
    while(cin>>n){
        // cout<<"****"<<n<<"****"<<endl;
        v.clear();
        m.clear();
        for(i=0; i<(1<<n); i++){
            cin>>t;
            // cout<<t<<endl;
            m[i]=t;
            v.push_back({i,t});
        }
        // sort(v.begin(),v.end(),softfn);
        // for (auto it:m){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // for (auto it:v){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        maxsum=0;
        for(i=0; i<(1<<n); i++){
            for(j2=0; j2<n; j2++){
                if(!(i&(1<<j2))){
                    i2=i^(1<<j2);
                    sum=0;
                    // cout<<"\n"<<"i:"<<i;
                    for(j=0;j<n;j++){
                        // t=i^(1<<j);//toggle jth bit of i
                        // cout<<" "<<t;
                        // t=i^(1<<j);
                        sum+=m[i^(1<<j)];
                        sum+=m[i2^(1<<j)];
                    }
                    if(sum>maxsum){
                        maxsum=sum;
                    }
                }
            }
        }
        cout<<maxsum<<endl;

    }
    return 0;
}