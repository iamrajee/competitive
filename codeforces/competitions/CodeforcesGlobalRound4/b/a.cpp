#include<bits/stdc++.h>
using namespace std;

int n,m;
int i,j,k,flag,counter;
long long int sum;
int a,b,t;
char c;
string s;
vector <int> v;
int main(){
    cin>>s;
    int sz=s.size();
    sum=0;
    counter=0;
    for(i=1;i<sz;i++){
        if(s[i]=='o'){
            v.push_back(counter);        
        }else if(s[i-1]=='v' && s[i]=='v' ){
            counter++;
        }
    }
    
    for(auto it:v){
        sum+=(it*(counter-it));
    }
    cout<<sum<<endl;
    return 0;
}
