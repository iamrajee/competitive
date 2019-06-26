#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t;
char c;
int l,r,x,ax;
string s;
vector <int> v;

void fn(vector <int> v_){
    sort(v_.begin()+l-1, v_.begin()+r);
    // cout<<*v_.begin()<<endl;
    // for(auto it:v_){
    //     cout<<it;
    // }
    // cout<<" "<<v_[x]<<ax<<endl;
    if(v_[x]==ax){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    for(i=0;i<m;i++){
        cin>>l>>r>>x;
        x--;
        ax = v[x];
        fn(v);
        // for(auto it:v){
        //     cout<<it;
        // }
        // cout<<endl;
    }
    return 0;
}