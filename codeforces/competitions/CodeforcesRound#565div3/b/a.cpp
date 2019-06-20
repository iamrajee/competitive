#include<bits/stdc++.h>
using namespace std;

int i,j,t,n,c,a,zc,oc,tc,result;
vector <int> v;
int main(){
    cin>>t;
    // cout<<t<<endl;
    for(i=0;i<t;i++){
        v.clear();
        cin>>n;
        // cout<<n<<endl;
        for(j=0;j<n;j++){
            cin>>a;
            // cout<<a<<" ";
            v.push_back(a%3);
            // ms.insert(a);
        }
        zc=count(v.begin(),v.end(),0);
        oc=count(v.begin(),v.end(),1);
        tc=count(v.begin(),v.end(),2);
        result=zc;
        if(tc>oc){
            result+=oc;
        }else{
            result+=tc;
            result+=((oc-tc)/3);
            // cout<<">"<<((oc-tc)/3)<<endl;
        }
        cout<<result<<endl;
    }
    return 0;
}