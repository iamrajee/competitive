#include<bits/stdc++.h>
using namespace std;

int m,q,T;
int i,j,k,flag,counter;
int a,b,t;
int sum,n;
int main(){
    cin>>n;
    int d=floor(log10(n)+1);
    sum=0;
    if(d%2==1){
        sum+=(n-pow10(d-1)+1);
        d-=2;
    }else{
        d--;
    }

    while(d>0){
        sum+=(9*pow10(d-1));
        d-=2;
    }
    cout<<sum<<endl;
    return 0;
}