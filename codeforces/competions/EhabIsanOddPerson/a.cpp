#include<bits/stdc++.h>
using namespace std;

int n,m,i,j;
long int t;
vector <int> v;
multiset <int> ms;
// vector<int>::iterator it;

int sum=0;
int sum1=0;
int sum2=0;
int flag=0;
int main(){
    cin>>n;
    // cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        // cout<<t<<" ";
        ms.insert(t);
    }
    int flag = 0;
    for(auto it:ms){
        if(flag==0){
            cout<<it;
        }else{
            cout<<" "<<it;
        }
        flag = 1;
    }
    cout<<endl;
    return 0;
}