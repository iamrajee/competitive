#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int i,j,k,flag,sum,counter;
int a,b,t;
char c;
string s;
int mn,mn1,mn2,mn3;
set <int> st;
int main(){
    cin>>q;
    // /*
    while(q--){
        cin>>n>>k;
        cin>>s;
        mn=2000;
        for(i=0;i<n-k+1;i++){
            flag=0;
            mn1=0;
            mn2=0;
            mn3=0;
            for(j=i;j<i+k;j++){
                if(flag==0){
                    if(s[j]=='R'){
                        mn2++;
                        mn3++;
                    }else if(s[j]=='G'){
                        mn1++;
                        mn3++;
                    }else{
                        mn1++;
                        mn2++;
                    }
                    flag++;
                }else if(flag==1){
                    if(s[j]=='R'){
                        mn1++;
                        mn2++;
                    }else if(s[j]=='G'){
                        mn2++;
                        mn3++;
                    }else{
                        mn1++;
                        mn3++;
                        
                    }
                    flag++;
                }else{
                     if(s[j]=='R'){
                        mn1++;
                        mn3++;
                    }else if(s[j]=='G'){
                        mn1++;
                        mn2++;
                    }else{
                        mn2++;
                        mn3++;
                    }
                    flag=0;
                }
                // cout<<i<<","<<j<<" - "<<mn1<<mn2<<mn3<<endl;
            }
            // min(mn1,mn2,mn3);
            mn=min(mn,min(mn1,min(mn2,mn3)));
        }
        cout<<mn<<endl;
    }
    //*/
//    auto result = bitset<32>("1010")^bitset<32>("1010");
//    cout << result << std::endl;
//    '1010'^'1010';
//    cout<<bitset<32>("1010") ^ bitset<32>("1010") << endl;
    return 0;
}