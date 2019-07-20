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
    sum=0;
    int sum2=0;
    cin>>a;
    sum2+=a;
    v.push_back(1);
    sum+=a;
    for(i=1;i<n;i++){
        cin>>t;
        sum+=t;
        if(a>=2*t){
            //cout<<"hi"<<endl;
            sum2+=t;
            v.push_back(i+1);
        }
    }
    //cout<<sum2<<sum<<endl;
    if(sum2*2>sum){
        int sz = (int)v.size();
        cout<<sz<<endl;
        cout<<v[0];
        for(i=1;i<sz;i++){
            cout<<" "<<v[i];
        }
        cout<<endl;
    }else{
        cout<<"0"<<endl;
    }
    return 0;
}
