#include<bits/stdc++.h>
using namespace std;

long long int n1,n2,c,d1,d2,r;
int main(){
    cin>>n1>>n2>>c;
    d1=n1%c;
    d2=n2%c;
    n1 = n1/c;
    n2=n2/c;
    r=n1+n2;
    if((int)(d1+d2)/c == 1){
        if(d1>d2){
            cout<<r+1<<" "<<c-d1<<endl;
        }else{
            cout<<r+1<<" "<<c-d2<<endl;
        }
    }else{
        cout<<r<<" 0"<<endl;
    }
    return 0;
}