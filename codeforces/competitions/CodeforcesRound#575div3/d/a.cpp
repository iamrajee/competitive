#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,suma,sumb,count;
int a,b,t;
map <int,int> ca;
map <int,int> cb;
string sa="";
string sb="";
int main(){
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        ca.clear();
        cb.clear();
        sa="";
        sb="";
        flag=0;
        for(j=0;j<n;j++){
            ca[j]=0;
            cb[j]=0;
        }
        for(j=0;j<n;j++){
            cin>>a;
            ca[a]++;
            sa+=to_string(a);
        }
        for(j=0;j<n;j++){
            cin>>b;
            cb[b]++;
            sb+=to_string(b);
        }
        for(j=0;j<n;j++){
            if(ca[j]!=cb[j]){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==1){
            continue;
        }
        if(stoi(sa)<stoi(sb)){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}