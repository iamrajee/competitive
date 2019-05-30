#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t;
vector <int> v;
int main(){
    cin>>n;
    while(n!=0){
        cout<<n<<endl;

        cin >>t;
        while(t!=0){
            v.clear();
            v.push_back(t);
            for(i=0;i<n-1;i++){
                cin >>t;
                v.push_back(t);
            }
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<endl;
            cin >>t;
        }
        cin>>n;
    }
    return 0;
}