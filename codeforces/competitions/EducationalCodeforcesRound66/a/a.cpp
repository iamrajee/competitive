#include<bits/stdc++.h>
using namespace std;

int n,i;
long long int t,a,b,c;
int main(){
    cin>>n;
    // cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>a>>b;
        // cout<<a<<b<<endl;
        c=0;
        while(a>b-1){
            t = a%b;
            if(t==0){
                c++;
                a=a/b;
            }else{
                c+=t+1;
                a=(a-t)/b;
            }
        }
        c+=a%b;
        cout<<c<<endl;
    }
    return 0;
}