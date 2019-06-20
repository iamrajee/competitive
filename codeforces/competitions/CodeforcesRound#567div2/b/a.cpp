#include<bits/stdc++.h>
using namespace std;

int i,j,l,n;
int flag=0;
int mn1,mn2,ls,rs;
string s;
int l1,l2,l1_,l2_;

int main(){
    cin>>l;
    cin>>s;
    if(l%2==0){
        l1=l%2;
        l2=l1;
        mn1=0;
        mn2=0;
        if(s[l1]!='0'){
            // mn1=stoi(s.substr(0,l1))+stoi(s.substr(l1,l-l1));
            // cout<<mn1<<endl;
        }else{
            l1--;
            l2++;
            while(1){
                if(s[l1]!='0'){
                    mn1=stoi(s.substr(0,l1))+stoi(s.substr(l1,l-l1));
                    if(s[l2]!='0'){
                        mn2=stoi(s.substr(0,l2))+stoi(s.substr(l2,l-l2));
                        if(mn1>mn2){
                            cout<<mn2<<endl;
                        }else{
                            cout<<mn1<<endl;
                        }
                        break;
                    }
                }else if(s[l2]!='0'){
                    mn2=stoi(s.substr(0,l2))+stoi(s.substr(l2,l-l2));
                    cout<<mn2<<endl;
                    break;
                }else{
                    l1--;
                    l2++;
                }

            }
        }
    }else{
        l1=(l1-1)%2;
        l2=l1+1;
        while(1){
            if(s[l1]!='0'){
                mn1=stoi(s.substr(0,l1))+stoi(s.substr(l1,l-l1));
                if(s[l2]!='0'){
                    mn2=stoi(s.substr(0,l2))+stoi(s.substr(l2,l-l2));
                    if(mn1>mn2){
                        cout<<mn2<<endl;
                    }else{
                        cout<<mn1<<endl;
                    }
                    break;
                }
            }else if(s[l2]!='0'){
                mn2=stoi(s.substr(0,l2))+stoi(s.substr(l2,l-l2));
                cout<<mn2<<endl;
                break;
            }else{
                l1--;
                l2++;
            }
        }
    }

    return 0;
}