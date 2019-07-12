#include<bits/stdc++.h>
using namespace std;

int n,i,p,c;
long long int result=1;
vector <int> d(200000,-1);
vector <int>::iterator itr;
int fact(int t_){
    if(d[t_] != -1){
        return d[t_];
    }else{
        if(t_ == 0){
            d[t_] = 1;
            return d[t_];
        }else if(t_==1){
            d[t_] = 2;
            return d[t_];
        }else if(t_==2){
            d[t_] = 2;
            return d[t_];
        }else{
            d[t_] = t_*fact(t_-1);
            return d[t_];
        }
    }
}
// int fact(int t_, vector <int> d){
//     if(d[t_] != -1){
//         return d[t_];
//     }else{
//         if(t_ == 0){
//             return 1;
//         }else if(t_==1){
//             return 2;
//         }else{
//             return t_*fact(t_,d);
//         }
//     }
// }
int main(){
    cin>>n;
    // cout<<n<<endl;
    vector <int> v(n+1,0) ;
    for(i=0;i<n-1;i++){
        cin>>p>>c;
        // cout<<p<<" "<<c<<endl;
        v[p]++;
    }
    for(itr=++v.begin();itr!=v.end();itr++){
        result*=fact(*itr);
        // cout<<"=>"<<*itr<<" , "<<result<<endl;
    }
    result*=n;
    cout<<result%998244353<<endl;
    return 0;
}