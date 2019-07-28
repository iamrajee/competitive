#include<bits/stdc++.h>
using namespace std;

int n;
int i,counter,t;
int main(){
    cin>>n;
    counter=0;
    for(i=1;i<n+1;i++){
        cin>>t;
        if(t!=i){
            counter++;
        }
    }
    if(counter>2){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}