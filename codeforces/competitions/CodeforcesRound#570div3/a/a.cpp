#include<bits/stdc++.h>
using namespace std;

int n,a,s;
int fn(int x){
    int d=0;
    while(x!=0){
        d+=x-(x/10)*10;
        x=x/10;
    }
    // cout<<"==>"<<d<<endl;
    return d;
}
int main(){
    cin>>n;
    // n=a;
    // m=a%4;
    // if(m==0){
    //     coux!=0t<<a<<endl;
    // }else{   x/10;
    //     d=ceil(a/10)*10-a;
    //     // d=(a/10 + 1)*10 - a;
    // }
    // d=fn();
    while(fn(n)%4!=0){
        n++;
        // cout<<n<<endl;
    }
    cout<<n<<endl;
    return 0;
}