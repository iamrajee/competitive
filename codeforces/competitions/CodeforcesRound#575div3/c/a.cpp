#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,sum,sum1,sum2,count;
int a,b,t;
vector <int> v;
vector <int> v1;
vector <int> v2;

int main(){
    cin>>n;
    vector <int> s1(n,0);
    vector <int> s2(n,0);
    for(i=0;i<n;i++){
        cin>>t;
        v1.push_back(t);
    }
    for(i=0;i<n;i++){
        cin>>t;
        v2.push_back(t);
    }
    sum1=0;
    sum2=0;
    flag=n%2;
    for(i=n-1;i>-1;i--){
        if(flag==0){
            sum1+=v2[i];
            sum2+=v1[i];
            s1[i]=sum2;
            s2[i]=sum1;
            flag=1;
        }else{
            sum1+=v1[i];
            sum2+=v2[i];
            s1[i]=sum1;
            s2[i]=sum2;
            flag=0;
        }
        
    }

    for(i=0;i<n-1;i++){
        if(s1[i]<s1[i+1]){

        }

        if(s2[i]<s2[i+1]){

        }
    }
    return 0;
}