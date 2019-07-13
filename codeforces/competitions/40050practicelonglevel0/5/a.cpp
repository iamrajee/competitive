#include<bits/stdc++.h>
using namespace std;

int n;
int i,j;
long int sum;
int a,w;
vector <int> v;
set <int> st;
int main(){
    cin>>n>>w;
    sum=0;
    for(i=0;i<n;i++){
        cin>>a;
        sum+=a;
        v.push_back(sum);
        st.insert(sum);
    }
    int mn = *st.begin();
    int mx = *st.rbegin();

    if(abs(mn)>w || abs(mx)>w || mx-mn>w){
        cout<<"0"<<endl;
    }else{
        if(mn<0){
            cout<<max(min(w-mx+mn,w+mn)+1,0)<<endl;
        }else{
            cout<<max(w-mx+1,0)<<endl;
        }
    }
    return 0;
}