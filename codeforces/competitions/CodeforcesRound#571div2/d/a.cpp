#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int b,t;
float a;
vector <int> v;
set <int> s;
int main(){
    cin>>n;
    sum=0;
    for(i=0;i<n;i++){
        cin>>a;
        t = floor(a);
        v.push_back(t);
        if(a==t){
            s.insert(i);
        }
        sum+=t;
    }
    // cout<<"s:"<<sum<<endl;
    for(i=0;i<n;i++){
        if( sum!=0 && s.find(i)==s.end()){
            cout<<v[i]+1<<endl;
            sum++;
        }else{
            cout<<v[i]<<endl;
        }
    }
    return 0;
}