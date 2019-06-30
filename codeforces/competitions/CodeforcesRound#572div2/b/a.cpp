#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,count;
int a,b,t;
char c;
string s,s2,s3;
int main(){
    cin>>n;
    cin>>s;
    cin>>m;

    for(i=0;i<m;i++){
        cin>>s2;
        size_t found = s2.find(s[j]);
        for(j=0;j<n && (int)s2.size()!=0; j++){
            found = s2.find(s[j]);  
            if(found!=std::string::npos){
                s3=s2.substr(0,found)+s2.substr(found+1,(int)s2.size()-found);
                s2=s3;
                // cout<<"hi  "<<s[j]<<"  -  "<<s2<<endl;
            }
        }
        cout<<j<<endl;
    }
    return 0;
}