#include<bits/stdc++.h>
using namespace std;

int n,i,t;
int flag1,flag2;
long int zeroes;
vector <int> v;
set <int> s;
map <int,int> m;

int main(){
    cin>>n;
    // cout<<n<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        // cout<<t<<" ";
        s.insert(t);
    }
    // cout<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        // cout<<t<<" ";
        m[t] = i;
        v.push_back(t);
    }
    // cout<<endl;

    zeroes=0;
    flag1 = 0;
    flag2 = 0;
    if(*s.find(1)!=1){
        int prev = v[n-1]+1;
        i = n-1;
        flag1 = 0;
        while(v[i]==prev-1){
            zeroes--;
            if(v[i]==1){
                flag1=1;
                break;
            }
            i--;
        }
        flag2=1;
        if(flag1==1){
            // zeroes=0;
            if(*s.find(v[n-1]+1)==v[n-1]+1){
                for(i=v[n-1]+1+1;i<n+1;i++){
                    if(*s.find(i)!=i){
                        if(m[i]>i-2+zeroes+1){
                            flag2=0;
                            break;
                            // zeroes++;
                        }
                    }
                }
            }else{
                flag2=0;
            }
        }
    }

    if(flag1==1 && flag1==1){
        cout<<n+zeroes<<endl;
    }else{
        zeroes=0;
        if(*s.find(1)!=1){
            zeroes=m[1]+1;
        }
        for(i=1+1;i<n+1;i++){
            if(*s.find(i)!=i){
                if(m[i]>i-2+zeroes){
                    zeroes++;
                }
            }
        }
        cout<<zeroes+n<<endl;
    }
    return 0;
}