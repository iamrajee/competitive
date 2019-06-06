#include<bits/stdc++.h>
using namespace std;

int n,i,j,t,k,a;
string s;
int x=0;
vector <int> v;
bool sortfn(const int & a, const int & b){   
    return (a > b);
}
int main(){
    cin>>t;
    cout<<t<<endl;
    for(i=0;i<t;i++){
        v.clear();
        cin>>n>>k;
        cout<<n<<" "<<k<<endl;
        for(j=0;j<n;j++){
            cin>>a;
            cout<<a<<" ";
            v.push_back(a);
        }
        for(j=0;j<n;j++){
            v[j]=abs(v[j]-x);
        }
        sort(v.begin(), v.end(),sortfn);
        cout<<endl;
        
    }
    return 0;
}