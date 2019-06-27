#include<bits/stdc++.h>
using namespace std;

int n,i,j,t;
vector <int> v;
int q,k,a,b,c,b_,a_,a_2,flag;
int main(){
    cin>>q;
    for(i=0;i<q;i++){
        cin>>k>>n>>a>>b;
        b_=0;
        a_=0;
        flag=0;
        if(a<k){
            a_ = ceil((float)(k-a)/a);
            // cout<<i<<"->"<<k<<" "<<k-a_*a<<" "<<a_<<endl;
            k=k-a_*a;//k>=1
        }
        if(b<k){
            b_ += ceil((float)(k-b)/b);
            // cout<<i<<"->"<<k<<" "<<k-b_*b<<" "<<b_<<endl;
            k=k-b_*b;//k>=1
        }
        c=a_+b_;
        if(c<n){
            // cout<<"-1"<<endl;
            // a_2=a_-1;
            // while(a_2>=0){
            //     k = k-a_2*a;
            //     if(b<k){
            //         b_ = ceil((float)(k-b)/b);
            //         k=k-b_*b;
            //     }
            //     if(a_2+b_>=n){
            //         cout<<a_2<<endl;
            //         flag=1;
            //         break;
            //     }
            //     a_2--;
            // }
            k=k - a_*a+b_*b;
            if(flag==0){
                cout<<"-1 "<<a_<<a_2<<endl;
            }
        }else{
            if(a_>n){
                cout<<n<<endl;    
            }else{
                cout<<a_<<endl;
            }
            
        }
        
        // cout<<c<<endl;
        // if(){

        // }
    }
    return 0;
}