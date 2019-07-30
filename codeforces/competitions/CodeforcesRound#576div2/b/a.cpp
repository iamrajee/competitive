#include<bits/stdc++.h>
using namespace std;

long long int h,l;
int main(){
    cin>>h>>l;
    // cout<<(l+h)*(l-h)/(2*h)<<endl;
    printf("%.6f\n",(double)((l+h)*(l-h))/(2*h));
    return 0;
}