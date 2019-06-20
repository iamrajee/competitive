#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,t,flag,sum;
char c;
string s1,s2;
int flag2;
multiset <char> us;
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>s1;
        cin>>s2;
        int s1s = (int)s1.size();
        int s2s = (int)s2.size();
        flag = 0;
        // cout<<s1<<endl;
        // cout<<s2<<endl;
        k=0;
        for(j=0;j<s1s;j++){
            if(j==s1s-1 || s1[j]!=s1[j+1]){
                if(k==s2s){
                    flag = 1;
                    break;
                }
                if(s1[j] == s2[k]){
                    k++;
                    while(k<s2s && s2[k]==s1[j]){
                        k++;
                    }
                }else{
                    flag = 1;
                    break;
                }
                
            }else{
                if(s1[j] != s2[k]){
                    flag = 1;
                    break;
                }else{
                    k++;
                }
            }
        }
        
        if(flag==1 || k!=s2s){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
        // c=s2[0];
}