#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t,k,a;
// string s;
int x,y,y_,yt,l,r;
set <pair<int,int> > s;
set <pair<int,int> >::iterator itr;
int b,c;
int main(){
    cin>>n>>m;
    cout<<n<<m<<endl;
    b = 1<<31;
    for(i=0;i<n;i++){
        cin>>l>>r;
        // cout<<l<<r<<endl;
        s.insert({l,r});
    }
    // for(auto it:s){
        // cout<<it.first<<it.second<<endl;
    // }
    // for(itr=s.begin();itr!=s.end();itr++){
        // 
    // }
    for(i=0;i<m;i++){
        cin>>x>>y;
        // cout<<x<<y<<endl;
        c=0;
        y_ = x;
        yt = x;
        for(auto it:s){
            // cout<<it.first<<it.second<<endl;
            if(it.first-1<x && x<it.second){
                if(y<it.second+1){
                    // y_= y;
                    c=1;
                    break;
                }else if(y_<it.second){
                    // c++;
                    c=1;
                    y_= it.second;
                }
            }else if(it.first-1<y_ && y_<it.second){
                c=2;
                if(y<it.second+1){
                    // c++;
                    break;
                }else if(yt<it.second){
                    // c++;
                    yt= it.second;
                }
            }
        }
    }
    return 0;
}