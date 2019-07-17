#include<bits/stdc++.h>
using namespace std;

long long int n,m,k,c,r;
int main(){
    cin>>n>>k;
    c = -2*(n+k);
    r=(sqrt(9-4*c)-3)/2;
    cout<<n-r<<endl;
    return 0;
}