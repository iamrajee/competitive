#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,t;
vector <int> v;
vector<int>::iterator it;

int sum=0;
int sum1=0;
int sum2=0;
int flag=0;
int main(){
    cin>>n;
    cout<<n<<endl;
    for(i=0;i<2*n;i++){
        cin>>t;
        cout<<t<<" ";
        v.push_back(t);
        sum+=t;
    }
    cout<<"\n========"<<endl;

    if(sum%2 ==1){
        cout<<"-1";
    }else{
        // for(auto it:v){
            // cout<<it;
        // }
        // for(it=v.begin(); it<v.end(); it++){

        // }
        for(int x=0; x< (1<<2*n); x++){
            sum1=0;
            sum2=0;
            // it=v.begin();
            for(j=0; j<2*n; j++){
                if((x&(1<<j)) && j<n){
                    sum1+=v[j];
                }else if(x&(1<<j)){
                    sum2+=v[j];
                }
            }
            if(sum1!=sum2){
                cout<<">>"<<2*n<<endl;
                for(j=0; j<2*n; j++){
                    if(x&(1<<j)){
                        cout<<v[j]<<", "<<sum1;
                    }
                }
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"-1";
        }
    }
    cout<<endl;
    return 0;
}