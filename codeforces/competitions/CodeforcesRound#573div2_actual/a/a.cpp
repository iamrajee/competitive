#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t,s;
int T,x;
int main(){
    cin>>x;
   int md = x%4;
   if(md==0){
       cout<<"1 A"<<endl;
   }else if(md==2){
       cout<<"1 B"<<endl;
   }else if(md==3){
       cout<<"2 A"<<endl;
   }else{
       cout<<"0 A"<<endl;
   }
   
    return 0;
}