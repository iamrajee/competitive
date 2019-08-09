#include<bits/stdc++.h>
using namespace std;

int n,i,j,t,k;
int x=0;
int mi;
vector <int> v;
long int m,sum,result;
int endi;
// bool sortfn(const int & a, const int & b){   
//     return (a > b);
// }
int main(){
    cin>>n>>k;
    // cout<<n<<" "<<k<<endl;
    for(i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
        // cout<<t<<" ";
    }
    
    endi = (int)v.size();
    result = 0;
    while(k>1){
        sum=0;
        m = INT32_MIN;
        // cout<<"INT32_MIN:"<<INT32_MIN<<endl;
        for(i=endi-1;i>k-2;i--){
            // cout<<"i:"<<i<<endl;
            sum+=v[i];
            if(sum>m){
                m = sum;
                mi = i;
            }
        }
        // cout<<"mi:"<<mi<<endl;
        // for(i=mi;i<endi;i++){
        //     result+=k*v[i];
        // }
        result+=k*m;
        endi = mi;
        k--;
    }
    for(i=0;i<endi;i++){
        result+=(k*v[i]);
    }
    cout<<result<<endl;
    return 0;
}