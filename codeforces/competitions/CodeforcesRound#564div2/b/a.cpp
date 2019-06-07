#include<bits/stdc++.h>
using namespace std;

int n,m,r,c;
int main(){
    cin>>n;
    // cout<<n<<endl;
    if(n%2==0){
        m = (n+2)/2;
        cout<<m<<endl;
    }else{
        m = (n+1)/2;
        cout<<m<<endl;
    }
    r=1;
    while(n>0 && r < m+1){
        cout<<r<<" "<<"1"<<endl;
        n--;
        r++;
    }
    c=2;
    while(n>0 && c < m+1){
        cout<<m<<" "<<c<<endl;
        n--;
        c++;
    }
    return 0;
}