#include<bits/stdc++.h>
using namespace std;

int i,j,T,D,ac,pc,px,px_;
string s;
int main(){
    cin>>T;
    // cout<<T<<endl;
    for(i=0;i<T;i++){
        cin>>D;
        // cout<<D<<endl;
        cin>>s;
        // cout<<s<<endl;
        pc = count(s.begin(),s.end(),'P');            
        px = ceil((float)(0.75*D-pc));
        px_ = px;
        for(j=2;(j<D-2) && px>0;j++){
            if(s[j]=='A'){
                // cout<<j<<"flag1"<<endl;
                if(s[j-2]=='P' || s[j-1]=='P'){
                    // cout<<j<<"flag2"<<endl;
                    if(s[j+1]=='P' || s[j+2]=='P'){
                        // cout<<j<<"flag3"<<endl;
                        px--;
                    }
                }
            }
        }
        if(px==0){
            cout<<px_<<endl;
        }else if(px<0){
            cout<<"0"<<endl;
        }else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}