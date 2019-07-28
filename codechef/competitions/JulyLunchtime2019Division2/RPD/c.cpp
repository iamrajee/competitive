#include<bits/stdc++.h>
using namespace std;

int i,j,T;
int a,t;
int n,sum,mx;
vector <int> v;

void fn(int d){
    sum=0;
    while(d>0){
        sum+=(d-(d/10)*10);
        d/=10;
    }
    if(sum>mx){
        mx=sum;
    }
}

int main(){
    cin>>T;
    for(i=0;i<T;i++){
        cin>>n;
        mx=0;

        cin>>a;
        v.push_back(a);
        for(j=1;j<n;j++){
            cin>>a;

            for(auto it:v){
                fn(it*a);
            }

            v.push_back(a);
        }
        cout<<mx<<endl;
    }
    return 0;
}