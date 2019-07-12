#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum;
int a,b,t,pre;
char c;
string s;
vector <int> v;
int main(){
    cin>>n;
    cin>>t;
    v.push_back(t);
    for(i=1;i<n;i++){
        cin>>t;

        if(t!=0){

            if( (t==1&&v[i-1]==1) || (t==2&&v[i-1]==2) ){
                t=0;
            }else if(t==3){
                if(v[i-1]==1){
                    t=2;
                }else if(v[i-1]==2){
                    t=1;
                }
                
            }
        }
        v.push_back(t);        
    }

    // for(auto it:v){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    cout<<count(v.begin(),v.end(),0)<<endl;
    return 0;
}