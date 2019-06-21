#include<bits/stdc++.h>
using namespace std;

int i,j,w,k,p,t;
int n,m;
vector <int> v;
int mx,xr;
int main(){
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n>>k;
        v.clear();
        // for(j=0;j<n;j++){
        //     cin>>p;
        //     v.push_back(p);
        // }
        // mx=0;
        // for(j=0;j<n-(k-1);j++){
        //     xr=0;
        //     for(w=j;w<j+k;w++){
        //         // cout<<v[w];
        //         xr^=v[w];
        //     }
        //     if(xr>mx){
        //         mx=xr;
        //     }
        //     // cout<<endl;
        // }
        // cout<<mx<<endl;


        // mx=0;
        // for(j=k-1;j<n;j++){
        //     xr=0;
        //     // cout<<j<<endl;
        //     for(w=j;w>j-k;w--){
        //         cout<<w;
        //         cin>>p;
        //         // cout<<p;
        //         xr^=p;
        //     }
        //     cout<<endl;
        //     if(xr>mx){
        //         mx=xr;
        //     }
        // }
        // cout<<mx<<endl;

        mx=0;
        xr=0;
        for(w=j;w>j-k;w--){
            cin>>p;
            v.push_back(p);
            xr^=p;
        }
        mx = xr;
        for(j=k;j<n;j++){
            cin>>p;
            v.push_back(p);
            xr=xr^v[j-k]^v[j];
            // cout<<j<<endl;
            
            // cout<<endl;
            if(xr>mx){
                mx=xr;
            }
        }
        cout<<mx<<endl;

    }
    return 0;
}