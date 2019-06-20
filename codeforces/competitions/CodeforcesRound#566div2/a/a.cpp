#include<bits/stdc++.h>
using namespace std;

int n,t;
int main(){
    cin>>n;
    if(n%2==0){
        cout<<(1<<(n/2))<<endl;
    }else{
        cout<<"0"<<endl;
    }
    return 0;
}