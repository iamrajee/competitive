#include<bits/stdc++.h>
using namespace std;

int n;
int i=0;
string s;
char s1;
int r;
int flagover=0;
long long fn(){
    long long int xl,temp;
    xl=0;
    int t;
    while(i<n){
        i++;
        getline(cin,s);
        if(s=="end"){
            if(xl>INT32_MAX){
                i=n;
                flagover=1;
                return -1;
            }
            return xl;
        }else if(s=="add"){
            xl++;
        }else{
            sscanf(s.c_str(),"%s %d",&s1,&t);
            temp=fn();
            if(flagover){
                return -1;
            }
            xl=xl+t*temp;
        }
    }
    if(xl>INT32_MAX || flagover==1){
        i=n;
        flagover=1;
        return -1;
    }
    return xl;
}

int main(){
    cin>>n;
    getline(cin,s);
    r = fn();
    if(flagover){
        cout<<"OVERFLOW!!!"<<endl;
    }else{
        cout<<r<<endl;
    }
    return 0;
}