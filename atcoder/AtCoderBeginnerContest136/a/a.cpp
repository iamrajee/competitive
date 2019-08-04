#include<bits/stdc++.h>
using namespace std;

long long int n,m,sum;
int main(){
    cin>>n>>m;
    sum = n+m;
    if(sum%2==0){
        cout<<sum/2<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}