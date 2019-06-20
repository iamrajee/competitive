#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,t,flag,sum2;
int sum=0;
int c;
string s;
vector <int> v;
multiset <int> ms;
// multiset <int>::iterator itr;
// priority_queue <int> pq;
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>t;
        // cout<<"-->"<<t<<endl;
        c=0;
        sum2=sum;
        if(sum+t>m){
            auto itr=ms.rbegin();
            while(sum+t>m){
                sum-=*itr;
                c++;
                itr++;
            }
        }
        ms.insert(t);
        sum=sum2+t;
        cout<<c<<endl;
    }
    // for(i=0;i<n;i++){
    //     cin>>t;
    //     cout<<"-->"<<t<<endl;
    //     c=0;
    //     if(sum+t>m){
    //         v.clear();
    //         while(sum+t>m){
    //             sum-=pq.top();
    //             v.push_back(pq.top());
    //             pq.pop();
    //             c++;
    //         }
    //         for(j=0;j<(int)v.size();j++){
    //             pq.push(v[j]);
    //             sum+=v[j];
    //         }
    //     }
    //     cout<<c<<endl;
    //     pq.push(t);
    //     sum+=t;
    // }
    return 0;
}