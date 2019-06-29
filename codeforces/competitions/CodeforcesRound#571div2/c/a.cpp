#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int t;
string a,b,c;

unsigned int countSetBits(unsigned int n){
    unsigned int count = 0; 
    while (n) 
    { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
}

int main(){
    cin>>a;
    cin>>b;
    // cout<<a<<" "<<b<<endl;
    // /*
    int as=(int)a.size();
    int bs=(int)b.size();
    int r=0;

    for(i=0;i<(int)(as-bs+1);i++){
        c = a.substr(i,bs);
        sum=0;
        // for(j=0;j<bs;j++){
        //     if(c[j]!=b[j]){
        //         sum++;
        //     }
        // }
        // if(sum%2==0){
        //     r++;
        // }
        int r_ = bitset<32>(b).to_ulong()^bitset<32>(c).to_ulong();
        if(countSetBits(r_)%2==0){
            r++;
        }
        // cout<<r_<<endl;//stoi(b)^stoi(c);
        // cout<<b<<" "<<c<<" "<<r_<<" "<<countSetBits(r_)<<endl;//stoi(c)<<" "<<r<<endl;
    }
    cout<<r<<endl;
    // */
    return 0;
}