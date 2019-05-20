#include<bits/stdc++.h>

using namespace std;
int n,t,i,j,d;
int a,b,flag;
int diff;
#define EOF (-1)
set <int> s;
set <int>  :: iterator itr;

int main()
{   
    while(cin >>n){
        d=0;
        flag=0;
        cin>>a;
        s.clear();
        for(i = 1;i<n;i++){
            cin>>b;
            s.insert(abs(b-a));
            a=b;
        }
        if(s.size()==0){
            cout<<"Jolly"<<endl;
        }else{
            // for(itr=s.begin();itr!=s.end();itr++){
            //     cout<<*itr<<" ";
            // }
            if(*s.begin()==1 && *(--s.end())==n-1 &&s.size()==n-1){
                cout<<"Jolly"<<endl;
            }else{
                cout<<"Not jolly"<<endl;
            }
        }
    }
    return 0;
}