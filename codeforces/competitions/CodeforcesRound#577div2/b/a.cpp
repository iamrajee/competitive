#include<bits/stdc++.h>
using namespace std;

int n,m,T;
int i,j,k,flag,ctr;
long long int sum,t;
int a,b,c,d;

vector <int> v;
set <int> st;


int main(){
    cin>>n;
    sum=0;
    for(i=0;i<n;i++){
        cin>>t;
        // st.insert(t);
        v.push_back(t);
        sum+=t;
    }
    sort(v.begin(), v.end());
    if(sum%2==1){
        cout<<"NO"<<endl;
    }else{

        while(v[n-2]!=0){
            d=v[n-1]-v[n-2];
            v[n-1]=d;
            v[n-2]=0;
            sort(v.begin(), v.end());
        }
        if(v[n-1]!=0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }

    }
    return 0;
}