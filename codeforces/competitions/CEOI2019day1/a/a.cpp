#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int i,j,k,t,r,c;
set <pair<int,int> > st;
set <pair<int,int> > st2;
queue <pair<int,int> > qu;
int main(){
    cin>>n;
    cin>>t;
    for(i=0;i<n;i++){
        cin>>r>>c;
        st.insert({r,c});
        qu.push({r,c});

    }

    for(auto it:st){
        r=it.first;
        c=it.second;
        // cout<<r<<c<<endl;
        if(st.find({r+1,c+1})==st.end() && st.find({r-1,c-1})==st.end() && st.find({r+1,c-1})==st.end() && st.find({r-1,c+1})==st.end() && st.find({r+1,c})==st.end() && st.find({r-1,c})==st.end() && st.find({r,c+1})==st.end() && st.find({r,c-1})==st.end()){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    
    cout<<"YES"<<endl;
    if(t==1){
        r=qu.front().first;
        c=qu.front().second;
        st2.insert({r,c});
        qu.pop();
        while(qu.empty()!=1){
            r=qu.front().first;
            c=qu.front().second;
            qu.pop();
            if(st2.find({r+1,c+1})==st2.end() && st2.find({r-1,c-1})==st2.end() && st2.find({r+1,c-1})==st2.end() && st2.find({r-1,c+1})==st2.end() && st2.find({r+1,c})==st2.end() && st2.find({r-1,c})==st2.end() && st2.find({r,c+1})==st2.end() && st2.find({r,c-1})==st2.end()){
                qu.push({r,c});
            }else{
                
            }
        }
    }else{

    }
    
    return 0;
}