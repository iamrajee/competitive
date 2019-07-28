#include<bits/stdc++.h>
using namespace std;

int i,j,T;
int d,t;
long long int N,n;
// map <int,int> m;
vector <int> v(INT32_MAX,-1);
int fact(int x){
    if(v[x]!=-1){//m.find(x)!=m.end()){
        return v[x];
    }else{
        if(x==0){
            return 1;
        }else{
            v[x] = x*fact(x-1);
            return v[x];
        }
    }
}
int bc(int b_, int c_){
    return fact(c_+b_-1)/(fact(b_-1)*fact(c_));
}
int main(){
    cin>>T;
    cout<<T<<endl;
    for(i=0;i<T;i++){
        cin>>N;
        cout<<N<<", ";
        n=N;
        d=2;
        // while(n>0){
        //     t = 10;
        //     while(t<d*9 && n>0){
        //         n-=bc(d,t-1); //1st digit >=1(to avoid repeat counting)
        //         t+=10;
        //     }
        //     d++;
        // }
        cout<<d-1<<", "<<t-10<<endl;

    }
    return 0;
}