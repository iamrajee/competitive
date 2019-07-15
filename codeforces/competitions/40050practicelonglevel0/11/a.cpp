#include<bits/stdc++.h>
using namespace std;

int n;
int i,j;
long long int counter;
int t;
map <int,int> mp2;
int main(){
    cin>>n;
    counter=0;
    vector <int> twop;
    for(i=1;i<=1000000000;i=i<<1){
        twop.push_back(i);
    }
    for(j=0;j<n;j++){
        cin>>t;
        if(mp2.count(t)>0){
            counter+=mp2[t];
        }   
        for(auto it:twop){
            if(it>t){
                if(!(mp2.count(it-t)>0)){
                    mp2[it-t]=1;
                }else{
                    mp2[it-t]++;
                }
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}