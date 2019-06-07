#include<bits/stdc++.h>
using namespace std;

int n,i,j,w,t,k,a;
// string s;
int x,l,r,sd;
long long int avg;
vector <int> v;
// bool sortfn(const int & a, const int & b){   
//     return (a > b);
// }
int main(){
    cin>>t;
    // cout<<t<<endl;
    for(i=0;i<t;i++){
        v.clear();
        cin>>n>>k;
        // cout<<n<<" "<<k<<endl;
        for(j=0;j<n;j++){
            cin>>a;
            // cout<<a<<" ";
            v.push_back(a);
        }
        // for(j=0;j<n;j++){
        //     v[j]=abs(v[j]-x);
        // }
        // sort(v.begin(), v.end(),sortfn);
        sd=INT32_MAX;
        for(j=0;j<n-k;j++){
            // v[j]=abs(v[j]-x);
            avg=0;
            for(w=j;w<j+k+1;w++){
                // cout<<w<<" ";
                avg+=v[w];
            }
            // cout<<endl;
            avg=round((float)avg/(k+1));
            l = avg-v[j];
            r = v[j+k]-avg;
            if(l > r){
                if(l<sd){
                    sd=l;
                    x=avg;
                }
            }else{
                if(r<sd){
                    sd=r;
                    x=avg;
                }
            }

        }
        cout<<x<<endl;
        
    }
    return 0;
}