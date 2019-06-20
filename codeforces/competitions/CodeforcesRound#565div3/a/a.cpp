#include<bits/stdc++.h>
using namespace std;

int i,j,q,flag,c;
long long int n;
int main(){
    cin>>q;
    // cout<<q<<endl;

    for(i=0;i<q;i++){
        cin>>n;
        // cout<<n<<endl;
        flag=0;
        c=0;
        if(n==1){
            cout<<"0"<<endl;
        }else{
            while(n>1){
                c++;
                if(n%2==0){
                    n=n/2;
                }else if(n%3==0){
                    n=2*n/3;
                }else if(n%5==0){
                    n=4*n/5;
                }else{
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                cout<<"-1"<<endl;
            }else{
                cout<<c<<endl;
            }
        }
    }
    return 0;
}