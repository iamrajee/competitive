#include<bits/stdc++.h>
using namespace std;

int n,i,j,t,n1,n2;
// long int t;
// vector <int> v;
// multiset <int> ms;
map <int,int> m;
// vector<int>::iterator it;
int idx;
int flag=0;
int main(){
    cin>>n;
    // cout<<n<<endl;
    vector <int> v(n-1,1);
    // memset(&v,1,sizeof(int)*(n-1));
    // fill(v.begin(),v.end(),1);
    for (i=2;i<n+1;i++){
        // idx = i-2;
        n1 = v[i-2];
        for(j=i+1;j<n+1;j++){
            n2 = v[j-2];
            if(j%i!=0 && n1==n2){
                v[j-2]++;
            }
        }
    }
    int flag=0;
    for(auto it:v){
        if(flag==0){
            cout<<it;
        }else{
            cout<<" "<<it;
        }
        flag=1;
    }
    cout<<endl;
    return 0;
}