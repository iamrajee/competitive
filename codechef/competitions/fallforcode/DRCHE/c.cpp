#include<bits/stdc++.h>
using namespace std;

int i,j,t;
int n,m;
int a,s,c,h;
bool f;
// vector <int> v;
multiset <int> ms;
// multiset <int>::iterator itr;
// auto itr;
// int fn(){
    // 
// }
int main(){
    cin>>t;
    for(i=0;i<t;i++){
        cin>>n;
        ms.clear();
        for(j=0;j<n;j++){
            cin>>a;
            ms.insert(a);
        }
        f=0;
        c=0;
        h=0;
        auto itr = ms.rbegin();
        c=count(ms.begin(),ms.end(),*itr);
        while((c!=(int)ms.size() || c==1) && *itr!=0){
            // cout<<*itr<<"-- ";
            for(auto it:ms){
                cout<<it<<" ";
            }
            cout<<","<<*itr<<",* "<<c<<">>"<<(int)ms.size()<<endl;
            if(c==1){
                if(f==0){
                    c+=*itr;
                }else{
                    h+=*itr;
                }
                ms.erase(*itr);
                ms.insert((*itr)/2);
            }else{
                while(c>0){
                    cout<<c<<endl;
                    ms.erase(*itr);
                    // itr++;WWWW
                    c--;
                }
            }
            f=!f;
            itr = ms.rbegin();
            c=count(ms.begin(),ms.end(),*itr);
        }
        cout<<"->"<<c<<" "<<h<<endl;
    }
    return 0;
}