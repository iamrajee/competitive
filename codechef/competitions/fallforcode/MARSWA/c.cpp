#include<bits/stdc++.h>
using namespace std;

int i,t;
int t1,t2,x,d;
long long int s1,s2,a;
int main(){
    cin>>t;
    // cout<<n<<endl;
    for(i=0;i<t;i++){
        cin>>s1>>s2>>t1>>t2;
        cin>>x;

        // d = s1/(1<<(t1-1));
        // cout<<d*(1<<(x-1))<<endl;

        // d = s1/pow(2,t1-1);
        if(x>t1){
            a=s1*pow(2,x-t1);
            cout<<a<<endl;
        }else{
            a=s1/pow(2,t1-x);
            cout<<a<<endl;
        }
        // cout<<s1/pow(2,t1-1)*pow(2,x-1)<<endl;

    }
    return 0;
}