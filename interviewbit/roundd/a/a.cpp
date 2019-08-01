#include<bits/stdc++.h>
using namespace std;

int n,T,q;
int i,j,k,w,y,z,flag,sum;
int a,b,t;
int X,X1,X2;
vector <int> v;

void bin(unsigned n) { 
    if (n > 1)
    bin(n>>1);
    printf("%d", n & 1); 
} 

int ckev(int r){
    // cout<<" ckev:"<<r;
    sum=0;
    while(r>0){
        sum+=(r&1);
        r =  r>>1;
    }
    if(sum%2==0){
        cout<<" "<<k;
        flag = 1;
        return 1;
    }else{
        return 0;
    }

}

void fn(){
    X1=X;
    k=n;
    if(ckev(X1)==1) return;

    for(k=n-1;k>0;k--){
        X1^=v[k];

        X2=X1;
        if(ckev(X2)==1) return;
        for(w=1;w<n-k+1;w++){
            X2^=v[w-1];
            X2^=v[w+k-1];
            if(ckev(X2)==1) return;
        }
    }
}


int main(){
    cin>>T;
    for(i=0;i<T;i++){
        cin>>n>>q;
        X=0;
        v.clear();
        for(j=0;j<n;j++){
            cin>>a;
            X^=a;
            v.push_back(a);
        }
        // cout<<"init-X:"<<X<<",   ";
        // bin(X);
        // cout<<endl;
        cout<<"Case #"<<i+1<<":";
        for(j=0;j<q;j++){
            cin>>a>>b;
            X^=v[a];
            X^=b;
            v[a]=b;
            // cout<<"\nX:"<<X<<",  ";
            // bin(X);
            // cout<<endl;
            flag=0;
            fn();
            if(flag==0){
                cout<<" 0";
            }
        }
        cout<<endl;
    }
    return 0;
}