#include<bits/stdc++.h>
using namespace std;

int n,k,q;
int i,j,counter;
long long int sum,a;
vector <int> v;
int sz;
int main(){
    cin>>q;
    for(i=0;i<q;i++){
        cin>>n>>k;
        v.clear();
        sum=0;
        // counter=k;
        for(j=0;j<n;j++){
            cin>>a;
            sum+=a;
            if(sum%2==1 && k>1){
                // cout<<"sum:"<<sum<<endl;
                k--;
                sum=0;
                v.push_back(j+1);
            }
            
        }
        // if(k%2==0 && sum%2 ==0){

        // }else if(k%2==1 && sum%2 ==1){
        if(sum%2==1 && k==1){
            v.push_back(n);
            cout<<"YES"<<endl;
            sz = (int)v.size();
            cout<<v[0];
            for(j=1;j<sz;j++){
                cout<<" "<<v[j];
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}