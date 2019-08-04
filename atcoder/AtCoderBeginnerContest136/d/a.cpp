#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum;
long long counter;
int a,b,t,q,l,L;
int M = 1000000007;
char c;
string s;
vector <int> v;
stringstream ss;
int main(){
    cin>>s;
    counter=0;
    n = (int)s.size();
    for(i=0;i<n;i++){
        if(s[i]=='?'){
            v.push_back(i);
        }
    }
    q=(int)v.size();
    l=pow(10,q);

    for(i=0;i<l;i++){
        L=i;
        for(j=0;j<q;j++){
            t = L-(L/10)*10;
            L/=10;
            s[v[j]] = (char)(t+48);
            if(stoi(s)%13==5){
                counter++;
            }
            // cout<<i<<" "<<t<<endl;
            // ss<<t;
            // cout<<ss;
            // cout<<to_string(t)<<" "<<(char)(t+48)<<endl;
            // cout<<s[v[j]]<<endl;
            // cout<<i<<" "<<t<<" "<<stoi(s)<<endl;

            
        }
    }
    cout<<counter%M<<endl;
    // cout<<n<<" "<<q<<" "<<l<<endl;
    return 0;
}