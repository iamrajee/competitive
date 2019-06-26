#include<bits/stdc++.h>
using namespace std;

int N,n,m,i,j,t,k,a,c,f1,f2,f3;
vector <int> d(INT32_MAX,-1);
map <int,int> ml;
map <int,int> ms;
map <int,int> mr;
int fn(int n){
    if(d[n]!=-1){
        return d[n];
    }else{
        if(n==1){
            return f1;
        }else if(n==2){
            return f2;
        }else if(n==3){
            return f3;
        }else{
            return fn(n-1)*fn(n-2)*fn(n-3);
        }
    }
}
int main(){
    ml[1]=4;
    ml[2]=1;
    ml[3]=2;
    ml[4]=3;

    ms[1]=3;
    ms[2]=4;
    ms[3]=1;
    ms[4]=2;

    mr[1]=2;
    mr[2]=3;
    mr[3]=4;
    mr[4]=1;

    for(i=0;i<4;i++){
        cin>>l>>s>>r>>p;
    }

    return 0;
}