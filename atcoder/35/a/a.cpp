#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t;
char c;
string s;
vector <int> v;
int main(){
    cin>>n;
    cin>>a;
    v.push_back(a);
    cin>>a;
    v.push_back(a);
    for(i=2;i<n;i++){
        cin>>a;
        v.push_back(a);

        if((v[i-2]^v[i]) != v[i-1]){
            cout<<"No"<<endl;
            return 0;
        }

    }
    if((v[1]^v[n-1]) != v[0] || (v[0]^v[n-2]) != v[n-1]){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}