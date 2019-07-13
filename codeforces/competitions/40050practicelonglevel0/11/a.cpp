#include<bits/stdc++.h>
using namespace std;

int n;
int i,j;
long long int counter;
int t;
// vector <int> v;
// vector <int> vo;
// vector <int> ve;
// map <int,vector <int>> mp;
map <int,int> mp2;
int main(){
    cin>>n;
    counter=0;
    vector <int> twop;
    // vector <int> r;
    // set <int> st;
    for(i=1;i<=1000000000;i=i<<1){
        twop.push_back(i);
    }
    for(j=0;j<n;j++){
        cin>>t;
        
        if(!(mp2.count(t)>0)){
            mp2[t]=0;
        }else{
            counter+=mp2[t];
        }
        
        for(auto it:twop){
            if(it>=t){
                // r.push_back(it-t);
                if(!(mp2.count(it-t)>0)){
                    mp2[it-t]=1;

                }else{
                    mp2[it-t]++;
                }
            }
        }
        
        // counter+=count(r.begin(),r.end(),t);
        // if(!(mp2.count(t)>0)){
        //     mp2[t]=1;
        //     for(auto it:twop){
        //         if(it>=t){
        //             r.push_back(it-t);
        //         }
        //     }
        // }else{
        //     mp2[t]++;
        // }
        
        
        
        // for(auto it:v){
        //     if(((it+t)&(it+t-1))==0){
        //         counter++;
        //         mp[it].push_back(t);
        //     }
        // }
        // v.push_back(t);

        // if(t%2==0){
        //     for(auto it:ve){
        //         // if(ceil(log2(it+t))==floor(log2(it+t))){
        //         if(((it+t)&(it+t-1))==0){
        //             counter++;
        //         }
        //     }
        //     ve.push_back(t);
        // }else{
        //     for(auto it:vo){
        //         //if(ceil(log2(it+t))==floor(log2(it+t))){
        //         if(((it+t)&(it+t-1))==0){
        //             counter++;
        //         }
        //     }
        //     vo.push_back(t);
        // }
    }
    cout<<counter<<endl;
    return 0;
}