#include<bits/stdc++.h>
using namespace std;

int n,i;
long long int sum;
long long int pre,A,B,curr;
long long int t;
vector <long long int> v; //!!!
int main(){
    cin>>n;
    for(i=0;i<n+1;i++){
        cin>>t;
        v.push_back(t);
    }
    sum=0;
    pre=0;
    for(i=0;i<n;i++){
        cin>>t;
        A = v[i]-pre;
        B=t;
        curr=min(A,B);
        pre = min(max(B-A,(long long int)0),v[i+1]); //!!!!
        sum+=(curr+pre);
    }
    cout<<sum<<endl;
    return 0;
}