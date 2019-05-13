#include<bits/stdc++.h>

using namespace std;
int n,k,t,i,j,s,b,l,r;
// priority_queue <int> pq;

multiset<int> ms;
multiset <int, greater <int> > :: iterator itr;

multiset <int, greater <int> > :: iterator posl;
multiset <int, greater <int> > :: iterator posr;
multiset <int, greater <int> > :: iterator it;

// auto posl;
// auto posr;
void printset(){
    cout<<"   set=>";
    for (itr = ms.begin(); itr != ms.end(); ++itr){ cout << '\t' << *itr; }
    cout<<endl;
}
void L(){
    if(l>1){
        posl = ms.find(l-1);
        if(*posl==l-1){
            if(*(++posl)!=l-1){
                --posl;
            }
            l = *(--posl);
            // cout<<"new_l:"<<l<<endl;
            L();
        }else{
            // cout<<"l:"<<l-1;
            cout<<l-1<<" ";
        }
    }else{
        // cout<<"l:*,";
        cout<<"* ";
    }
}
void R(){
    if(r<s){
        posr = ms.find(r+1);
        if(*posr==r+1 && ms.size()!=2){
            r = *(++posr);
            R();
            // if(*(++posr)!=r+1){
            //     --posr;
            //     r = *(++posr);
            //     // cout<<"new_r:"<<r<<",s:"<<s<<", mssize:"<<ms.size()<<endl;
            //     R();
            // }
            // else{
            //     cout<<" (r):*"<<endl;
            //     // r = *(++posr);
            //     // cout<<"new_r:"<<r<<endl;
            //     // R();
            // }
            
        }else{
            // cout<<" r:"<<r+1<<endl;
            cout<<r+1<<endl;
        }
    }else{
        // cout<<" r:*"<<endl;
        cout<<"*"<<endl;
    }
}
void f(){
    ms.insert(l);
    ms.insert(r);
    //printset();
    L();
    R();
    // cout<<endl;
    // auto posl = ms.find(l);
    // auto posr = ms.find(r);
    // cout<< *posl<<","<<*posr  <<endl;

    // cout<<"find:"<<*posl<<","<<*posr<<endl;

}
int main()
{   
    cin>>s>>b;
    // cout<<s<<" "<<b<<endl;
    while(s!=0 && b!=0){
        ms.clear();
        for(i=0;i<b;i++){
            cin>>l>>r;
            // cout<<l<<" "<<r;
            f();
        }
        cout<<"-"<<endl;
        cin>>s>>b;
        // cout<<s<<" "<<b<<endl;
    }
    return 0;
}