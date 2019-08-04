#include<bits/stdc++.h>
using namespace std;

int n,m,g,T;
int i,j,k,flag,sum;
int a,b,t,h;
char c;
string s;
set <int> st;
vector <int> r;
vector <vector<int> > cl;
vector <pair<int,char> > gt;
int main(){
    cin>>T;
    int T_ = T;
    while(T_--){
        cl.clear();
        gt.clear();
        r.clear();
        cin>>n>>g>>m;
        cl.resize(n+1);
        r.resize(g,0);
        // gt.resize(g);
        for(i=0;i<g;i++){
            cin>>h>>c;
            gt.push_back({h,c});
        }

        while(m--){
            st.clear();
            for(i=0;i<g;i++){
                auto it = gt[i];
                if(it.second=='C'){
                    if(it.first==n){
                        it.first=1;
                    }else{
                        it.first++;
                    }
                }else{
                    if(it.first==1){
                        it.first=n;
                    }else{
                        it.first--;
                    }
                }
                if(st.find(it.first)==st.end()){
                    st.insert(it.first);
                    cl[it.first].clear();
                }
                cl[it.first].push_back(i+1);
            }
        }
        
        for(auto it:cl){
            for(auto it2:it){
                r[it2]++;
            }
        }

        cout<<"Case #"<<T-T_<<":";
        for(auto it:r){
            cout<<" "<<it;
        }
        cout<<endl;
    }
    return 0;
}