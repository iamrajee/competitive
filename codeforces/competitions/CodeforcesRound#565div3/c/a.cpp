#include<bits/stdc++.h>
using namespace std;

int n,i,t,a,sz,c;
vector <int> v;
map <int,int> m;

int main(){
    cin>>n;
    // cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>a;
        // cout<<a<<" ";
        v.push_back(a);
    }
    // cout<<endl;
    sz=(int)v.size();
    c=0;
    m[4] = 0;
    m[8] = 0;
    m[15] = 0;
    m[16] = 0;
    m[23] = 0;
    m[42] = 0;


    if(sz<6){
        cout<<sz<<endl;
    }else{
        for(auto it:v){
            m[it]++;
            if( m[4]> 0 && m[8]> 0 && m[15]> 0 && m[16]> 0 && m[23]> 0 && m[42]> 0){
                m[4] --;
                m[8] --;
                m[15]--;
                m[16]--;
                m[23]--;
                m[42]--;
            }
        }
        cout<<m[4]+m[8]+m[15]+m[16]+m[23]+m[42]<<endl;
        // cout<<c*6+sz%6<<endl;
    }
    return 0;
}