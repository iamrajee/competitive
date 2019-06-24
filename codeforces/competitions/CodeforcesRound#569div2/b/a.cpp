#include<bits/stdc++.h>
using namespace std;

int n;
int flag=0;
int i,j;
int t;
int e=1;
// char c;
// string s;
vector <int> v;
// multiset <int> ms;
multiset <int> msp;
multiset <int> msn;
long long int pn,pp,pn_,pp_;
int nr,pr,fn,fp;
int main(){
    cin>>n;
    pp=1;
    pn=1;
    pp_=1;
    pn_=1;
    fn=0;
    fp=0;
    for(i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
        if(t==0 || e==-1){
            e=-e;
        }else if(t<0){
            msn.insert(-t);
            pn*=t;
            // pn_*=(-t-1);
        }else{
            msp.insert(t);
            pp*=t;
            pp_*=(-t-1);
        }
    }
    pn_=pn;
    if(pp_*pn_*e>0){
        // cout<<"hi"<<endl;
        flag=0;
        for(auto it:v){
            if(flag==0){
                if(it>-1){
                    cout<<(-it-1);
                }else{
                    cout<<it;
                }
                flag=1;
                continue;
            }
            if(it>-1){
                cout<<" "<<(-it-1);
            }else{
                cout<<" "<<it;
            }
        }
    }else{
        //  cout<<"hi"<<endl;
        for(auto it:msn){
            if(it!=1){//neg
                nr=-it;
                fn=1;
                break;
            }
        }
        for(auto it:msp){
            pr=it;
            fp=1;
            break;
        }

        if(fn==1 && fp==1){
            if(e*(pp_/pr*(-pr-1))*pn_ > e*pp_*(pn_/nr*(-nr-1))){
                fn=0;
            }else{
                fp=0;
            }
        }

        if(fp==1){
            flag=0;
            for(auto it:v){
                if(flag==0){
                    if(it>-1 && it!=pr){
                        cout<<(-it-1);
                    }else{
                        cout<<it;
                    }
                    flag=1;
                    continue;
                }
                if(it>-1 && it!=pr){
                    cout<<" "<<(-it-1);
                }else{
                    cout<<" "<<it;
                }
            }
        }else if(fn==1){
            flag=0;
            for(auto it:v){
                if(flag==0){
                    if(it>-1 || it==pn){
                        cout<<(-it-1);
                    }else{
                        cout<<it;
                    }
                    flag=1;
                    continue;
                }
                if(it>-1 || it==pn){
                    cout<<" "<<(-it-1);
                }else{
                    cout<<" "<<it;
                }
            }
        }else{
            //  cout<<"hi"<<endl;
             flag=0;
            for(auto it:v){
                if(flag==0){
                    // if(it>-1 && it!=pr){
                    //     cout<<(-it-1);
                    // }else{
                    //     cout<<it;
                    // }
                    cout<<it;
                    flag=1;
                    continue;
                }
                // if(it>-1 && it!=pr){
                //     cout<<" "<<(-it-1);
                // }else{
                //     cout<<" "<<it;
                // }
                cout<<" "<<it;
            }
        }
    }
    cout<<endl;
    return 0;
}