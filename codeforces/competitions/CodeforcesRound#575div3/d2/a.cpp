#include<bits/stdc++.h>
using namespace std;

int n,m,q;
int i,j,k,flag,sum,counter;
int a,b,t;
char c;
string s;
int mn,mn1,mn2,mn3,mn1_,mn2_,mn3_;
set <int> st;
int main(){
    cin>>q;
    // /*
    while(q--){
        cin>>n>>k;
        cin>>s;
        mn=200000;
        for(i=0;i<n-k+1;i++){
            // cout<<"i:"<<i<<endl;
            if(i==0){
                // flag=0;
                mn1=0;
                mn2=0;
                mn3=0;
                for(j=i;j<i+k;j++){
                    flag=j%3;
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
                        // flag++;
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
                        // flag++;
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
                        // flag=0;
                    }
                    // cout<<i<<","<<j<<" - "<<mn1<<mn2<<mn3<<endl;
                }
                // min(mn1,mn2,mn3);
                mn=min(mn,min(mn1,min(mn2,mn3)));
                // cout<<"mn:"<<mn<<endl;
            }else{
                
                if(s[i-1]=='R'){
                    mn2--;
                    mn3--;
                }else if(s[i-1]=='G'){
                    mn1--;
                    mn3--;
                }else{
                    mn1--;
                    mn2--;
                }

                //remove first
                // if(flag==0){
                //     if(s[i]=='R'){
                //         mn2--;
                //         mn3--;
                //     }else if(s[i]=='G'){
                //         mn1--;
                //         mn3--;
                //     }else{
                //         mn1--;
                //         mn2--;
                //     }
                // }else if(flag==1){
                //     if(s[i]=='R'){
                //         mn1--;
                //         mn2--;
                //     }else if(s[i]=='G'){
                //         mn2--;
                //         mn3--;
                //     }else{
                //         mn1--;
                //         mn3--;
                //     }
                // }else{
                //      if(s[i]=='R'){
                //         mn1--;
                //         mn3--;
                //     }else if(s[i]=='G'){
                //         mn1--;
                //         mn2--;
                //     }else{
                //         mn2--;
                //         mn3--;
                //     }
                // }
                //=====================
                mn1_=mn1;
                mn2_=mn2;
                mn3_=mn3;

                mn2=mn1_;
                mn3=mn2_;
                mn1=mn3_;

                j=i+k-1;
                flag=(k-1)%3;
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
                    // i=i-1;
                    // flag=i%3;
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
                    // i=i-1;
                    // flag=i%3;
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
                    // i=i-1;
                    // flag=i%3;
                }

                //=============================
                mn=min(mn,min(mn1,min(mn2,mn3)));
                
                // cout<<i<<","<<j<<" - "<<mn1<<mn2<<mn3<<",    fj,fi-1 : ("<<j%3<<","<<i%3<<endl;
                // cout<<"mn:"<<mn<<endl;
                // i++;
            }
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