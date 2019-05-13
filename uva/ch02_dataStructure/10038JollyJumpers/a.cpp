#include<bits/stdc++.h>

using namespace std;
int n,t,i,j,d;
int a,b,flag;
#define EOF (-1)

int main()
{   
    while(cin >>n){
        d=0;
        flag=0;
        cin>>a;
        for(i = 1;i<n;i++){
            cin>>b;
            if (i>1 && abs(abs(b-a)-d)!=1){
                flag = 1;
            }

            d =abs(b-a);
            a = b;
        }
        if(flag==0){
            cout<<"Jolly"<<endl;    
        }else{
            cout<<"Not jolly"<<endl;
        }
    }
    return 0;
}