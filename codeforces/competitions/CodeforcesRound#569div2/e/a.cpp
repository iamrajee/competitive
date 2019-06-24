#include<bits/stdc++.h>
using namespace std;

int N,n,m,i,j,t,k,a,c,f1,f2,f3;
vector <int> d(INT32_MAX,-1);
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
    cin>>N>>f1>>f2>>f3>>c;
    cout<<N<<f1<<f2<<f3<<c<<endl;
    // fn(N);
    cout<<pow(2,8)<<endl;
    return 0;
}