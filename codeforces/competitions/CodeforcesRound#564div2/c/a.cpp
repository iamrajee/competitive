#include<bits/stdc++.h>
using namespace std;

int n,i,j,w,t,k,a;
int x,l,r,sd;
vector <int> v;
vector <int> v2;
// bool sortfn(const int & a, const int & b){   
//     return (a > b);
// }
int main(){
    cin>>n;
    cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        cout<<t<<" ";
        v.push_back(t);
    }
    cout<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        cout<<t<<" ";
        v2.push_back(t);
    }
    cout<<endl;
    return 0;
}